local tunpack = unpack or table.unpack

local M = {}

function M.astype(typ)
  if terralib.types.istype(typ) then
    return typ
  elseif terralib.isquote(typ) then
    return typ:astype()
  else
    error "tried to convert something to a type that isn't a quote or a type"
  end
end

function M.type_template(typefn)
  typefn = terralib.memoize(typefn)
  local function fn(...)
    local args = {...}
    for i = 1, select("#", ...) do
      args[i] = M.astype(args[i])
    end
    return typefn(tunpack(args))
  end
  return macro(fn, fn)
end

function M.SafeFree(...)
  return quote
    escape
      for _, p in ipairs({...}) do
        if not p:gettype():ispointer() then
          error ("p is not a pointer: " .. p:gettype():layoutstring())
        end
        emit(quote 
          if p ~= nil then
            C.free(p)
          end
        end)
      end
    end
  end
end

return M
