#include <stdio.h>

int  main(){
  float celcius=0;
  float step=15;
  float high=150;
  printf("celcius to farenheit\n");
  while(celcius<=high){
    float fh=(celcius*(9/5))+32;
    printf("%3.0f\t%6.2f\n",celcius,fh);
    celcius+=step;
  }
}
