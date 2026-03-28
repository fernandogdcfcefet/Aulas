#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define tam 10

double desvioPadrao (int vet[tam]){


    int i;
    double valor=0, media=0, dp0=0;

    for(i=0; i<tam; i++){


        valor = valor + vet[i];

    }

     media = media + (valor / tam);

    for(i=0; i<tam; i++){

        dp0 = ((1 / (i - 1)) * ((vet[i] - media) * (vet[i] - media)));

    }

    return sqrt(dp0);
}


int main()
{
    int vet[tam];

    double result = desvioPadrao(vet);

    printf("%f", result);


    return 0;
}
