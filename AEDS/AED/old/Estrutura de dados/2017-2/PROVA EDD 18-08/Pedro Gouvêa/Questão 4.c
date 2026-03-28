#include <stdlib.h>
#include <stdio.h>
#define p 3.1415

void calc_esfera(float R, float *area, float *volume) {
  *area = 4*p*(R*R);
  *volume = (4*p*R*R*R)/3;
}

int main() {
  float R, area = 0, volume = 0;
  printf("Informe o valor do raio: ");
  scanf("%f", &R);

  calc_esfera(R, &area, &volume);

  printf("Area: %.2f\nVolume: %.2f", area, volume);

  return 0;
}
