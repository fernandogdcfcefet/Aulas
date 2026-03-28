#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 5
typedef int TipoApontador;

typedef int TipoChave;

typedef struct {
    TipoChave Chave;
/* outros componentes */
} TipoItem;

typedef struct {
    TipoItem Item[MAXTAM] ;
    TipoApontador Frente , Tras;
} TipoFila ;

void FFVazia(TipoFila *Fila )
{
    Fila->Frente = 1;
    Fila->Tras = Fila->Frente;
}

int Vazia(TipoFila Fila )
{
    return ( Fila .Frente == Fila .Tras ) ;
}

void Enfileira (TipoItem x , TipoFila *Fila )
{
    if ( Fila->Tras % MAXTAM + 1 == Fila->Frente)
        printf ( " Erro f i la est a cheia\n" ) ;
    else {
        Fila->Item[ Fila->Tras - 1] = x;
        Fila->Tras = Fila->Tras % MAXTAM + 1;
    }
}

void Desenfileira(TipoFila *Fila , TipoItem *Item)
{
    if (Vazia(*Fila ) )
        printf ( "Erro f i la esta vazia\n" ) ;
    else {
        *Item = Fila->Item[ Fila->Frente - 1];
        Fila->Frente = Fila->Frente % MAXTAM + 1;
    }
}

void imprime(TipoFila fila){
    TipoApontador aux;
    aux = fila.Frente;
    while (aux != fila.Tras%MAXTAM){
        printf("%d ", fila.Item[(aux-1)%MAXTAM].Chave);
        aux = (aux+1)%MAXTAM;
    }
}
int main()
{
    TipoItem a;
    TipoFila fila;
    FFVazia(&fila);
    int i;
    for (i=0; i<4; i++){
        a.Chave = i+1;
        Enfileira(a, &fila);
    }
    imprime(fila);
    return 0;
}
