#include <stdio.h>
#include <stdarg.h>
#include <malloc.h>
#include "surface.r"
#include "surface.h"


static void
*Surface_ctor(void *_self, va_list *app){
  struct __Surface *self = super_ctor(Surface,_self,app);

  typedef void* voidstar;
  self->delegate = va_arg(*app,voidstar);
  self->point = (pointM) respondsTo(self->delegate,"point");

  return self;
}

static void
*Surface_dtor (void *_self)
{
  struct __Surface *self = super_dtor(Surface,_self);

  free(dtor(self->delegate));

  return self;
}

static void
*SurfaceClass_ctor(void *_self, va_list *app){
  struct __SurfaceClass *self = super_ctor(SurfaceClass,_self,app);

  typedef const char *stringconst;
  Method selector;
  va_list ap;

  va_copy(ap,*app);

  while((selector = va_arg(ap,Method))){
      const char *tag = va_arg(ap,stringconst);

      Method method = va_arg(ap,Method);

// Install function  implicit
      if(selector == (Method) surface){
          if(tag)
            self->surface.tag = tag;
          self->surface.selector = selector;
          self->surface.method = method;
          continue;
        }
// Install function eval volume
      if(selector == (Method) volume){
          if(tag)
            self->volume.tag = tag;
          self->volume.selector = selector;
          self->volume.method = method;
          continue;
        }
    }

  va_end(ap);
  return self;
}

const void *_SurfaceClass;
const void *_Surface;

const void*
__surfaceclass(){
  return new(Class,"SurfaceClass",Class,sizeof(struct __SurfaceClass),
             ctor,"",SurfaceClass_ctor,
             (void*)0);
}

const void*
__surface(){
  return new(SurfaceClass,"Surface",Object,sizeof(struct __Surface),
             ctor,"",Surface_ctor,
             dtor,"",Surface_dtor,
             (void*)0);
}
