//THIS FILE AUTOGENERATED
#ifndef BACKEND_H
#define BACKEND_H

#include <stdint.h> // for integers
#include <stdbool.h> // for bool

enum FG_Format {
  FG_Format_JPG = 5,
  FG_Format_WEAK_LAYER = 3,
  FG_Format_SVG = 14,
  FG_Format_BMP = 4,
  FG_Format_ICO = 7,
  FG_Format_WEBP = 11,
  FG_Format_LAYER = 2,
  FG_Format_GIF = 8,
  FG_Format_MKV = 17,
  FG_Format_AVI = 15,
  FG_Format_MP4 = 16,
  FG_Format_WIC = 13,
  FG_Format_UNKNOWN = 255,
  FG_Format_DDS = 12,
  FG_Format_GRADIENT = 0,
  FG_Format_PNG = 6,
  FG_Format_TIFF = 9,
  FG_Format_BUFFER = 1,
  FG_Format_TGA = 10,
  FG_Format_WEBM = 18
};
typedef struct FG_Vec__ FG_Vec;
typedef float FG_anon_1[2];
struct FG_Vec__ {
  float x;
    float y;
    
};
enum FG_BlendValue {
  FG_BlendValue_DST_COLOR = 4,
  FG_BlendValue_SRC_ALPHA_SATURATE = 14,
  FG_BlendValue_INV_SRC_COLOR = 3,
  FG_BlendValue_INV_CONSTANT_ALPHA = 13,
  FG_BlendValue_INV_SRC_ALPHA = 7,
  FG_BlendValue_CONSTANT_ALPHA = 12,
  FG_BlendValue_ZERO = 0,
  FG_BlendValue_INV_CONSTANT_COLOR = 11,
  FG_BlendValue_CONSTANT_COLOR = 10,
  FG_BlendValue_ONE = 1,
  FG_BlendValue_SRC_ALPHA = 6,
  FG_BlendValue_SRC_COLOR = 2,
  FG_BlendValue_INV_DST_ALPHA = 9,
  FG_BlendValue_DST_ALPHA = 8,
  FG_BlendValue_INV_DST_COLOR = 5
};
enum FG_Level {
  FG_Level_NONE = -1,
  FG_Level_FATAL = 0,
  FG_Level_DEBUG = 4,
  FG_Level_WARNING = 2,
  FG_Level_ERROR = 1,
  FG_Level_NOTICE = 3
};
typedef void (* FG_Log)(void *, FG_Level, const char*, ...);
typedef struct FG_Rect__ FG_Rect;
typedef float FG_anon_2[4];
struct FG_Rect__ {
  union {
    struct
    {
      float left;
      float top;
      float right;
      float bottom;
    };

    struct
    {
      FG_Vec topleft;
      FG_Vec bottomright;
    };

    float ltrb[4];
  };
};
enum FG_Feature {
  FG_Feature_CIRCLE_ALPHA = 2048,
  FG_Feature_RECT_BLUR = 64,
  FG_Feature_CIRCLE_ARCS = 256,
  FG_Feature_LINES_ALPHA = 65536,
  FG_Feature_RECT_CORNERS = 16,
  FG_Feature_CIRCLE_BORDER = 512,
  FG_Feature_LAYER_TRANSFORM = 524288,
  FG_Feature_TEXT_ANTIALIAS = 1,
  FG_Feature_TEXT_BLUR = 4,
  FG_Feature_TRIANGLE_BLUR = 16384,
  FG_Feature_TRIANGLE_ALPHA = 32768,
  FG_Feature_RECT_BORDER = 32,
  FG_Feature_CURVE_STROKE = 131072,
  FG_Feature_SHADER_GLSL_ES2 = 2097152,
  FG_Feature_RECT_ALPHA = 128,
  FG_Feature_TEXT_ALPHA = 8,
  FG_Feature_IMMEDIATE_MODE = 33554432,
  FG_Feature_TRIANGLE_BORDER = 8192,
  FG_Feature_BACKGROUND_OPACITY = 16777216,
  FG_Feature_CIRCLE_BLUR = 1024,
  FG_Feature_SHADER_HLSL2 = 8388608,
  FG_Feature_TRIANGLE_CORNERS = 4096,
  FG_Feature_SHADER_GLSL4 = 4194304,
  FG_Feature_LAYER_OPACITY = 1048576,
  FG_Feature_CURVE_FILL = 262144,
  FG_Feature_TEXT_SUBPIXEL = 2
};
enum FG_AntiAliasing {
  FG_AntiAliasing_NO_AA = 0,
  FG_AntiAliasing_LCD_V = 3,
  FG_AntiAliasing_AA = 1,
  FG_AntiAliasing_LCD = 2
};
enum FG_Joy {
  FG_Joy_Button4 = 3,
  FG_Joy_Button21 = 20,
  FG_Joy_Button11 = 10,
  FG_Joy_Button12 = 11,
  FG_Joy_Button25 = 24,
  FG_Joy_Button3 = 2,
  FG_Joy_Button15 = 14,
  FG_Joy_ID2 = 256,
  FG_Joy_Button31 = 30,
  FG_Joy_Button32 = 31,
  FG_Joy_Button2 = 1,
  FG_Joy_Button28 = 27,
  FG_Joy_Button18 = 17,
  FG_Joy_ID7 = 1536,
  FG_Joy_ID15 = 3584,
  FG_Joy_ID14 = 3328,
  FG_Joy_Button22 = 21,
  FG_Joy_Button9 = 8,
  FG_Joy_ID12 = 2816,
  FG_Joy_ID3 = 512,
  FG_Joy_ID11 = 2560,
  FG_Joy_ID10 = 2304,
  FG_Joy_ID9 = 2048,
  FG_Joy_ID1 = 0,
  FG_Joy_ID8 = 1792,
  FG_Joy_Button20 = 19,
  FG_Joy_ID16 = 3840,
  FG_Joy_Button8 = 7,
  FG_Joy_ID6 = 1280,
  FG_Joy_Button26 = 25,
  FG_Joy_ID5 = 1024,
  FG_Joy_Button23 = 22,
  FG_Joy_Button1 = 0,
  FG_Joy_Button24 = 23,
  FG_Joy_ID4 = 768,
  FG_Joy_Button29 = 28,
  FG_Joy_Button16 = 15,
  FG_Joy_Button7 = 6,
  FG_Joy_Button10 = 9,
  FG_Joy_Button27 = 26,
  FG_Joy_Button30 = 29,
  FG_Joy_Button5 = 4,
  FG_Joy_Button17 = 16,
  FG_Joy_Button19 = 18,
  FG_Joy_ID13 = 3072,
  FG_Joy_Button14 = 13,
  FG_Joy_Button13 = 12,
  FG_Joy_Button6 = 5
};
enum FG_Primitive {
  FG_Primitive_LINE_STRIP = 3,
  FG_Primitive_LINE = 1,
  FG_Primitive_TRIANGLE = 2,
  FG_Primitive_INDEX_INT = 7,
  FG_Primitive_POINT = 0,
  FG_Primitive_INDEX_SHORT = 6,
  FG_Primitive_INDEX_BYTE = 5,
  FG_Primitive_TRIANGLE_STRIP = 4
};
typedef void (* FG_Delegate)(void *);
typedef struct FG_MsgReceiver__ FG_MsgReceiver;
struct FG_MsgReceiver__ {
  void * * vftable;
};
typedef struct FG_Color__ FG_Color;
struct FG_Color__ {
  union {
    unsigned int v;
    unsigned char colors[4];
    struct
    {
      unsigned char b;
      unsigned char g;
      unsigned char r;
      unsigned char a;
    };
  };
};
typedef struct FG_Shader__ FG_Shader;
typedef struct FG_ShaderParameter__ FG_ShaderParameter;
enum FG_ShaderType {
  FG_ShaderType_COLOR32 = 5,
  FG_ShaderType_FLOAT = 1,
  FG_ShaderType_TEXTURE = 6,
  FG_ShaderType_INT = 3,
  FG_ShaderType_DOUBLE = 2,
  FG_ShaderType_TEXCUBE = 7,
  FG_ShaderType_UINT = 4,
  FG_ShaderType_HALF = 0
};
struct FG_ShaderParameter__ {
  FG_ShaderType type;
  uint32_t length;
  uint32_t multi;
  const char* name;
};
struct FG_Shader__ {
  void * data;
  FG_ShaderParameter * parameters;
  uint32_t n_parameters;
};
typedef struct FG_Color16__ FG_Color16;
struct FG_Color16__ {
  uint64_t v;
};
enum FG_Cursor {
  FG_Cursor_NONE = 0,
  FG_Cursor_RESIZEWE = 7,
  FG_Cursor_RESIZEALL = 10,
  FG_Cursor_RESIZENS = 6,
  FG_Cursor_CUSTOM = 14,
  FG_Cursor_IBEAM = 2,
  FG_Cursor_ARROW = 1,
  FG_Cursor_DRAG = 13,
  FG_Cursor_RESIZENESW = 9,
  FG_Cursor_NO = 11,
  FG_Cursor_RESIZENWSE = 8,
  FG_Cursor_HELP = 12,
  FG_Cursor_WAIT = 4,
  FG_Cursor_HAND = 5,
  FG_Cursor_CROSS = 3
};
typedef struct FG_Data__ FG_Data;
struct FG_Data__ {
  union {
  void * data;
  uint32_t index;
};;
};
typedef struct FG_Result__ FG_Result;
struct FG_Result__ {
  union {
  int32_t draw;
  int32_t mouseScroll;
  int32_t mouseOn;
  int32_t joyButtonUp;
  int32_t mouseOff;
  int32_t keyUp;
  uint32_t getWindowFlags;
  int32_t keyDown;
  int32_t action;
  int32_t keyChar;
  int32_t touchEnd;
  int32_t touchMove;
  int32_t touchBegin;
  int32_t mouseUp;
  int32_t mouseDblClick;
  int32_t setWindowFlags;
  uint64_t construct;
  int32_t mouseDown;
  int32_t destroy;
  int32_t lostFocus;
  int32_t joyButtonDown;
  int32_t joyOrientation;
  int32_t joyAxis;
  int32_t drop;
  int32_t setWindowRect;
  int32_t mouseMove;
  int32_t gotFocus;
};;
};
typedef struct FG_Msg__ FG_Msg;
enum FG_Kind {
  FG_Kind_MOUSEOFF = 18,
  FG_Kind_TOUCHEND = 25,
  FG_Kind_KEYCHAR = 11,
  FG_Kind_KEYDOWN = 12,
  FG_Kind_MOUSEDBLCLICK = 15,
  FG_Kind_ACTION = 0,
  FG_Kind_GOTFOCUS = 6,
  FG_Kind_JOYBUTTONDOWN = 8,
  FG_Kind_MOUSEMOVE = 17,
  FG_Kind_DROP = 4,
  FG_Kind_SETWINDOWFLAGS = 22,
  FG_Kind_MOUSEON = 19,
  FG_Kind_DRAW = 3,
  FG_Kind_SETWINDOWRECT = 23,
  FG_Kind_LOSTFOCUS = 14,
  FG_Kind_JOYORIENTATION = 10,
  FG_Kind_JOYBUTTONUP = 9,
  FG_Kind_MOUSEDOWN = 16,
  FG_Kind_MOUSESCROLL = 20,
  FG_Kind_JOYAXIS = 7,
  FG_Kind_TOUCHBEGIN = 24,
  FG_Kind_DESTROY = 2,
  FG_Kind_TOUCHMOVE = 26,
  FG_Kind_MOUSEUP = 21,
  FG_Kind_CONSTRUCT = 1,
  FG_Kind_GETWINDOWFLAGS = 5,
  FG_Kind_KEYUP = 13
};
typedef struct FG_anon_3__ FG_anon_3;
struct FG_anon_3__ {
  void * data;
  FG_Rect area;
};
typedef struct FG_anon_4__ FG_anon_4;
struct FG_anon_4__ {
  float x;
  float y;
  float delta;
  float hdelta;
};
typedef struct FG_anon_5__ FG_anon_5;
struct FG_anon_5__ {
  float x;
  float y;
  uint8_t all;
  uint8_t modkeys;
};
typedef struct FG_anon_6__ FG_anon_6;
struct FG_anon_6__ {
  uint16_t index;
  uint16_t button;
  uint8_t modkeys;
};
typedef struct FG_anon_7__ FG_anon_7;
struct FG_anon_7__ {
  float x;
  float y;
  uint8_t all;
  uint8_t modkeys;
};
typedef struct FG_anon_8__ FG_anon_8;
struct FG_anon_8__ {
  uint8_t key;
  uint8_t modkeys;
  uint16_t scancode;
};
typedef struct FG_anon_9__ FG_anon_9;
struct FG_anon_9__ {
  ;
};
typedef struct FG_anon_10__ FG_anon_10;
struct FG_anon_10__ {
  uint8_t key;
  uint8_t modkeys;
  uint16_t scancode;
};
typedef struct FG_anon_11__ FG_anon_11;
struct FG_anon_11__ {
  ;
};
typedef struct FG_anon_12__ FG_anon_12;
struct FG_anon_12__ {
  int32_t unicode;
  uint8_t modkeys;
};
typedef struct FG_anon_13__ FG_anon_13;
struct FG_anon_13__ {
  float x;
  float y;
  float z;
  float r;
  float pressure;
  uint16_t index;
  uint8_t flags;
  uint8_t modkeys;
};
typedef struct FG_anon_14__ FG_anon_14;
struct FG_anon_14__ {
  float x;
  float y;
  float z;
  float r;
  float pressure;
  uint16_t index;
  uint8_t flags;
  uint8_t modkeys;
};
typedef struct FG_anon_15__ FG_anon_15;
struct FG_anon_15__ {
  float x;
  float y;
  float z;
  float r;
  float pressure;
  uint16_t index;
  uint8_t flags;
  uint8_t modkeys;
};
typedef struct FG_anon_16__ FG_anon_16;
struct FG_anon_16__ {
  float x;
  float y;
  uint8_t all;
  uint8_t modkeys;
  uint8_t button;
};
typedef struct FG_anon_17__ FG_anon_17;
struct FG_anon_17__ {
  float x;
  float y;
  uint8_t all;
  uint8_t modkeys;
  uint8_t button;
};
typedef struct FG_anon_18__ FG_anon_18;
struct FG_anon_18__ {
  uint32_t flags;
};
typedef struct FG_anon_19__ FG_anon_19;
struct FG_anon_19__ {
  void * target;
};
typedef struct FG_anon_20__ FG_anon_20;
struct FG_anon_20__ {
  float x;
  float y;
  uint8_t all;
  uint8_t modkeys;
  uint8_t button;
};
typedef struct FG_anon_21__ FG_anon_21;
struct FG_anon_21__ {
  ;
};
typedef struct FG_anon_22__ FG_anon_22;
struct FG_anon_22__ {
  ;
};
typedef struct FG_anon_23__ FG_anon_23;
struct FG_anon_23__ {
  uint16_t index;
  uint16_t button;
  uint8_t modkeys;
};
typedef struct FG_anon_24__ FG_anon_24;
typedef struct FG_Vec3D__ FG_Vec3D;
typedef float FG_anon_25[3];
struct FG_Vec3D__ {
  float x;
    float y;
    float z;
    
};
struct FG_anon_24__ {
  uint16_t index;
  FG_Vec3D velocity;
  FG_Vec3D rotation;
};
typedef struct FG_anon_26__ FG_anon_26;
struct FG_anon_26__ {
  uint16_t index;
  float value;
  uint16_t axis;
  uint8_t modkeys;
};
typedef struct FG_anon_27__ FG_anon_27;
struct FG_anon_27__ {
  int32_t kind;
  void * target;
  uint32_t count;
};
typedef struct FG_anon_28__ FG_anon_28;
struct FG_anon_28__ {
  FG_Rect rect;
};
typedef struct FG_anon_29__ FG_anon_29;
struct FG_anon_29__ {
  float x;
  float y;
  uint8_t all;
  uint8_t modkeys;
};
typedef struct FG_anon_30__ FG_anon_30;
struct FG_anon_30__ {
  ;
};
struct FG_Msg__ {
  uint16_t kind;
  uint16_t subkind;
  union {
  FG_anon_3 draw;
  FG_anon_4 mouseScroll;
  FG_anon_5 mouseOn;
  FG_anon_6 joyButtonUp;
  FG_anon_7 mouseOff;
  FG_anon_8 keyUp;
  FG_anon_9 getWindowFlags;
  FG_anon_10 keyDown;
  FG_anon_11 action;
  FG_anon_12 keyChar;
  FG_anon_13 touchEnd;
  FG_anon_14 touchMove;
  FG_anon_15 touchBegin;
  FG_anon_16 mouseUp;
  FG_anon_17 mouseDblClick;
  FG_anon_18 setWindowFlags;
  FG_anon_19 construct;
  FG_anon_20 mouseDown;
  FG_anon_21 destroy;
  FG_anon_22 lostFocus;
  FG_anon_23 joyButtonDown;
  FG_anon_24 joyOrientation;
  FG_anon_26 joyAxis;
  FG_anon_27 drop;
  FG_anon_28 setWindowRect;
  FG_anon_29 mouseMove;
  FG_anon_30 gotFocus;
};;
};
typedef FG_Result (* FG_Behavior)(FG_MsgReceiver *, void *, void *, FG_Msg *);
enum FG_Window {
  FG_Window_NOBORDER = 16,
  FG_Window_NOCAPTION = 8,
  FG_Window_FULLSCREEN = 256,
  FG_Window_MINIMIZED = 32,
  FG_Window_CLOSED = 128,
  FG_Window_MAXIMIZABLE = 2,
  FG_Window_MINIMIZABLE = 1,
  FG_Window_RESIZABLE = 4,
  FG_Window_MAXIMIZED = 64
};
enum FG_ModKey {
  FG_ModKey_CONTROL = 2,
  FG_ModKey_SHIFT = 1,
  FG_ModKey_NUMLOCK = 32,
  FG_ModKey_HELD = 64,
  FG_ModKey_ALT = 4,
  FG_ModKey_CAPSLOCK = 16,
  FG_ModKey_SUPER = 8
};
enum FG_MouseButton {
  FG_MouseButton_X2 = 16,
  FG_MouseButton_M = 4,
  FG_MouseButton_X4 = 64,
  FG_MouseButton_X3 = 32,
  FG_MouseButton_R = 2,
  FG_MouseButton_X5 = 128,
  FG_MouseButton_L = 1,
  FG_MouseButton_X1 = 8
};
typedef struct FG_Backend__ FG_Backend;
typedef void (* FG_anon_31)(FG_Backend *);
typedef struct FG_Font__ FG_Font;
struct FG_Font__ {
  FG_Data data;
  FG_Vec dpi;
  float baseline;
  float lineheight;
  uint32_t pt;
  FG_AntiAliasing aa;
};
typedef struct FG_BlendState__ FG_BlendState;
enum FG_BlendOp {
  FG_BlendOp_ADD = 0,
  FG_BlendOp_REV_SUBTRACT = 2,
  FG_BlendOp_SUBTRACT = 1
};
struct FG_BlendState__ {
  uint8_t srcBlend;
  uint8_t destBlend;
  uint8_t colorBlend;
  uint8_t srcBlendAlpha;
  uint8_t destBlendAlpha;
  uint8_t alphaBlend;
  uint8_t mask;
  FG_Color constant;
};
typedef int32_t (* FG_anon_32)(FG_Backend *, void *, FG_Font *, void *, FG_Rect *, FG_Color, float, float, float, FG_BlendState *);
typedef struct FG_Asset__ FG_Asset;
typedef struct FG_Veci__ FG_Veci;
typedef int32_t FG_anon_34[2];
struct FG_Veci__ {
  int x;
    int y;
    
};
struct FG_Asset__ {
  FG_Data data;
  FG_Format format;
  union {
    struct {
      FG_Veci size;
      FG_Vec dpi;
    };
    struct {
      unsigned int count;
      unsigned short stride;
      unsigned char primitive;
      FG_ShaderParameter * parameters;
      unsigned int n_parameters;
    };
  };
};
typedef FG_Asset * (* FG_anon_33)(FG_Backend *, const char*, uint32_t, FG_Format);
enum FG_Clipboard {
  FG_Clipboard_NONE = 0,
  FG_Clipboard_ALL = 7,
  FG_Clipboard_CUSTOM = 6,
  FG_Clipboard_WAVE = 2,
  FG_Clipboard_BITMAP = 3,
  FG_Clipboard_ELEMENT = 5,
  FG_Clipboard_FILE = 4,
  FG_Clipboard_TEXT = 1
};
typedef int32_t (* FG_anon_35)(FG_Backend *, void *, FG_Clipboard);
typedef struct FG_Display__ FG_Display;
struct FG_Display__ {
  FG_Veci size;
  FG_Veci offset;
  FG_Vec dpi;
  float scale;
  void * handle;
  bool primary;
};
typedef int32_t (* FG_anon_36)(FG_Backend *, uint32_t, FG_Display *);
typedef int32_t (* FG_anon_37)(FG_Backend *, void *, FG_Rect *);
typedef void * (* FG_anon_38)(FG_Backend *, FG_MsgReceiver *, void *, FG_Vec *, FG_Vec *, const char*, uint64_t, void *);
typedef int32_t (* FG_anon_39)(FG_Backend *, void *, FG_Rect *, FG_Rect *, FG_Color, float, FG_Color, float, FG_Asset *, float, float, FG_BlendState *);
typedef int32_t (* FG_anon_40)(FG_Backend *, void *, FG_Clipboard, const char*, uint32_t);
typedef FG_Vec (* FG_anon_41)(FG_Backend *, FG_Font *, void *, FG_Rect *, uint32_t);
typedef FG_Font * (* FG_anon_42)(FG_Backend *, const char*, uint16_t, bool, uint32_t, FG_Vec, FG_AntiAliasing);
typedef int32_t (* FG_anon_43)(FG_Backend *, FG_Shader *);
typedef int32_t (* FG_anon_44)(FG_Backend *, void *, FG_Asset *);
typedef void * (* FG_anon_45)(FG_Backend *);
typedef int32_t (* FG_anon_46)(FG_Backend *, void *, FG_Display *);
typedef FG_Asset * (* FG_anon_47)(FG_Backend *, void *, uint32_t, uint8_t, FG_ShaderParameter *, uint32_t);
typedef int32_t (* FG_anon_48)(FG_Backend *, void *);
typedef bool (* FG_anon_49)(FG_Backend *, void *, FG_Clipboard);
typedef int32_t (* FG_anon_50)(FG_Backend *, void *, FG_Asset *, FG_Rect *, FG_Rect *, FG_Color, float, float, float, FG_BlendState *);
typedef int32_t (* FG_anon_51)(FG_Backend *, void *, FG_Shader *, FG_Asset *, FG_Asset *, FG_BlendState *, ...);
typedef int32_t (* FG_anon_52)(FG_Backend *, void *, FG_Rect *, FG_Vec, FG_Color, float, FG_Color, float, float, float, FG_Asset *, float, FG_BlendState *);
typedef uint32_t (* FG_anon_53)(FG_Backend *, void *, FG_Clipboard, void *, uint32_t);
typedef int32_t (* FG_anon_54)(FG_Backend *);
typedef int32_t (* FG_anon_55)(FG_Backend *, void *, void *);
typedef int32_t (* FG_anon_56)(FG_Backend *, void *, void *, FG_Rect *, ...);
typedef int32_t (* FG_anon_57)(FG_Backend *, void *, FG_MsgReceiver *, void *, FG_Vec *, FG_Vec *, const char*, uint64_t);
typedef bool (* FG_anon_58)(FG_Backend *, void *, FG_Color);
typedef int32_t (* FG_anon_59)(FG_Backend *, FG_Font *);
typedef FG_Asset * (* FG_anon_60)(FG_Backend *, void *, FG_Vec *, bool);
typedef int32_t (* FG_anon_61)(FG_Backend *, void *, FG_Cursor);
typedef int32_t (* FG_anon_62)(FG_Backend *, void *, FG_Asset *, float *, float, FG_BlendState *);
enum FG_BreakStyle {
  FG_BreakStyle_NONE = 0,
  FG_BreakStyle_CHARACTER = 2,
  FG_BreakStyle_WORD = 1
};
typedef void * (* FG_anon_63)(FG_Backend *, FG_Font *, const char*, FG_Rect *, float, float, FG_BreakStyle, void *);
typedef FG_Shader * (* FG_anon_64)(FG_Backend *, const char*, const char*, const char*, const char*, const char*, const char*, FG_ShaderParameter *, uint32_t);
typedef uint32_t (* FG_anon_65)(FG_Backend *, FG_Font *, void *, FG_Rect *, FG_Vec, FG_Vec *);
typedef int32_t (* FG_anon_66)(FG_Backend *, void *, FG_Vec *, uint32_t, FG_Color, float, FG_Color, FG_BlendState *);
typedef int32_t (* FG_anon_67)(FG_Backend *, void *, FG_Asset *, float *);
typedef void * (* FG_anon_68)(FG_Backend *, void *, const char*, FG_Rect *, ...);
typedef int32_t (* FG_anon_69)(FG_Backend *, void *, FG_Vec *, uint32_t, FG_Color, FG_BlendState *);
typedef int32_t (* FG_anon_70)(FG_Backend *, FG_Asset *);
struct FG_Backend__ {
  FG_anon_31 destroy;
  FG_Feature features;
  uint32_t formats;
  FG_Vec dpi;
  float scale;
  uint64_t cursorblink;
  uint64_t tooltipdelay;
  FG_anon_32 drawText;
  FG_anon_33 createAsset;
  FG_anon_35 clearClipboard;
  FG_anon_36 getDisplayIndex;
  FG_anon_37 pushClip;
  FG_anon_37 beginDraw;
  FG_anon_37 dirtyRect;
  FG_anon_38 createWindow;
  FG_anon_39 drawTriangle;
  FG_anon_40 putClipboard;
  FG_anon_41 fontPos;
  FG_anon_39 drawRect;
  FG_anon_42 createFont;
  FG_anon_43 destroyShader;
  FG_anon_44 setRenderTarget;
  FG_anon_45 getSyncObject;
  FG_anon_46 getDisplayWindow;
  FG_anon_47 createBuffer;
  FG_anon_48 endDraw;
  FG_anon_49 checkClipboard;
  FG_anon_50 drawAsset;
  FG_anon_51 drawShader;
  FG_anon_46 getDisplay;
  FG_anon_52 drawCircle;
  FG_anon_53 getClipboard;
  FG_anon_54 processMessages;
  FG_anon_55 destroySystemControl;
  FG_anon_56 setSystemControl;
  FG_anon_48 popClip;
  FG_anon_57 setWindow;
  FG_anon_58 clear;
  FG_anon_48 popLayer;
  FG_anon_59 destroyFont;
  FG_anon_48 destroyLayout;
  FG_anon_60 createLayer;
  FG_anon_61 setCursor;
  FG_anon_62 pushLayer;
  FG_anon_63 fontLayout;
  FG_anon_64 createShader;
  FG_anon_65 fontIndex;
  FG_anon_48 destroyWindow;
  FG_anon_66 drawCurve;
  FG_anon_67 getProjection;
  FG_anon_68 createSystemControl;
  FG_anon_69 drawLines;
  FG_anon_70 destroyAsset;
};
enum FG_JoyAxis {
  FG_JoyAxis_X = 0,
  FG_JoyAxis_INVALID = 65535,
  FG_JoyAxis_U = 4,
  FG_JoyAxis_Y = 1,
  FG_JoyAxis_V = 5,
  FG_JoyAxis_Z = 2,
  FG_JoyAxis_R = 3
};
enum FG_Touch {
  FG_Touch_MOVE = 1,
  FG_Touch_HOVER = 2,
  FG_Touch_PALM = 4
};
typedef FG_Backend * (* FG_InitBackend)(void *, FG_Log, FG_Behavior);
enum FG_Keys {
  FG_Keys_4 = 52,
  FG_Keys_S = 83,
  FG_Keys_PAGEDOWN = 34,
  FG_Keys_EXECUTE = 43,
  FG_Keys_F7 = 118,
  FG_Keys_PAGEUP = 33,
  FG_Keys_8 = 56,
  FG_Keys_W = 87,
  FG_Keys_NUMPAD_EQUAL = 146,
  FG_Keys_6 = 54,
  FG_Keys_F16 = 127,
  FG_Keys_NUMPAD5 = 101,
  FG_Keys_Y = 89,
  FG_Keys_RETURN = 13,
  FG_Keys_F9 = 120,
  FG_Keys_LSUPER = 91,
  FG_Keys_KANA = 21,
  FG_Keys_BACK = 8,
  FG_Keys_GRAVE = 192,
  FG_Keys_DELETE = 46,
  FG_Keys_LSHIFT = 160,
  FG_Keys_F14 = 125,
  FG_Keys_JUNJA = 23,
  FG_Keys_RSUPER = 92,
  FG_Keys_FINAL = 24,
  FG_Keys_B = 66,
  FG_Keys_LCONTROL = 162,
  FG_Keys_INSERT = 45,
  FG_Keys_F15 = 126,
  FG_Keys_APPS = 93,
  FG_Keys_XBUTTON1 = 5,
  FG_Keys_SELECT = 41,
  FG_Keys_H = 72,
  FG_Keys_F = 70,
  FG_Keys_F21 = 132,
  FG_Keys_J = 74,
  FG_Keys_L = 76,
  FG_Keys_NUMLOCK = 144,
  FG_Keys_RSHIFT = 161,
  FG_Keys_COMMA = 188,
  FG_Keys_F20 = 131,
  FG_Keys_NUMPAD1 = 97,
  FG_Keys_LEFT_BRACKET = 219,
  FG_Keys_SPACE = 32,
  FG_Keys_F18 = 129,
  FG_Keys_F23 = 134,
  FG_Keys_SEMICOLON = 186,
  FG_Keys_MODECHANGE = 31,
  FG_Keys_MENU = 18,
  FG_Keys_NUMPAD9 = 105,
  FG_Keys_5 = 53,
  FG_Keys_R = 82,
  FG_Keys_F19 = 130,
  FG_Keys_F6 = 117,
  FG_Keys_T = 84,
  FG_Keys_NUMPAD_MULTIPLY = 106,
  FG_Keys_ACCEPT = 30,
  FG_Keys_F22 = 133,
  FG_Keys_UP = 38,
  FG_Keys_NUMPAD2 = 98,
  FG_Keys_CANCEL = 3,
  FG_Keys_9 = 57,
  FG_Keys_X = 88,
  FG_Keys_F25 = 136,
  FG_Keys_NUMPAD0 = 96,
  FG_Keys_V = 86,
  FG_Keys_DOWN = 40,
  FG_Keys_SNAPSHOT = 44,
  FG_Keys_NUMPAD3 = 99,
  FG_Keys_F24 = 135,
  FG_Keys_NUMPAD8 = 104,
  FG_Keys_APOSTROPHE = 222,
  FG_Keys_A = 65,
  FG_Keys_NUMPAD6 = 102,
  FG_Keys_TAB = 9,
  FG_Keys_LBUTTON = 1,
  FG_Keys_PLUS = 187,
  FG_Keys_C = 67,
  FG_Keys_RIGHT_BRACKET = 221,
  FG_Keys_BACKSLASH = 220,
  FG_Keys_SLASH = 191,
  FG_Keys_PERIOD = 190,
  FG_Keys_HOME = 36,
  FG_Keys_NUMPAD4 = 100,
  FG_Keys_F1 = 112,
  FG_Keys_LMENU = 164,
  FG_Keys_E = 69,
  FG_Keys_RCONTROL = 163,
  FG_Keys_D = 68,
  FG_Keys_NONCONVERT = 29,
  FG_Keys_F11 = 122,
  FG_Keys_F8 = 119,
  FG_Keys_7 = 55,
  FG_Keys_NUMPAD7 = 103,
  FG_Keys_G = 71,
  FG_Keys_3 = 51,
  FG_Keys_F4 = 115,
  FG_Keys_RIGHT = 39,
  FG_Keys_RMENU = 165,
  FG_Keys_XBUTTON2 = 6,
  FG_Keys_SCROLL = 145,
  FG_Keys_CAPITAL = 20,
  FG_Keys_F12 = 123,
  FG_Keys_I = 73,
  FG_Keys_RBUTTON = 2,
  FG_Keys_1 = 49,
  FG_Keys_OEM_8 = 223,
  FG_Keys_P = 80,
  FG_Keys_U = 85,
  FG_Keys_Z = 90,
  FG_Keys_NULL = 0,
  FG_Keys_CONTROL = 17,
  FG_Keys_NUMPAD_DECIMAL = 110,
  FG_Keys_K = 75,
  FG_Keys_CLEAR = 12,
  FG_Keys_M = 77,
  FG_Keys_F2 = 113,
  FG_Keys_KANJI = 25,
  FG_Keys_ESCAPE = 27,
  FG_Keys_SHIFT = 16,
  FG_Keys_F13 = 124,
  FG_Keys_MBUTTON = 4,
  FG_Keys_LEFT = 37,
  FG_Keys_HELP = 47,
  FG_Keys_MINUS = 189,
  FG_Keys_N = 78,
  FG_Keys_0 = 48,
  FG_Keys_CONVERT = 28,
  FG_Keys_O = 79,
  FG_Keys_PRINT = 42,
  FG_Keys_SLEEP = 95,
  FG_Keys_NUMPAD_ADD = 107,
  FG_Keys_NUMPAD_DIVIDE = 111,
  FG_Keys_END = 35,
  FG_Keys_F10 = 121,
  FG_Keys_NUMPAD_SUBTRACT = 109,
  FG_Keys_SEPARATOR = 108,
  FG_Keys_Q = 81,
  FG_Keys_F5 = 116,
  FG_Keys_2 = 50,
  FG_Keys_F3 = 114,
  FG_Keys_PAUSE = 19,
  FG_Keys_F17 = 128
};
typedef struct FG_URect__ FG_URect;
struct FG_URect__ {
  FG_Rect abs;
  FG_Rect rel;
};
typedef struct FG_UVec__ FG_UVec;
struct FG_UVec__ {
  FG_Vec abs;
  FG_Vec rel;
};

#endif