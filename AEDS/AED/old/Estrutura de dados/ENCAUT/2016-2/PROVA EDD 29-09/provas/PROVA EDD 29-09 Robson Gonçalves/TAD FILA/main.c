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
    int tam;
} TipoFila ;

void FFVazia(TipoFila *Fila )
{
    Fila->tam==0;
    //Fila->Frente = 1;
    //Fila->Tras = Fila->Frente;
}

int Vazia(TipoFila Fila )
{
    return (Fila.tam==0 /*Fila .Frente == Fila .Tras*/ ) ;
}

void Enfileira (TipoItem x , TipoFila *Fila )
{
    if ( Fila->tam >= MAXTAM-1 /*Fila->Tras % MAXTAM + 1 == Fila->Frente*/)
        printf ( " Erro f i la est a cheia\n" ) ;
    else {
        Fila->Item[ Fila->Tras - 1] = x;
        Fila->Tras++; /*Fila->Tras % MAXTAM + 1*/
        Fila->tam++;
    }
}

void Desenfileira(TipoFila *Fila , TipoItem *Item)
{
    if (Vazia(*Fila ) )
        printf ( "Erro f i la esta vazia\n" ) ;
    else {
        *Item = Fila->Item[ Fila->Frente - 1];
        Fila->Frente++ /*Fila->Frente % MAXTAM + 1*/;
        Fila->tam--;
    }
}
void Imprime(TipoFila fila){
    int aux;
    aux=fila.frente-1;
    while(aux!=fila.Tras-1){
        printf("%d\n",fila.Item.Chave);
        aux++;
    }
}

int main()
{
    return 0;
}
