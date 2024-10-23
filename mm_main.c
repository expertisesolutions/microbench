#include <stdio.h>
#include <stdlib.h>     /* malloc, free, rand */
#include "common.h"

#define LEN  32768

//make sure struct occupies an entire cache line.
struct ll {
  int val;
  long long p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
  long long q1,q2,q3,q4,q5,q6,q7,q8,q9,q10;
  struct ll* _next;
};

int loop(int zero,struct ll* n);

int main(int argc, char* argv[]) {
   argc&=10000;
   int i,t=0;
   struct ll *n, *cur;

   n=malloc(sizeof(struct ll));
   cur=n;
   for(i=0;i<LEN;++i) {
     cur->val=i;
     cur->_next=malloc(sizeof(struct ll));
     cur=cur->_next;
   }
   cur->val=100;
   cur->_next=NULL;

   ROI_BEGIN(); 
   for (i=0;i<10000;++i)
      t+=loop(argc,n);
   ROI_END();

   volatile int a = t;
}


