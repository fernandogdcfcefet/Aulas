#include <stdio.h>
#include <stdlib.h>
typedef struct celula *apontador;
typedef struct celula{
    apontador prox;
    char item;
}celula;

typedef struct{
    apontador frente, atras;
    int tam;
}fila;

void inicializa(fila *minhaFila){
    minhaFila->frente = (apontador)malloc(sizeof(celula));
    minhaFila->atras = minhaFila->frente;
    minhaFila->tam = 0;
}

int isVazia(fila minhaFila){
    return ((minhaFila.frente==minhaFila.atras)&&(minhaFila.tam==0));
}

void enfilera(fila *minhaFila, char x){
    minhaFila->atras->prox=(apontador)malloc(sizeof(celula));
    minhaFila->atras->item=x;
    minhaFila->atras=minhaFila->atras->prox;
    minhaFila->atras->prox=NULL;
    minhaFila->tam++;
}

void desenfilera(fila *minhaFila){
    if(isVazia(*minhaFila)){
        puts("Fila Vazia");
    }else{
        apontador q = minhaFila->frente;
        minhaFila->frente = minhaFila->frente->prox;
        free(q);
        minhaFila->tam--;
    }
}

void imprime(fila minhaFila){
    apontador aux = minhaFila.frente;
    while(aux->prox!=NULL){
        printf("%c ",aux->item);
        aux = aux->prox;
    }
}

int main()
{
    fila mf;
    inicializa(&mf);
    enfilera(&mf,'a');
    enfilera(&mf,'b');
    enfilera(&mf,'c');
    enfilera(&mf,'d');
    desenfilera(&mf);
    enfilera(&mf,'e');
    imprime(mf);
    return 0;
}
