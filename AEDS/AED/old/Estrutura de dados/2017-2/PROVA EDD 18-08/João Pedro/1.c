#include <stdio.h>
#include <stdlib.h>
#include<math.h>

#define TAM 10

float calcula(float vetor[]){
    float media, soma, desvio;
    int i;
    for(i=0; i<TAM; i++)
        media = media + vetor[i];
    media = media / TAM;

    for(i=0; i<TAM; i++)
        soma = soma + ((vetor[i]*media)*(vetor[i]*media));

    return desvio = sqrt(soma/(TAM-1));
}

pegaValor(float vetor[]){
    int i;
    printf("\n\n\tDIGITE OS VALORS\n\n");
    for(i=0; i<TAM; i++){
        printf("Posicao %d: ", i+1);
        scanf("%f", &vetor[i]);
    }
}

int main()
{
    float vetor[TAM], desvio;
    pegaValor(vetor);
    desvio = calcula(vetor);
    printf("\n\nDesvio padrao: %.2f\n\n", desvio);
    return 0;
}
