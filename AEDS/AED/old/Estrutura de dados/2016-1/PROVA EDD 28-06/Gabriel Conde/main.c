#include <stdio.h>
#include <stdlib.h>
#define N 2
typedef  int  TipoChave;
typedef  struct  {
    TipoChave Vertice;
    /*  outros  componentes  */
}  TipoItem;
typedef  struct  TipoCelula  *TipoApontador;
typedef  struct  VA  *TipoApontadorVA;
typedef  struct  TipoCelula  {
    TipoItem  Item;
    TipoChave Grau;
    TipoApontadorVA  VA;
    TipoApontador  Prox;
}  TipoCelula;

typedef  struct  VA{
    TipoItem  Item;
    TipoApontadorVA  VA;
}  VA;

typedef  struct  {
    TipoApontador  Primeiro ,  Ultimo;
}  TipoGrafo ;

void InsereAresta(TipoGrafo *Grafo, int vertA, int vertB){
    TipoApontador aux=Grafo->Primeiro->Prox;
    TipoApontadorVA aux1=Grafo->Primeiro->VA;
    TipoApontadorVA novoVA;
    novoVA->VA = NULL;
    novoVA->Item.Vertice = vertB;
    while(aux!=NULL){
        if(aux->Item.Vertice == vertA){
        while(aux1!=NULL){
            if(aux1->VA == NULL){
                aux1->VA = novoVA;
            }
            aux1=aux1->VA;
            }
        }
    aux=aux->Prox;
    aux1=aux1->VA;
    }
}

void imprimeMatriz(TipoGrafo Grafo){
    TipoApontador aux=Grafo.Primeiro->Prox;
    TipoApontadorVA aux1=Grafo.Primeiro->VA;
    int i = 0;
    while(aux!=NULL){
        printf("%d ", aux->Item.Vertice);
        while(aux1!=NULL){
            for(i=0;i<N;i++){
                if(aux1->Item.Vertice !=0)
                    printf("%d ", aux1->Item.Vertice);
                else printf("0 ");
            }
            aux1=aux1->VA;
        }
        printf("\n ");
        aux=aux->VA;
    }
}

void iniciaGrafo(TipoGrafo *Grafo){
    TipoApontadorVA aux1=Grafo->Primeiro->VA;
    int i = 0;
    while(i<N){

    }
}



}
