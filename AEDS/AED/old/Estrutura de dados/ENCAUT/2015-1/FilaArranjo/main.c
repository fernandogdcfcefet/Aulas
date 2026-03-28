#include <stdio.h>
#include <stdlib.h>
#define TAM 10
typedef struct{
    int vet[TAM];
    int primeiro, ultimo;
}Lista;

void esvazia(Lista *minhaLista){
    minhaLista->primeiro=0;
    minhaLista->ultimo=minhaLista->primeiro;
}

int verificaVazia(Lista minhaLista){
    return minhaLista.ultimo==minhaLista.primeiro;
}

void insere(Lista *minhaLista, int x){
    if(minhaLista->ultimo==TAM){
        printf("Lista cheia\n");
    }else{
        minhaLista->vet[minhaLista->ultimo]=x;
        minhaLista->ultimo++;
    }
}

void imprime(Lista minhaLista){
    int aux;
    if(verificaVazia(minhaLista))printf("Lista Vazia\n");
    for(aux=minhaLista.primeiro;aux<minhaLista.ultimo;aux++){
        printf("%d ",minhaLista.vet[aux]);
    }
}
int main()
{
    Lista ML;
    esvazia(&ML);
//    insere(&ML,2);
//    insere(&ML,20);
//    insere(&ML,0);
//    insere(&ML,3);
//    insere(&ML,5);
//    insere(&ML,6);
//    insere(&ML,8);
//    insere(&ML,90);
//    insere(&ML,34);
//    insere(&ML,4);
//    insere(&ML,1);

    imprime(ML);
    return 0;
}
