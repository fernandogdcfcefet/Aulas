#include<stdio.h>
#define Pi 3.14

void calc_esfera(float R, float *area, float *volume){
    *area = 4*Pi*R*R;
    *volume = (4/3)*Pi*R*R*R;
}

int main(){
    float Raio, a = 0, v = 0;

    scanf("%f", &Raio);

    calc_esfera(Raio,&a,&v);

    printf("Area: %.2f\nVolume: %.2f\nRaio: %.2f\n", a, v, Raio);

    return(0);
}
