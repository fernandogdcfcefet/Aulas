#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 1000

typedef int TipoApontador;
typedef int TipoChave;

typedef struct{
    TipoChave Chave;
}TipoItem;

typedef struct{
    TipoItem Item[MAXTAM];
    TipoApontador Frente, Tras;
}TipoFila;

void FFVazia(TipoFila *Fila){
    Fila->Frente = 1;
    Fila->Frente = Fila->Tras;
}

int Vazia(TipoFila Fila){
    return(Fila.Frente == Fila.Tras);
}

void Enfileira(TipoItem x, TipoFila *Fila){
    if(Fila->Tras % MAXTAM + 1 == Fila->Frente){
        if(Fila->Tras == MAXTAM - 1){
            Fila->Item[Fila->Tras-1] = x;
            Fila->Tras = Fila->Tras%MAXTAM+1;}
        else{
            printf("Fila esta cheia");
        }
    }
    else{
        Fila->Item[Fila->Tras-1] = x;
        Fila->Tras = Fila->Tras%MAXTAM+1;
    }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item){
    if(Vazia(*Fila))
        printf("Erro fila esta vazia");
    else{
        *Item = Fila->Item[Fila->Frente-1];
        Fila->Frente = Fila->Frente%MAXTAM+1;
    }
}

void Imprime(TipoFila Fila){
    int i;
    for(i=0;i<MAXTAM;i++){
        printf("O elemento %d da fila e %d \n", i, Fila.Item[i].Chave);
    }
}
