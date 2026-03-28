#include <stdio.h>
#include <stdlib.h>
#define NVertices 8

typedef  int  TipoChave;
typedef  struct  {
    TipoChave Chave;
    /*  outros  componentes  */
}  TipoItem;
typedef  struct  TipoCelula  *TipoApontador;
typedef  struct  TipoCelula  {
    TipoItem  Item;
    TipoApontador  Prox;
}  TipoCelula;

typedef  struct  {
    TipoApontador  Primeiro ,  Ultimo;
}  TipoLista;

typedef struct{
    TipoLista Lista [NVertices];
}TipoGrafo;

void FLVazia(TipoLista *Lista)
{ 	Lista->Primeiro  = (TipoApontador) malloc(sizeof(TipoCelula)) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
}

int  Vazia(TipoLista  Lista )
{  return  ( Lista.Primeiro ==  Lista . Ultimo ) ;  }

void  Insere(TipoItem  x ,	TipoLista  * Lista )
{  	Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Ultimo->Prox ;
    Lista->Ultimo->Item  =  x;
    Lista->Ultimo->Prox  =  NULL;
}

void  Retira(TipoApontador  p,	TipoLista  *Lista ,  TipoItem  *Item)
{	/*--O item  a  ser  retirado  e  o  seguinte  ao  apontado  por  p--*/
    TipoApontador  q;
    if ( Vazia(*Lista )	||	p == NULL	||	p->Prox == NULL){
        printf ( "  Erro : Lista  vazia  ou  posicao  nao  existe \n" ) ;
        return ;
    }
    q =  p->Prox;  *Item  =  q->Item ;
    p->Prox  =  q->Prox ;
    if ( p->Prox == NULL )  Lista->Ultimo  = p;
    free (q);
}

void iniciaGrafo(TipoGrafo *Grafo){
    int i;
    TipoLista L;
    FLVazia(&L);
    for(i=0; i<NVertices;i++){
        Grafo->Lista[i]=L;
    }

}

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%d->", aux->Item.Chave);
        aux=aux->Prox;
    }
}

void imprimeGrafo(TipoGrafo Grafo){
    int i;

    for(i=0;i<NVertices;i++){
        printf("%d: ",i);
        if(!Vazia(Grafo.Lista[i])){
            imprime(Grafo.Lista[i]);
        }
        printf("\n");
    }
}

void insereAresta(TipoGrafo *Grafo, int vertA, int vertB){
    TipoItem item;
    TipoLista L;
    L=Grafo->Lista[vertA-1];
    item.Chave=vertB;
    Insere(item,&L);
    Grafo->Lista[vertA-1]=L;
    item.Chave=vertA;
    L=Grafo->Lista[vertB-1];
    Insere(item,&L);
    Grafo->Lista[vertB-1]=L;
}

int main()
{
    TipoGrafo Grafo;
    iniciaGrafo(&Grafo);
    insereAresta(&Grafo,1,2);
    insereAresta(&Grafo,1,3);
    insereAresta(&Grafo,3,4);
    insereAresta(&Grafo,4,3);
    insereAresta(&Grafo,4,2);
    insereAresta(&Grafo,5,2);
    insereAresta(&Grafo,6,4);
    insereAresta(&Grafo,6,7);
    insereAresta(&Grafo,1,8);
    insereAresta(&Grafo,7,8);
    imprimeGrafo(Grafo);

    return 0;
}
