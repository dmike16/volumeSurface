#include <stdio.h>
#include <malloc.h>
#include <mcheck.h>
#include "implicitForm.h"
#include "surfaceSphere.h"
#include "grid.h"

int main(void)
{
#ifdef MEMTRACE
  mtrace();
#endif
  // This main is only for test i'll change it
  float x[] ={0.4f,0.6f,0.3f};
  float **omega = malloc(sizeof(float*)*3);
  int i;
  for(i=0; i<3; i++){
    omega[i]=malloc(sizeof(float)*2);
    omega[i][0]=-3.00f;
    omega[i][1]=3.00f;
    }
  printf("Hello World!\n");
  void *surf = new(ImplicitForm,
                   new(SurfaceSphere,
                       new(Grid,3,100,omega),3,1.00f),0.5);
  printf("Il valore della superfici nel punto %.2f,%.2f,%.2f è %.2f\n",
         0.4f,0.6f,0.3f,u_surface(surf,x));
  delete(surf);
  for(i=0; i<3; i++)
    free(omega[i]);
  free(omega);
  return 0;
}

