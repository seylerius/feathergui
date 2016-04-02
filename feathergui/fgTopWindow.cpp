// Copyright �2016 Black Sphere Studios
// For conditions of distribution and use, see copyright notice in "feathergui.h"

#include "fgTopWindow.h"
#include "fgText.h"
#include "feathercpp.h"

size_t FG_FASTCALL fgTopWindow_CloseMessage(fgButton* self, const FG_Msg* msg)
{
  if(msg->type == FG_ACTION)
    fgChild_IntMessage(self->window.element.parent, FG_ACTION, FGTOPWINDOW_CLOSE, 0);
  return fgButton_Message(self, msg);
}

size_t FG_FASTCALL fgTopWindow_MaximizeMessage(fgButton* self, const FG_Msg* msg)
{
  if(msg->type == FG_ACTION)
    fgChild_IntMessage(self->window.element.parent, FG_ACTION, !memcmp(&self->window.element.parent->element, &fgElement_DEFAULT, sizeof(fgElement))? FGTOPWINDOW_RESTORE : FGTOPWINDOW_MAXIMIZE, 0);
  return fgButton_Message(self, msg);
}

size_t FG_FASTCALL fgTopWindow_MinimizeMessage(fgButton* self, const FG_Msg* msg)
{
  if(msg->type == FG_ACTION)
    fgChild_IntMessage(self->window.element.parent, FG_ACTION, (self->window.element.parent->flags&FGCHILD_HIDDEN)? FGTOPWINDOW_UNMINIMIZE : FGTOPWINDOW_MINIMIZE, 0);
  return fgButton_Message(self, msg);
}

void FG_FASTCALL fgTopWindow_Init(fgTopWindow* self, fgFlag flags, const fgElement* element)
{
  fgChild_InternalSetup(*self, flags, 0, 0, element, (FN_DESTROY)&fgTopWindow_Destroy, (FN_MESSAGE)&fgTopWindow_Message);
}
void FG_FASTCALL fgTopWindow_Destroy(fgTopWindow* self)
{  
  fgWindow_Destroy((fgWindow*)self);
}

size_t FG_FASTCALL fgTopWindow_Message(fgTopWindow* self, const FG_Msg* msg)
{
  assert(self!=0 && msg!=0);

  switch(msg->type)
  {
  case FG_CONSTRUCT:
    fgWindow_Message((fgWindow*)self, msg);
    self->dragged = 0;
    fgText_Init(&self->caption, 0, 0, 0, FGCHILD_BACKGROUND | FGCHILD_IGNORE | FGCHILD_EXPAND, *self, 0, 0);
    fgButton_Init(&self->controls[0], FGCHILD_BACKGROUND, *self, 0, 0);
    fgButton_Init(&self->controls[1], FGCHILD_BACKGROUND, *self, 0, 0);
    fgButton_Init(&self->controls[2], FGCHILD_BACKGROUND, *self, 0, 0);
    fgChild_AddPreChild(*self, self->caption);
    fgChild_AddPreChild(*self, self->controls[0]);
    fgChild_AddPreChild(*self, self->controls[1]);
    fgChild_AddPreChild(*self, self->controls[2]);
    self->controls[0].window.element.message = (FN_MESSAGE)&fgTopWindow_CloseMessage;
    self->controls[1].window.element.message = (FN_MESSAGE)&fgTopWindow_MaximizeMessage;
    self->controls[2].window.element.message = (FN_MESSAGE)&fgTopWindow_MinimizeMessage;
    return 1;
  case FG_SETTEXT:
  case FG_SETFONT:
  case FG_SETCOLOR:
  case FG_GETTEXT:
  case FG_GETFONT:
  case FG_GETCOLOR:
    return fgChild_PassMessage(self->caption, msg);
  case FG_MOUSEDBLCLICK:
    if(msg->button == FG_MOUSELBUTTON)
    {
      AbsRect out;
      ResolveRect(*self, &out);
      if(msg->y < out.top + self->window.element.padding.top)
        fgChild_IntMessage(*self, FG_ACTION, FGTOPWINDOW_MAXIMIZE, 0);
      return 1;
    }
    break;
  case FG_MOUSEDOWN:
    if(msg->button == FG_MOUSELBUTTON)
    {
      AbsRect out;
      ResolveRect(*self, &out);

      // Check for resize

      // Check for move
      if(msg->y < out.top + self->window.element.padding.top)
      {
        self->offset.x = msg->x;
        self->offset.y = msg->y;
        self->dragged = 1;
      }

      if(self->dragged)
      {
        fgCaptureWindow = *self;
        fgSendMsg<FG_ACTIVE>(*self);
      }
    }
    break;
  case FG_MOUSEMOVE:
    if(self->dragged&1) // window is being moved around
    {
      AbsVec v = { msg->x, msg->y };
      CRect area = self->window.element.element.area;
      AbsVec dv = { v.x - self->offset.x + area.left.abs, v.y - self->offset.y + area.top.abs };
      MoveCRect(dv, &area);
      self->offset = v;
      fgSendMsg<FG_SETAREA, void*>(*self, &area);
      fgSendMsg<FG_SETAREA, void*>(*self, &area);
    }
    if(self->dragged & 2) {} // resize on left
    if(self->dragged & 4) {} // resize on top
    if(self->dragged & 8) {} // resize on right
    if(self->dragged & 16) {} // resize on bottom
    break;
  case FG_MOUSEUP:
    self->dragged = 0;
    if(fgCaptureWindow == *self) // Remove our control hold on mouse messages.
      fgCaptureWindow = 0;
    break;
  case FG_ACTION:
    switch(msg->otherint)
    {
    case FGTOPWINDOW_MINIMIZE:
      fgChild_IntMessage(*self, FG_SETFLAG, FGCHILD_HIDDEN, 1);
      break;
    case FGTOPWINDOW_UNMINIMIZE:
      fgChild_IntMessage(*self, FG_SETFLAG, FGCHILD_HIDDEN, 0);
      break;
    case FGTOPWINDOW_MAXIMIZE:
      self->prevrect = self->window.element.element.area;
      fgSendMsg<FG_SETAREA, void*>(*self, (void*)&fgElement_DEFAULT.area);
      break;
    case FGTOPWINDOW_RESTORE:
      fgSendMsg<FG_SETAREA, void*>(*self, &self->prevrect);
      break;
    case FGTOPWINDOW_CLOSE:
      VirtualFreeChild(*self);
      return 1;
    }
  case FG_GETCLASSNAME:
    return (size_t)"fgTopWindow";
  }
  return fgWindow_Message((fgWindow*)self,msg);
}