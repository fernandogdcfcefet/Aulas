#include <stdio.h>
#include <stdlib.h>

#define maxtam 8

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

typedef  struct  TipoCelula  {
    TipoItem  Item;
    TipoLista Adjacentes[maxtam];
}  TipoCelulaG;

typedef  struct  {
    TipoApontador  Primeiro ,  Ultimo;
}  TipoLista ;

typedef  struct  {
    TipoCelulaG Vertice[maxtam];
}  TipoGrafo;

void  FLVazia( TipoLista  * Lista )
{ 	Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
}
void  FGVazio( TipoGrafo  * Grafo )
{
    int i;
    for(i=0;i<maxtam;i++){
        FLVazia(Grafo->Vertice[i]->Adjacente[i]);
        Grafo->Vertice[i].item = 0;
    }
}
int  Vazia( TipoLista  Lista )
{  return  ( Lista . Primeiro ==  Lista . Ultimo ) ;  }

void  Insere(TipoItem  x ,	TipoLista  * Lista )
{  	Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Ultimo->Prox ;
    Lista->Ultimo->Item  =  x;
    Lista->Ultimo->Prox  =  NULL;
}

void insereAdj(TipoGrafo *grafo,TipoItem Item ,TipoLista Adj){
    while(Adj->ultimo->Prox != NULL){
       for(i=0;i<maxtam;i++){
        if(grafo->vertice[i].item == item)

        }
    }
}

void insereAresta(TipoGrafo *grafo, int vertA, int vertB){
    int i;
    for(i=0;i<maxtam;i++){
        if(grafo->vertice[i].item == vertA)
            Insere(vertB, grafo->vertice[i]->Adjacentes);
        if(grafo->vertice[i].item == vertB)
            Insere(vertA, grafo->vertice[i]->Adjacentes);
    }
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

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;
    }
}
//void imprimeMatriz(TipoGrafo grafo){
//    int i,j;
//    for(i=0;i<maxtam;i++){
//        while(grafo->Vertice[j]->Adjacente[j]){
//            if(grafo->Vertice[j]->Adjacente[j]== grafo->Vertice[i]->Item[i])
//                printf("%d",1);
//            else
//                printf("%d",0);
//        }
//    }
//}

int main()
{


    return 0;
}
