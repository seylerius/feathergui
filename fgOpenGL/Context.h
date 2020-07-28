// Copyright (c)2020 Fundament Software
// For conditions of distribution and use, see copyright notice in "fgOpenGL.h"

#ifndef GL__CONTEXT_H
#define GL__CONTEXT_H

#include "glad/gl.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "compiler.h"
#include "khash.h"
#include "Layer.h"
#include "Shader.h"
#include "Asset.h"
#include <vector>

namespace GL {
  class Backend;
  struct Asset;
  struct Font;
  struct Glyph;

  KHASH_DECLARE(tex, const Asset*, GLuint);
  KHASH_DECLARE(font, const Font*, uint64_t);
  KHASH_DECLARE(glyph, uint32_t, char);

  // A context may or may not have an associated OS window, for use inside other 3D engines.
  struct Context
  {
    Context(Backend* backend, FG_Element* element, FG_Vec* dim);
    virtual ~Context();
    void BeginDraw(const FG_Rect* area, bool clear);
    void EndDraw();
    void Draw(const FG_Rect* area);
    void PushClip(const FG_Rect& rect);
    void PopClip();
    void PushLayer(const FG_Rect& area, float* transform, float opacity, Layer* cache);
    Layer* PopLayer();
    void CreateResources();
    void DestroyResources();
    GLFWwindow* GetWindow() const { return _window; }
    void Scissor(const FG_Rect& rect, float x, float y) const;
    void Viewport(const FG_Rect& rect, float x, float y) const;
    void AppendBatch(const void* vertices, GLsizeiptr bytes, GLsizei count);
    GLsizei FlushBatch();
    void SetDim(const FG_Vec& dim);
    GLuint LoadAsset(Asset* asset);
    bool CheckGlyph(uint32_t g);
    GLuint GetFont(const Font* font, uint32_t powsize);

    FG_Element* _element;
    GLuint _imageshader;
    GLuint _rectshader;
    GLuint _circleshader;
    GLuint _trishader;
    GLuint _lineshader;
    GLuint _quadobject;
    GLuint _quadbuffer;
    GLuint _imageobject;
    GLuint _imagebuffer;
    float proj[4][4];

    static const size_t BATCH_BYTES = (1 << 12);

  protected:
    template<class T, int I>
    void CreateVAO(Shader& shader, GLuint instance, GLuint* object, GLuint* buffer, const T(&init)[I])
    {
      _createVAO(shader, instance, object, buffer, init, sizeof(T), I);
    }
    void _createVAO(Shader& shader, GLuint instance, GLuint* object, GLuint* buffer, const void* init, size_t size, size_t count);

    GLFWwindow* _window;
    Backend* _backend;
    std::vector<FG_Rect> _clipstack;
    std::vector<Layer*> _layers;
    GLintptr _bufferoffset;
    GLsizei _buffercount;
    bool _initialized;
    kh_tex_s* _texhash;
    kh_font_s* _fonthash; // Holds the initialized texture for this font on this context
    kh_glyph_s* _glyphhash; // The set of all glyphs that have been initialized
  };
}

#endif
