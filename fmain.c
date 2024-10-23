#include <stdio.h>
#include "common.h"

__attribute__ ((noinline)) 
float loop3(int zero);

int main(int argc, char* argv[]) {
   int i;
   float f=0;
   argc&=10000;

   ROI_BEGIN(); 
   for (i=0;i<10000;++i)
      f+=loop3(argc);
   ROI_END();
   volatile float a = f;
}

