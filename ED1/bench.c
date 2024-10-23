#include <stdio.h>
#include "common.h"

#define ASIZE 2048
#define STEP   128
#define ITERS 4096

__attribute__ ((noinline))
int loop(int zero) {
  int t1 = zero*zero+zero+1;

  int i;
  for(i=zero; i < ITERS; i+=1) {
    t1=t1/(zero+1);
  }
  return t1;
}
