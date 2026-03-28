#include <stdio.h>
#include <stdlib.h>
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
}  TipoLista ;

void  FLVazia( TipoLista  * Lista )
{ 	Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
}

int  Vazia( TipoLista  Lista )
{  return  ( Lista . Primeiro ==  Lista . Ultimo ) ;  }

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

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;
    }
}

void RetiraTodos (TipoLista *Lista, TipoItem Item) {
TipoApontador aux=Lista->Primeiro->Prox;
    while(aux!=NULL) {
        if (aux->Item.Chave == Item.Chave) {
        	Retira(aux , &*Lista, &Item);
		}
        aux=aux->Prox;
    }	

}

int main()
{
	TipoLista ML;
	TipoItem Item;
	FLVazia(&ML);
	
	Item.Chave = 1;
	Insere(Item, &ML);
	Item.Chave = 3;
	Insere(Item, &ML);
	Item.Chave = 3;
	Insere(Item, &ML);
	Item.Chave = 3;
	Insere(Item, &ML);
	Item.Chave = 3;
	Insere(Item, &ML);
	Item.Chave = 5;
	Insere(Item, &ML);
	
	//remove todos os "3"
	Item.Chave = 3;
	RetiraTodos(&ML, Item);
	imprime(ML);
    return 0;
}
