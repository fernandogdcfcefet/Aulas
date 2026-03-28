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



// codigo que coloco os elementos da lista em ordem. Ao ser inserido os elementos , os mesmos serão verificados e trocar em ordem.
 voidsort(TipoLista *ML) 
 {
 	
 	int ordena ( TipoLista*Lista,TipoItem x)
	  {
 	  	
 	 int aux;
 	 int Item a;
 	 int Item b;
 	  Insere ( TipoItem a, Tipo * Lista);
 	  Insere ( TipoItem b, Tipo * Lista);
 	  
      if ( TipoItem a >TipoItem b)
	   {
      	
      	Item a = Item b;
      	Item b = aux;
      	aux = a ; 
      	
 
 	
	   } 
     }
 	
 }
 //codigo que retira todos ocorrencias do item em parametro. 
 void RetiraTodos ( Tipo Lista * Lista , TipoItem Item) 
 {
 	 TipoApontador q;
 	if ( Vazia( Tipo Lista * Lista )||TipoItem ==NULL|| Item->Prox==NULL) {
 		return; 
}
 	
 	q =  p->Prox;  *Item  =  q->Item ;
    p->Prox  =  q->Prox ;
    if ( p->Prox == NULL )  Lista->Ultimo  = p;
    free (q);
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

int main()
{
    TipoLista ML;
    TipoItem item;
    FLVazia(&ML);
    item.Chave=1;Insere(item,&ML);
    item.Chave=7;Insere(item,&ML);
    item.Chave=13;Insere(item,&ML);
    item.Chave=5;Insere(item,&ML);
    item.Chave=9;Insere(item,&ML);
    Retira(ML.Primeiro->Prox,&ML,&item);
    imprime(ML);
    return 0;
}
