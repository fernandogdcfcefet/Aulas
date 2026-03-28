#include <stdio.h>
#include <stdlib.h>

typedef struct TipoVertice *Apontador;

typedef struct{
    int x,y;
}TipoCoordenadas;

typedef struct TipoVertice{
    TipoCoordenadas C;
    Apontador Prox;
}Vertice;

typedef struct{
    Apontador Primeiro, Ultimo;
}TipoPoligono;

void FPoliVazio(TipoPoligono *P){
    P->Primeiro = (Apontador)malloc(sizeof(Vertice));
    P->Ultimo = P->Primeiro;
    P->Primeiro->Prox = NULL;
}

void InserirVertices(TipoPoligono *P, TipoCoordenadas C){
    P->Ultimo->Prox = (Apontador)malloc(sizeof(Vertice));
    P->Ultimo = P->Ultimo->Prox;
    P->Ultimo->C = C;
    P->Ultimo->Prox = NULL;
}

void RemoverVertice(Apontador Pos,TipoPoligono *P, TipoCoordenadas *C){
    Apontador Aux;

    Aux = Pos->Prox;
    *C = Aux->C;
    Pos->Prox = Aux->Prox;
    if(Pos->Prox == NULL){
        P->Ultimo = Pos;
    }
    free(Aux);
}

void DesenharPoligono(TipoPoligono P){
    Apontador Aux;

    Aux = P.Primeiro->Prox;

    while(Aux != NULL){
        printf("( %d, %d ), ",Aux->C.x,Aux->C.y);
        Aux = Aux->Prox;
    }
}


int main()
{

    TipoPoligono MP;
    TipoCoordenadas C;

    FPoliVazio(&MP);
    C.x = 1;
    C.y = 1;
    InserirVertices(&MP,C);
    C.x = 1;
    C.y = 2;
    InserirVertices(&MP,C);
    RemoverVertice(MP.Primeiro,&MP,&C);
    DesenharPoligono(MP);

    return 0;
}
