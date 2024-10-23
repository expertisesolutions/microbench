#include <stdio.h>
#include <stdlib.h>     /* malloc, free, rand */

#include "common.h"

#define ASIZE 2048
#define STEP   128
#define ITERS    2
#define LEN  32768

int arr[ASIZE];

//make sure struct occupies an entire cache line.
struct ll {
  int val;
  long long p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
  long long q1,q2,q3,q4,q5,q6,q7,q8,q9,q10;
  struct ll* _next;
};

__attribute__ ((noinline))
int loop(int zero,struct ll* n) {
  int t = 0,i,iter;
  for(iter=0; iter < ITERS; ++iter) {
    struct ll* cur =n;
    while(cur!=NULL) {
      //t+=cur->val;
      cur->val=7; //a tore!
      cur=cur->_next;
    }
  }
  return t;
}
