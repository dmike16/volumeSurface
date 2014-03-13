#ifndef SURFACE_R
#define SURFACE_R

#include "Object.r"

typedef float * (*pointM) (const void*,const int*,float*);

struct __Surface {
  struct __Object _;
  struct __Object *delegate;
  pointM point;
};

struct __SurfaceClass{
  struct __Class _;
  struct Method surface;
  struct Method volume;
};

#endif // SURFACE_R
