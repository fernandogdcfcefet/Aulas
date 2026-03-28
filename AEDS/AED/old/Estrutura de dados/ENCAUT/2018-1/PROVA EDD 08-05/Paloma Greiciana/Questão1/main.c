#include <stdio.h>
#include <stdlib.h>

typedef  int  TipoChave;
typedef  struct  {
    TipoChave x;
    TipoChave y;
}  TipoItem;
typedef  struct  TipoCelula  *TipoApontador;

typedef  struct  TipoCelula  {
    TipoItem  Item;
    TipoApontador  Prox;
}  TipoCelula;

typedef  struct  {
    TipoApontador  Primeiro ,  Ultimo;
}  TipoLista ;

void  FLVazia( TipoLista  * Lista )
{ 	Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
}

int  Vazia( TipoLista  Lista )
{  return  ( Lista . Primeiro ==  Lista . Ultimo ) ;  }

void  Insere(TipoItem  a ,	TipoLista  * Lista )
{  	Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Ultimo->Prox ;
    Lista->Ultimo->Item  =  a;
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

void imprime(TipoLista Lista){
    TipoApontador aux=Lista.Primeiro->Prox;
    while(aux!=NULL){
        printf("(%d , %d)\n", aux->Item.x, aux->Item.y);
        aux=aux->Prox;
    }
}


void Poligono(TipoLista *Lista){
  if(Lista->Primeiro==NULL || Lista->Primeiro->Prox==NULL || Lista->Primeiro->Prox->Prox==NULL || Lista->Primeiro->Prox->Prox->Prox==NULL){

    printf("A quantidade de vertices nao e suficiente para formar um poligono\n");
  }
  TipoApontador p;
  if(p==p->Prox){

    printf("Existem dois vertices iguais e, portanto, o poligono nao sera formado\n ");
  }
}



int main()
{
  TipoLista ML;
  FLVazia(&ML);
  TipoItem Item1, Item2, Item3, Item4;
  Item1.x=2;
  Item1.y=3;
  Item2.x=2;
  Item2.y=4;
  Item3.x=0;
  Item3.y=9;
  Item4.x=9;
  Item4.y=10;

  Insere(Item1,&ML);

  Insere(Item2, &ML);
  Poligono(&ML);

  Insere(Item3, &ML);

  Insere(Item4, &ML);

  Poligono(&ML);
  imprime(ML);
}
