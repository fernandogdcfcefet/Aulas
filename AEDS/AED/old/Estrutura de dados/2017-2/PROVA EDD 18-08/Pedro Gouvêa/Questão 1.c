#include <stdlib.h>
#include <stdio.h>
#define n 2

float desvio_padrao(float v[]) {
  int i;
  float media = 0, soma = 0, desP = 0, somatorio = 0;

  for(i = 0; i < n; i++)
    soma += v[i];

  media = soma/2;

  for(i = 0; i < n; i++) {
    somatorio += pow(v[i] - media, 2);
  }

  desP = sqrt((1/(n - 1))* somatorio);

  return desP;
}

int main() {
  float vet[n];
  int i;
  for(i = 0; i < n; i++)
    scanf("%f", &vet[i]);

  printf("Desvio padrao: %.2f", desvio_padrao(vet));
  return 0;
}
