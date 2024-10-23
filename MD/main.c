#include <stdio.h>
#include <stdlib.h>     /* malloc, free, rand */
#include "common.h"

#define LEN   2048

struct ll {
  int val;
  struct ll* _next;
};

__attribute__ ((noinline))
int loop(int zero,struct ll* n);

int main(int argc, char* argv[]) {
   argc&=10000;
   struct ll *n, *cur;

   int i,t = 0;
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

