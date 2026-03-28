#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415

void calc_esfera(float R, float *area, float *volume){
    *area = 4*PI*pow(R,2);
    *volume = ((float)4/3)*PI*pow(R,3);
}

int main()
{
    float raio, area = 0.0, vol = 0.0;
    calc_esfera(raio,&area,&vol);
    printf("Area = %.2f, Volume = %.2f", area, vol);
    return 0;
}
