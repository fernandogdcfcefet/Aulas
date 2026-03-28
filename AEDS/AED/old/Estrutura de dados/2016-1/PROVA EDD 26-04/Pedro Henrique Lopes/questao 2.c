#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#define MAXTAM 1000
typedef int TipoApontador;
typedef int TipoChave;
typedef struct{
    TipoChave Chave;
    TipoApontador Prox;
} TipoItem;

typedef struct{
    TipoItem Item[Maxtam];
    TipoApontador Frente, Tras;
} TipoFila;

void FFVazia(TipoFila *Fila){
    Fila->Frente = 1;
    Fila->Tras = Fila->Frente;
}

int Vazia(TipoFila Fila){
    return(Fila.Frente==Fila.Tras);
}




void Imprime(TipoFila *Fila){            //LETRA B
    TipoApontador aux = Fila->Frente;
    While(aux->Prox!=NULL){
    printf("%d",aux->Prox->item->Chave);
    aux=aux->Prox;
    }

}

int main()
{
    return 0;
}
