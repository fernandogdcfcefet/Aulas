#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 10

//função calcula media, usa somente o vetor como parametro
float media(float vtr[n]){
    float med;
    int i;
    for(i=0;i<n;i++)
        med+=vtr[i];
    return med/n;
}

//calcula o desvio padrao utilizando o vetor e sua media como parametro
float desvio_padrao(float vet[n], float media){
    float dp, soma;
    int i = 0;
    for(i = 0; i<n; i++)
        soma += pow((vet[i] - media),2);
    dp = sqrt(pow(n-1,-1)*soma );
    return dp;
}


int main()
{

    float m = 0.0, vetor[n], desviop = 0.0;
    int i = 0;
    printf("Insira os 10 elementos para que seja calculado o desvio padrao\n");
    for(i=0;i<n;i++)
        scanf("%f", &vetor[i]);
    m = media(vetor);
    desviop = desvio_padrao(vetor,m);
    printf("Desvio padrao e: %.2f\n", desviop);

    return 0;
}
