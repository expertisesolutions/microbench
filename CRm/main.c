#include <stdio.h>
#include "randArr.h"
#include "common.h"

#define ASIZE 16384

int temp[ASIZE];

__attribute__ ((noinline))
void mergeSort(int numbers[], int temp[], int array_size);
 
int main(int argc, char* argv[]) {
   argc&=10000;
   ROI_BEGIN(); 
   mergeSort(randArr,temp,ASIZE);
   ROI_END();
   volatile int a = temp[argc];
}

