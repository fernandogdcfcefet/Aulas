#include <stdio.h>
#include <stdlib.h>
#define P 3.1415

typedef struct{
    float R;
    float volume;
    float area;
}Esfera;

void calc_esfera(float R, float *area, float *volume){
    *area=4*P*R*R;
    *volume=4/3*P*R*R*R;
}

int main()
{
    Esfera E;
    printf("Digite o raio da esfera: ");
    scanf("%f", &E.R);

    calc_esfera(E.R,&E.area,&E.volume);
    printf("\n\nArea: %.2f\n",E.area);
    printf("Volume: %.2f",E.volume);
    return 0;
}
