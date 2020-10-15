local shared = require 'feather.shared'
local alloc = require 'std.alloc'
local rtree = require 'feather.rtree'
local backend = require 'feather.backend'
local override = require 'feather.util'.override

local M = {}


local shadow_parent = {}
local shadow_mt = {
  __index = function(self, key)
    return self[shadow_parent][key]
  end
}
local function shadow(base)
  return setmetatable({[shadow_parent] = base}, shadow_mt)
end


local function map_pairs(tab, fn)
  local res = {}
  for k, v in pairs(tab) do
    local k_, v_ = fn(k, v)
    res[k_] = v_
  end
  return res
end



local struct layout {}

local struct layout_stack {
  head: layout
  tail: &layout_stack
                         }

local struct outline_context {
  layouts: layout_stack
                             }


local function make_outline(info)


end

  --Simple translation for now
struct M.transform {
  r: shared.Vec3D
                   }
terra M.transform:compose(other: &M.transform)
  return M.transform{self.r + other.r}
end
terra M.transform:invert()
  return M.transform{-self.r}
end
terra M.transform.methods.identity()
  return M.transform{shared.Vec3D{array(0.0f, 0.0f, 0.0f)}}
end

local template_mt = {}
local outline_mt = {__index = {}}

M.context = {}

--Expression instantiation functions
--TODO: rewrite with implementations that handle the real expressions
local function constant_expression(v) return v end
local function expression_parse(expr) return expr end

M.body = setmetatable({
    generate = function(type_environment)
      return type_environment[M.body](type_environment)
    end
                      }, outline_mt)

local function make_body(body)
  local function generate(context, type_environment)
    local elements = {}
    local types = {}
    for i, b in ipairs(body) do
      elements[i], types[i] = b:generate(context, type_environment)
    end
    print("body values")
    terralib.printraw(types)
    terralib.printraw(elements)
    terralib.printraw(context)

    return {
      enter = function(self, context, environment)
        terralib.printraw(context)
        return `{
          escape
              print("inside escape")
              terralib.printraw(context)
            for i, e in ipairs(elements) do
              print("inside loop")
              terralib.printraw(context)
              local x = `self.["_"..(i-1)]
              print(x, context, environment)
              emit(e.enter(x, "fubar", "environment"))
            end
          end
        }
      end,
      update = function(self, context, environment)
        return quote
          escape
            for i, e in ipairs(elements) do
              emit(e.update(`self.["_"..(i-1)], context, environment))
            end
          end
        end
      end,
      exit = function(self, context)
        return quote
          escape
            for i, e in ipairs(elements) do
              emit(e.exit(`self.["_"..(i-1)], context))
            end
          end
        end
      end,
      render = function(self, context)
        return quote
          escape
            for i, e in ipairs(elements) do
              emit(e.render(`self.["_"..(i-1)], context))
            end
          end
        end
      end,
    }, tuple(unpack(types))
  end
  return generate
end

-- Calling a template produces an outline node.
function template_mt:__call(desc)
  local outline = {args = {}, template = self, has_unbound_body = false}
  for i = 1, #self.params.names do
    local name = self.params.names[i]
    if desc[name] ~= nil and self.params.required[name] then
      error("parameter " .. name .. " is required but not specified in outline definition")
    end
    outline.args[name] = desc[name] ~= nil and expression_parse(desc[name]) or self.params.defaults[name]
  end
  if self.params.body then
    local body = {n = #desc}
    for i = 1, #desc do
      body[i] = desc[i]
    end
    outline.body = make_body(body)
  end
  function outline:generate(context, type_environment)
    local binds = {}
    if self.body then
      local body_fns, body_type = self.body(contex, type_environment)
      binds[M.body] = function()
        return {
          enter = function(self, context, environment)
            return body_fns.enter(self, context, environment[M.body])
          end,
          update = function(self, context, environment)
            return body_fns.update(self, context, environment[M.body])
          end,
          exit = function(self, context)
            return body_fns.exit(self, context)
          end,
          render = function(self, context)
            return body_fns.render(self, context)
          end
        }, body_type
      end
    else
      binds[M.body] = function()
        return {
          enter = function() return {} end,
          update = function() return {} end,
          exit = function() return {} end,
          render = function() return {} end
        }, terralib.types.unit
      end
    end
    for k, v in pairs(self.args) do
      binds[k] = type_expression(v, type_environment)
    end
    local fns, type = self.template.generate(context, binds)
    return {
      enter = function(data, context, environment)
        local binds = {
          [M.body] = environment,
        }
        for k, v in pairs(self.args) do
          binds[k] = expression_enter(v, context, environment)
        end
        return fns.enter(data, binds)
      end,
      update = function(data, context, environment)
        local binds = {
          [M.body] = environment,
        }
        for k, v in pairs(self.args) do
          binds[k] = expression_update(v, context, environment)
        end
        return fns.update(data, context, binds)
      end,
      exit = function(data, context)
        return fns.exit(data, context)
      end,
      render = function(data, context)
        return fns.render(data, context)
      end
    }, type
  end
  return setmetatable(outline, outline_mt)
end

-- parse an argument declaration table into a usable specification
local function parse_params(desc)
  local res = {required = {}, defaults = {}, names = {}, body = false}
  for k, v in pairs(desc) do
    if type(k) ~= "string" then
      if k == 1 and v == M.body then
        res.body = true
      else
        error("invalid argument specifier provided to declaration", 2)
      end
    else
      table.insert(res.names, k)
      if v == M.required then
        res.required[k] = true
      else
        res.defaults[k] = constant_expression(v)
      end
    end
  end
  return res
end

function M.raw_template(params)
  local params = parse_params(params)
  return function(generate)
    local self = {
      params = params,
      generate = generate
    }
    return setmetatable(self, template_mt)
  end
end

function M.basic_template(params)
  local params_abbrev = parse_params(params)
  local params_full = parse_params(params)

  table.insert(params_full.names, "pos")
  table.insert(params_full.names, "ext")
  table.insert(params_full.names, "rot")
  local zerovec = `[shared.Vec3D]{array(0.0f, 0.0f, 0.0f)}
  params_full.defaults.pos = zerovec
  params_full.defaults.ext = zerovec
  params_full.defaults.rot = zerovec

  return function(render)
    local function generate(self, context, type_environment)
      --TODO: write this
      local typ = terralib.types.newstruct("template_store")
      for i, name in ipairs(params.names) do
        typ.entries[i] = {field = name, type = type_environment[name]}
      end
      typ.entries:insert{field = "_node", type = context.rtree_node}

      local function unpack_store(store)
        local res = {}
        for i, name in ipairs(params_abbrev.names) do
          res[name] = `store.[name]
        end
        return res
      end

      local body_fns, body_type
      if params_abbrev.body then
        body_fns, body_type = type_environment[M.body](context, type_environment)
      end


      return {
        enter = function(self, context, environment)
          return quote
            escape
              for i, name in ipairs(params_abbrev.names) do
                emit quote self._0.[name] = [environment[name] ] end
              end
            end
            var pos = [environment.pos]
            var ext = [environment.ext]
            var rot = [environment.rot]
            var z_index = [shared.Veci]{0, 0}
            self._0._node = [context.rtree]:create([context.rtree_node], &pos, &ext, &rot, z_index)
            var transform = [context.transform]:compose(M.transform{self._0._node.pos})
            escape
              if params_abbrev.body then
                emit(body_fns.enter(
                       `self._1,
                       override(context, {rtree_node = `self._0._node, transform = `transform}),
                       override(environment, unpack_store(`self._0))
                ))
              end
            end
                 end
        end,
        update = function(self, context, environment)
          return quote
            escape
              for i, name in ipairs(params_abbrev.names) do
                emit quote self._0.[name] = [environment[name] ] end
              end
            end
            self._0._node.pos = [environment.pos]
            self._0._node.extent = [environment.ext]
            self._0._node.rot = [environment.rot]
            var transform = [context.transform]:compose(M.transform{self._0._node.pos})
            escape
              if params_abbrev.body then
                emit(body_fns.update(
                       `self._1,
                       override(context, {rtree_node = `self._0._node, transform = `transform}),
                       override(environment, unpack_store(`self._0))
                ))
              end
            end
                 end
        end,
        exit = function(self, context)
          return quote
            escape
              if params_abbrev.body then
                emit(body_fns.exit(`self._1, override(context, {rtree_node = `self._0._node})))
              end
            end
            [context.rtree]:destroy(self._0._node)
                 end
        end,
        render = function(self, context)
          return quote
            var tranform = [context.transform]:compose(M.transform{self._0._node.pos})
            [render(override(context, {transform = `transform}), unpack_store(`self._0))]
                 end
        end
      }
    end

    local self = {
      params = params_full,
      generate = generate
    }
    return setmetatable(self, template_mt)
  end
end

function M.template(params)
  local params = parse_params(params)
  return function(defn)
    print(desc, defn)
    local defn_body = make_body(defn)

    local function generate(self, context, type_environment)
      local defn_body_fns, defn_body_type = defn_body(context, type_environment)

      local typ = terralib.types.newstruct("template_store")
      for i, name in ipairs(params.names) do
        typ.entries[i] = {field = name, type = type_environment[name]}
      end

      local function unpack_store(store)
        local res = {}
        for i, name in ipairs(params.names) do
          res[name] = `store.[name]
        end
      end

      return {
        enter = function(self, context, environment)
          local initializers = {}
          for i, name in ipairs(params.names) do
            initializers[i] = quote self._0.[name] = [environment[name] ] end
          end
          return quote
            [initializers]
            [defn_body_fns.enter(self._1, context, override(environment, unpack_store(self._0)))]
                 end
        end,
        update = function(self, context, environment)
          local updates = {}
          for i, name in ipairs(params.names) do
            updates[i] = quote self._0.[name] = [environment[name] ] end
          end
          return {updates, defn_body_fns.update(`self._1, context, override(environment, unpack_store(self._0)))}
        end,
        exit = function(self, context)
          return defn_body_fns.exit(`self._1, context)
        end,
        render = function(self, context)
          return defn_body_fns.render(`self._1, context)
        end
      }
    end

    local self = {
      params = params,
      generate = generate
    }
    return setmetatable(self, template_mt)
  end
end

function M.let(bindings)
  local exprs = {}
  for k, v in pairs(bindings) do
    exprs[k] = expression_parse(v)
  end
  return function(body)
    local body = make_body(body)
    local function generate(self, context, type_environment)
      local texprs = {}
      for k, v in pairs(exprs) do
        texprs[k] = type_expression(v, context, type_environment)
      end
      local variables = {}
      for k, v in pairs(texprs) do
        table.insert(variables, {field = k, type = v})
      end
      local store = terralib.types.newstruct("let_store")
      store.entries = variables

      local function body_env(environment, s)
        return override(environment, map_pairs(exprs, function(k, v) return k, `s.[k] end))
      end

      local body_fn, body_type = body(context, override(type_environment, texprs))


      return {
        enter = function(self, context, environment)
          return quote
            escape
              for k, v in pairs(exprs) do
                emit quote self._0.[k] = [expression_enter(v, context, environment)] end
              end
            end
            [body_fn.enter(`self._1, context, body_env(environment, `self._0))]
                 end
        end,
        update = function(self, context, environment)
          return quote
            escape
              for k, v in pairs(exprs) do
                emit quote self._0.[k] = [expression_update(v, context, environment)] end
              end
            end
            [body_fn.update(`self._1, context, body_env(environment, `self._0))]
                 end
        end,
        exit = function(self, context)
          return quote
            [body_fn.exit(`self._1, context)]
                 end
        end,
        render = function(self, context)
          return body_fn.render(`self._1, context)
        end
      }, tuple(store, body_type)
    end

    return setmetatable({generate = generate}, outline_mt)
  end
end


function M.ui(desc)
  local body = make_body(desc)

  local type_environment = {}
  local query_names = {}

  local allocator_type = alloc.default_allocator:gettype()
  local rtree_type = rtree(allocator_type)
  local application_type = desc.application
  local backend_type = &backend.Backend

  for k, v in pairs(desc.queries) do
    table.insert(query_names, k)
  end

  table.sort(query_names)

  local query_name_lookup = {}
  local query_binding = terralib.types.newstruct("query_struct")
  local query_store = (&opaque)[#query_names]
  local query_store_initializers = {}
  for i, v in ipairs(query_names) do
    queries_binding_type.entries:insert {field = v, type = desc.queries[v]}
    query_name_lookup[v] = i
  end

  local type_context = {
    rtree = rtree_type,
    rtree_node = &rtree_type.Node,
    allocator = allocator_type,
    backend = backend_type
  }

  local body_fns, body_type = body(type_context, type_environment)

  local struct ui {
    data: body_type
    rtree: rtree_type
    allocator: allocator_type
    application: application_type
    queries: query_binding
    backend: backend_type
                  }

  -- terralib.printraw(ui)

  terra ui:init(application: application_type, queries: query_binding, backend: backend_type)
    self.rtree:init()
    var zero = [shared.Vec3D] {array(0.0f, 0.0f, 0.0f)}
    var zindex = [shared.Veci] {array(0, 0)}
    self.rtree:create(nil, &zero, &zero, &zero, &zindex)
    self.allocator = alloc.default_allocator
    self.application = application
    --[[escape
      for i, v in ipairs(query_names) do
        emit quote self.queries[ [i] ] = queries.[v] end
      end
      end]]
    self.queries = queries
    self.backend = backend
  end

  local function make_context(self)
    return {
      rtree = `self.rtree,
      rtree_node = `self.rtree.root,
      allocator = `self.rtree.allocator,
      backend = `self.backend
    }
  end

  local function make_environment(self)
    local res = {

    }
    for i, v in ipairs(query_names) do
      res[v] = macro(function(...) local args = {...}; return `self.queries.[v](self.application, [args]) end)
    end
    return res
  end

  do
    --DEBUG
    local self = symbol(ui)
    local blk = body_fns.enter(`self.data,
                               make_context(self),
                               make_environment(self)
    )
    print(blk)
  end

  terra ui:enter()
    [body_fns.enter(`self.data,
                    make_context(self),
                    make_environment(self)
    )]
  end
  terra ui:update()
    [body_fns.update(
       `self.data,
       make_context(self),
       make_environment(self)
    )]
  end
  terra ui:exit()
    [body_fns.exit(`self.data, make_context(self))]
  end
  terra ui:render()
    [body_fns.render(`self.data, make_context(self))]
  end

  return ui
end

return M