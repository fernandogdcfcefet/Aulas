#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define p 3.14
//#define R 2.0
void calc_esfera(float R,float *area,float *volume){
 *area=4*p*R*R;
 *volume=(4*p*R*R*R)/3;
   printf("area: %f\n",*area);
   printf("volume:%f\n",*volume);
}
int main(){
 float area,volume,R=2.0;


 calc_esfera(R,&area,&volume);

 return 0;
}
