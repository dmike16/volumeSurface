#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <stdarg.h>
#include "implicitForm.r"
#include "implicitForm.h"


static void
*ImplicitForm_ctor(void *_self,va_list *app){
  struct __ImplicitForm *self = super_ctor(ImplicitForm,_self,app);

  typedef void* voidstar;
  typedef double dprecision;
  self->delegate = va_arg(*app,voidstar);
  self->level = va_arg(*app,dprecision);
  self->u = (levelSet)respondsTo(self->delegate,"surface");
  self->vol = (volM)respondsTo(self->delegate,"volume");

  return self;
}

static void
*ImplicitForm_dtor (void *_self)
{
  struct __ImplicitForm *self = super_dtor(ImplicitForm,_self);

  free(dtor(self->delegate));

  return self;
}

float
u_surface(const void *_self, const float *x){
  struct __ImplicitForm *self = cast(Object,_self);

  return self->u(self->delegate,x);
}

float
u_vol(const void *_self){
  struct __ImplicitForm *self = cast(Object,_self);

  return self->vol(self->delegate,self);
}

const void *_ImplicitForm;

const void
*__implicitform(){
  return new(Class,"ImplicitSurface",Object,sizeof(struct __ImplicitForm),
             ctor,"",ImplicitForm_ctor,
             dtor,"",ImplicitForm_dtor,
             (void*)0);
}
