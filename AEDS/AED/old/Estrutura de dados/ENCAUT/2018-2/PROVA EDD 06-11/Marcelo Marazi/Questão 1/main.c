#include <stdio.h>
#include <stdlib.h>

typedef  int  TipoChave;
typedef  struct  {
    TipoChave Chave;
}  TipoItem;

typedef  struct  TipoCelula  *TipoApontador;

typedef  struct  TipoCelula  {
    TipoItem  Item;
    TipoApontador  Prox;
}  TipoCelula;

typedef  struct  {
    TipoApontador  Primeiro ,  Ultimo;
}  TipoLista ;

void  FLVazia( TipoLista  * Lista ){
    Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
}

int  Vazia( TipoLista  Lista ){
    return  ( Lista . Primeiro ==  Lista . Ultimo ) ;
    }


void  InsereOrdenado(TipoItem  x ,	TipoLista  * Lista ){
    TipoApontador Aux;
    Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    while(Aux!= NULL){
        Lista->Ultimo  =  Lista->Ultimo->Prox ;
        Lista->Ultimo->Item  =  x;
        Lista->Ultimo->Prox  =  NULL;

    }
}

void  Retira(TipoApontador  p,	TipoLista  *Lista ,  TipoItem  *Item){
    TipoApontador  q;
    if ( Vazia(*Lista )	||	p == NULL	||	p->Prox == NULL){
        printf ( "  Erro : Lista  vazia  ou  posicao  nao  existe \n" ) ;
    return ;
    }
    q =  p->Prox;
    *Item  =  q->Item ;
    p->Prox  =  q->Prox ;
    if ( p->Prox == NULL ){
        Lista->Ultimo  = p;
        free (q);
    }
}

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;
    }
}

int main()
{

    TipoLista ML;
    TipoItem a;

    FLVazia(&ML);
    a.Chave = 9;
    InsereOrdenado(a,&ML);
    a.Chave = 8;
    InsereOrdenado(a,&ML);
    imprime(ML);
    system("pause");


    return 0;
}
