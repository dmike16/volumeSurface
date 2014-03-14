#ifndef SURFACE_R
#define SURFACE_R

#include "Object.r"

typedef float * (*pointM) (const void*,const int*,float*);

struct __Surface {
  struct __Object _;
  struct __Object *delegate;
  pointM point;
};

#define Delegate(x) (((const struct __Surface *) (x))->delegate)
#define Point(x) (((const struct __Surface *) (x))->point)

struct __SurfaceClass{
  struct __Class _;
  struct Method surface;
  struct Method volume;
  struct Method volError;
};

#endif // SURFACE_R
