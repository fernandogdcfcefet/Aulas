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

typedef struct{
	TipoApontador Primerio, Ultimo;
}TipoFila;
typedef struct{
	TipoApontador Primerio, Ultimo;
}TipoPilha;

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

void  Enfileira(TipoItem  x ,	TipoLista  * Lista )
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

TipoItem desenfileira(TipoLista *Lista, TipoItem *Item){
	if(Vazia(*Lista)){
		printf("vazia");
	//	return;
	}
	 TipoApontador q;
	 TipoApontador p=Lista->Primeiro->Prox;
	 *Item =p->Item;
	 Lista->Primeiro->Prox=p->Prox;
	 free(p);
	 
	 for(q=Lista->Primeiro,p=Lista->Primeiro->Prox;p!=NULL;q=p,p=p->Prox){
	 	q->Prox=NULL;
	 	Lista->Ultimo=q;
	 }
	
}

TipoItem desempilha(TipoLista *Lista, TipoItem *Item){
	TipoApontador q;
	TipoApontador p;
	 
	if(Vazia(*Lista)){
		printf("vazia");
		//return;
	}
	 
	
	 for(q=Lista->Primeiro,p=Lista->Primeiro->Prox;p!=Lista->Ultimo;q=p,p=p->Prox){
	 	
	 }
		*Item=p->Item;
		free(p);
		q->Prox=NULL;
		Lista->Ultimo=q;
}


void empilha2fila(TipoFila *p,TipoItem x){
	TipoFila p2;
	FLVazia(&p2);
	while(!Vazia(p)){
		Insere(&p2,desenfileira(p));
	}
	Insere(p,x);
	while(!Vazia(&p2)){
		Insere(p,desenfileira(&p2));
	}
}

TipoItem desempilha2fila(TipoFila *p){
	desenfileira(p,x);
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

    return 0;
}
