#include <stdio.h>
#include <stdarg.h>
#include <malloc.h>
#include <math.h>
#include "assert.h"
#include "surfaceSphere.r"
#include "implicitForm.r"
#include "surfaceSphere.h"

#define PI 3.14159265f
static void
*SurfaceSphere_ctor(void *_self, va_list *app){
  struct __SurfaceSphere *self = super_ctor(SurfaceSphere,_self,app);

/* definition local, made becouse of the error check by qtcreator
 but the program works wtihout too
*/
  typedef int integer;
  typedef double dprecision;

  self->space = va_arg(*app,integer);
  self->radius = va_arg(*app,dprecision);

  return self;
}

static float
SurfaceSphere_surface(const void* _self, const float *x){
  struct __SurfaceSphere *self = cast(SurfaceSphere,_self);

  register int i;
  float u = 0.00f;
  float r_two = (self->radius)*(self->radius);

    for (i = 0; i < self->space; i++)
      u += (x[i])*(x[i]);
    if (u <= r_two)
      return r_two-u;
    else
      return 0.0f;
}

static float
heaviSide(float x, float epsilon){
  if(x < -epsilon)
    return 0.00f;
  else if(x >= -epsilon && x < epsilon)
    return 0.50f + x/(2.00f*epsilon) + (1.00f/(2.00f*PI))*sin((PI*x)/epsilon);
  else
    return 1.00f;
}

static float
SurfaceSphere_volume(const void *_self,const void *_implicitSurf,
                     const float *Omega, float step){

  struct __SurfaceSphere *self = cast(Object,_self);
  struct __ImplicitForm *impSurf = cast(Object,_implicitSurf);

  printf("incostruzione\n");

  /*float epsilon = step*(3.00f/2.00f);
  float vol = 0.0f;
  register int i,flag;
  float *x = malloc(sizeof(float)*self->space);
  int *index = calloc(1,sizeof(int)*self->space);

  assert(x);
  assert(index);

  for(i = 0; i < steps; i++){
      vol += 1-heaviSide(((impSurf->u)(self,x)-impSurf->level),epsilon);
    }

  free(x);
  free(index);
*/
  return 1.0f;
}

float
surface(const void *_self,const  float *x){
  struct __SurfaceClass *self = cast(SurfaceClass,classOf(_self));

  assert((levelSet)surface == surface);
  assert(self->surface.method);

  return ((levelSet)self->surface.method)(_self,x);
}

float
volume(const void *_self, const void *implicitSurf,
       const float *Omega, float step){
  struct __SurfaceClass *self = cast(SurfaceClass,classOf(_self));

  assert((volM)volume == volume);
  assert(self->volume.method);

  return ((volM)self->volume.method)(_self,implicitSurf,Omega,step);
}

const void* _SurfaceSphere;

const void
*__surfacesphere(){
  return new(SurfaceClass,"SurfaceSphere",Surface,sizeof(struct __SurfaceSphere),
             ctor,"",SurfaceSphere_ctor,
             surface,"surface",SurfaceSphere_surface,
             volume,"volume",SurfaceSphere_volume,
             (void*)0);
}
