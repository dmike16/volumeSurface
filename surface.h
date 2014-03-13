#ifndef SURFACE_H
#define SURFACE_H

#include "Object.h"

extern const void *_SurfaceClass;
extern const void *_Surface;
#define SurfaceClass (_SurfaceClass ? _SurfaceClass : (_SurfaceClass = __surfaceclass()))
#define Surface (_Surface ? _Surface : (_Surface = __surface()))

float surface(const void *self, const float *x);
float volume(const void *self, const void *implicitSurf,const float *Omega, float step);
const void *__surfaceclass();
const void *__surface();

#endif // SURFACE_H
