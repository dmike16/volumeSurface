#ifndef IMPLICITFORM_H
#define IMPLICITFORM_H

#include "Object.h"

extern const void* _ImplicitForm;
#define ImplicitForm (_ImplicitForm ? _ImplicitForm : \
  (_ImplicitForm = __implicitform()))

float u_surface(const void *self, const float *x);
const void* __implicitform();

#endif // IMPLICITSURFACE_H
