#include <stdio.h>
#include <stdlib.h>

float media(float V[]){
    int i;
    float Media=0.0;
    for(i=0;i<10;i++){
        Media=Media+V[i];
    }
    return Media/10;
}

double DesvioPadrao (int n, float m, float vet[]){
    double DP;
    float Som=0;
    int i;
    for(i=0;i<n;i++){
        Som=Som+((vet[i]-m)*(vet[i]-m));
    }
    DP=sqrt((1/(n-1))*Som);
    return DP;
}

int main()
{
    float Vet[10];
    int i;
    printf("Digite os numeros a ser calculado o desvio padrao: \n");

    for(i=0;i<10;i++){
        scanf("%f", &Vet[i]);
    }
    printf("\n\n");

    printf("\n\n%d \n\n",DesvioPadrao(10,media(Vet),Vet));
    return 0;
}
