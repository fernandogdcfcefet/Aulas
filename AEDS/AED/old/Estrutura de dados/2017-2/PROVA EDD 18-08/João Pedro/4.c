#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

void calc_esfera(float R, float *area, float *volume){
    *area = 4*PI*(R*R);
    *volume = (4/3)*PI*(R*R*R);
}

int main()
{
    float area, volume, raio;
    printf("Digite o raio: ");
    scanf("%f", &raio);
    calc_esfera(raio, &area, &volume);
    printf("Area: %.2f\n", area);
    printf("\nVolume: %.2f\n", volume);
    return 0;
}
