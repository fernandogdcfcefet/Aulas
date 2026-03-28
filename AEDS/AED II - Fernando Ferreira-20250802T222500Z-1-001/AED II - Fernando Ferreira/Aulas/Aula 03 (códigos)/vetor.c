#include <stdio.h>
#include <stdlib.h>

float *Alocar_vetor_real (int n){
    if (n < 1){
        printf ("** Erro: Parametro invalido **\n");
        return (NULL);
    }
    float * v = (float*)calloc (n, sizeof(float));
    if (v == NULL){
        printf ("** Erro: Memoria Insuficiente **");
        return (NULL);
    }
    return (v);
}
void Liberar_vetor_real (float *v)
{
    if (v != NULL)
        free(v);
}

int main (void) {
    int i;
    int TAM;

    do{
        printf("Digite o tamanho de TAM (> 0): ");
        scanf("%d", &TAM);
    } while(TAM <=0);

    float *vetor_real = Alocar_vetor_real(TAM);

    for (i=0; i<TAM; i++)
        vetor_real[i] = i;

    for (i=0; i<TAM; i++)
        printf("\n%.2f",vetor_real[i]);

    Liberar_vetor_real (vetor_real);

    return 0;
}
