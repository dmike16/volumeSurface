#include <stdio.h>
#include <stdarg.h>
#include <malloc.h>
#include <math.h>
#include "assert.h"
#include "surfaceSphere.r"
#include "implicitForm.r"
#include "grid.r"
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
  else if(x >= -epsilon && x <= epsilon)
    return 0.50f + x/(2.00f*epsilon) + (1.00f/(2.00f*PI))*sin((PI*x)/epsilon);
  else
    return 1.00f;
}

static float
SurfaceSphere_volume(const void *_self,const void *_implicitSurf){

  struct __SurfaceSphere *self = cast(Surface,_self);
  struct __ImplicitForm *impSurf = cast(Object,_implicitSurf);

  float deltax = Deltax(Delegate(self));
  float epsilon = deltax*(3.00f/2.00f);
  int steps = Steps(Delegate(self));
  int gSize = (int)powf(steps,self->space);
  float vol = 0.0f;
  float val;
  register int i,flag;
  float *x = malloc(sizeof(float)*self->space);
  int *index = calloc(1,sizeof(int)*self->space);

  assert(x);
  assert(index);

  printf("level = %.2f raggio = %.2f deltax=%.2f  e epsilon = %.2f\n",
         impSurf->level,self->radius,deltax,epsilon);
  for(i = 0; i < gSize; i++){
      x = Point(self)(Delegate(self),index,x);
      val=(impSurf->u)(self,x);
      if(val != 0.0f)
          vol += (1-heaviSide((val-impSurf->level),epsilon));

      for(flag = 0; flag < self->space; flag++)
            if(index[flag] == steps-1)
              index[flag] = 0;
            else{
              ++index[flag];
              break;}
    }

  free(x);
  free(index);

  return vol*powf(deltax,self->space);
}

float
surface(const void *_self,const  float *x){
  struct __SurfaceClass *self = cast(SurfaceClass,classOf(_self));

  assert((levelSet)surface == surface);
  assert(self->surface.method);

  return ((levelSet)self->surface.method)(_self,x);
}

float
volume(const void *_self, const void *implicitSurf){
  struct __SurfaceClass *self = cast(SurfaceClass,classOf(_self));

  assert((volM)volume == volume);
  assert(self->volume.method);

  return ((volM)self->volume.method)(_self,implicitSurf);
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
