#include <stdio.h>
#include "common.h"

__attribute__ ((noinline))
int loop(int zero);

int main(int argc, char* argv[]) {
   int i, t=0;
   argc&=10000;
   ROI_BEGIN();
   for (i=0;i<1000;++i)
      t+=loop(argc);
   ROI_END();
   volatile int a = t;
}

