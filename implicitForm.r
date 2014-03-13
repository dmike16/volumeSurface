#ifndef IMPLICITFORM_R
#define IMPLICITFORM_R

#include "Object.r"

typedef float (*levelSet)(const void*,const float*);
typedef float (*volM)(const void*,const void*,const float*,float);

struct __ImplicitForm {
  struct __Object _;
  struct __Object *delegate;
  levelSet u;
  volM vol;
  float level;
};

#endif // IMPLICITSURFACE_R
