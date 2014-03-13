#ifndef GRID_R
#define GRID_R

#include "Object.r"

struct __Grid {
  struct __Object _;
  int dim;
  int steps;
  float **axes;
};

struct __GridClass {
  struct __Class _;
  struct Method point;
};

#endif // GRID_R
