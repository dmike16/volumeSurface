#include <stdio.h>
#include <malloc.h>
#include <mcheck.h>
#include "implicitForm.h"
#include "surfaceSphere.h"
#include "surfaceTorus.h"
#include "grid.h"

int main(void)
{
//#ifdef MEMTRACE
  mtrace();
//#endif
  // This main is only for test i'll change it
  float **omega = malloc(sizeof(float*)*3);
  int i;
  for(i=0; i<3; i++){
    omega[i]=malloc(sizeof(float)*2);
    omega[i][0]=-3.00f;
    omega[i][1]=3.00f;
    }
  void *surf_toro = new(ImplicitForm,
                   new(SurfaceTorus,
                       new(Grid,3,100,omega),3,0.3,0.5f),0.0f);
  float vol = uVol(surf_toro);
  printf("vol(S) = %.4f\n",vol);
  printf(" ||Error Volume||= %.2e \n",uVolError(surf_toro,vol));
  delete(surf_toro);
  void *surf_s = new(ImplicitForm,
                     new(SurfaceSphere,
                       new(Grid,3,100,omega),3,3.0f),5.0f);

  vol = uVol(surf_s);
  printf("vol(S) = %.4f\n",vol);
  printf(" ||Error Volume||= %.2e \n",uVolError(surf_s,vol));
  delete(surf_s);
  for(i=0; i<3; i++)
    free(omega[i]);
  free(omega);
  return 0;
}

