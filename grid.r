#ifndef GRID_R
#define GRID_R

#include "Object.r"

struct __Grid {
  struct __Object _;
  int dim;
  int steps;
  float *delatax;
  float **axes;
};

#define Deltax(x) (((const struct __Grid *) (x)) ->delatax[0])
#define Steps(x) (((const struct __Grid *) (x)) ->steps)

struct __GridClass {
  struct __Class _;
  struct Method point;
};

#endif // GRID_R
