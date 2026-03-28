#include <stdio.h>
#include <stdlib.h>

typedef  int  TipoChave;

typedef  struct  { TipoChave Chave;
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

void  FLVazia( TipoLista   *Lista )
{
    Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
}


void InsereOrdenado(TipoLista *lista,TipoItem x){
	
	TipoApontador novo ;
   	TipoApontador  p=lista->Primeiro->Prox ;
	TipoApontador  q = lista ->Primeiro;
	while(p!=NULL){//for o primeiro elemento da lista 
		
		if(p->Item.Chave <x.Chave){//for elemento menor que o primeiro elemento 
		novo=(TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
		novo->Item=x;
		q->Prox=novo;
		novo->Prox=p;
		
	}
	
	}
	
	p=(TipoApontador) malloc( sizeof ( TipoCelula ) ) ;
		p =  p->Prox ;
        p->Item  =  x;
        p->Prox  =  NULL;
	
	
	
	
	
	
	
	
	}
	
	


int  Vazia( TipoLista  Lista )
{
    return  ( Lista . Primeiro ==  Lista . Ultimo ) ;
}

void  Insere(TipoItem  x ,	TipoLista  * Lista )
{
    Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Ultimo->Prox ;
    Lista->Ultimo->Item  =  x;
    Lista->Ultimo->Prox  =  NULL;
}
void  Retira(TipoApontador  p,	TipoLista  *Lista ,  TipoItem  *Item)
{	/*--O item  a  ser  retirado  e  o  seguinte  ao  apontado  por  p--*/
    TipoApontador  q;
    if	( Vazia(*Lista )	||	p == NULL	||	p->Prox == NULL){
        printf ( "  Erro :	Lista  vazia  ou  posicao  nao  existe \n" ) ;
        return ;
    }
    q =  p->Prox;  *
    Item  =  q->Item ;
    p->Prox  =  q->Prox ;
    if	( p->Prox == NULL )
        Lista->Ultimo  = p;
    free (q);
}
void  Imprime( TipoLista  Lista )
{
    TipoApontador  Aux;
    Aux =  Lista . Primeiro->Prox ;
    while  (Aux  !=  NULL){
        printf ( "%d\n" ,  Aux->Item .Chave) ;
        Aux = Aux->Prox ;
    }
}

int main()
{
    TipoLista lista;
	TipoItem item1,item2,item3,item4;
	item1.Chave=2;
	item2.Chave=1;
	item3.Chave=3;
	item4.Chave=4;
	FLVazia(&lista);
	Vazia(lista);
	
	InsereOrdenado(&lista,item2);
	InsereOrdenado(&lista,item1);
	
	Imprime(lista);
	//RetiraTodos(&lista,&item1);
	printf("\n\n");
    Imprime(lista);
    
}
