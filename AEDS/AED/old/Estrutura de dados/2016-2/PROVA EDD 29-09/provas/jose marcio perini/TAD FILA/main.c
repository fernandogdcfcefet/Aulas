#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 5

typedef int Apontador;

typedef int Chave;

typedef struct {
    Chave Chave;

}Item;

typedef struct {
    Item Item[MAXTAM] ;
    Apontador Frente , Tras;
}Fila ;

void FFVazia(Fila *Fila )
{
    Fila->Frente = 1;
    Fila->Tras = Fila->Frente;
}

int Vazia(Fila Fila )
{
    return ( Fila .Frente == Fila .Tras ) ;
}

void Enfileira (Item x , Fila *Fila )
{
    if ( Fila->Tras % MAXTAM + 1 == Fila->Frente)
        printf ( " Erro f i la est a cheia\n" ) ;
    else {
        Fila->Item[ Fila->Tras - 1] = x;
        Fila->Tras = Fila->Tras % MAXTAM + 1;
    }
}

void Desenfileira(Fila *Fila , Item *Item)
{
    if (Vazia(*Fila ) )
        printf ( "Erro f i la esta vazia\n" ) ;
    else {
        *Item = Fila->Item[ Fila->Frente - 1];
        Fila->Frente = Fila->Frente % MAXTAM + 1;
    }
}

void Imprimefila(Fila *Fila){

 Apontador aux;
 aux = Fila->Frente;

 while(aux->prox != NULL){

    printf(" %d " , aux->Item.Chave);
    aux = aux->prox;
 }

 int i;

 for(i = 0 ; i < 5 ; i = Fila->Frente % MAXTAM + 1){

    printf(" %d " , Fila->Item[aux]);

 }

}

int main()
{

Fila Fila1;
FFVazia(&Fila1);
Vazia(Fila1);

Item Item1 = {1};
Item Item2 = {2};
Item Item3 = {3};
Item Item4 = {4};
Item Item5 = {5};

Enfileira(Item1 , &Fila1);
Enfileira(Item2 , &Fila1);
Enfileira(Item3 , &Fila1);
Enfileira(Item4 , &Fila1);
//Enfileira(Item1 , &Fila1);

Imprimefila(&Fila1);


return 0;
}
