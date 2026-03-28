#include <stdio.h>
#include <stdlib.h>
#define TAM 8

typedef struct{
    int vet[TAM];
    int frente, tras,tamanho;
}fila;
void esvazia(fila * minhaFila){
    minhaFila->frente=0;
    minhaFila->tras=minhaFila->frente;
    minhaFila->tamanho=0;
}
void enfilera(fila *minhaFila, int x){
    //verificar se a fila esta cheia
    if(minhaFila->tamanho==TAM){
        printf("FILA CHEIA\n");
    }else{
        minhaFila->vet[minhaFila->tras%TAM]=x;
        minhaFila->tras++;
        minhaFila->tamanho++;
//    minhaFila->tras=minhaFila->tras%TAM+1;;
    }
}
void desenfilera(fila *minhaFila){
    minhaFila->frente=(minhaFila->frente+1)%TAM;
    minhaFila->tamanho--;
}
void imprimeFila(fila minhaFila){
    int i;
    for(i=minhaFila.frente;i!=minhaFila.tras;
    i=i%TAM+1){
        printf("%d \n",minhaFila.vet[i]);
    }
}
int main()
{
    fila MF;
    esvazia(&MF);
    enfilera(&MF,1);
    enfilera(&MF,2);
    enfilera(&MF,3);
    enfilera(&MF,4);
    enfilera(&MF,5);
    enfilera(&MF,6);
    enfilera(&MF,7);
    desenfilera(&MF);
    desenfilera(&MF);
    desenfilera(&MF);
    enfilera(&MF,8);
    imprimeFila(MF);
    return 0;
}
