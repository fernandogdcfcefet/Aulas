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
void  Retira(TipoApontador  p,	TipoLista  *Lista )
{	
    TipoApontador  q;
    if	( Vazia(*Lista )	||	p == NULL	||	p->Prox == NULL){
        printf ( "  Erro :	Lista  vazia  ou  posicao  nao  existe \n" ) ;
        return ;
    }
    q =  p->Prox; 
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
        printf ( "%d\n" ,  Aux->Item.Chave) ;
        Aux = Aux->Prox ;
    }
}
void RetiraTodos(TipoLista *lista,TipoItem *Item){
	
	TipoApontador aux=lista->Primeiro;
	
	while(aux!=NULL){
		if(aux->Item.Chave==Item->Chave){
			Retira(aux,lista);
			lista->Ultimo--;
		
		}
		aux=aux->Prox;
	}
	
		
}

	
	
	



int main()
{
    
    
    TipoLista lista;
	TipoItem item1,item2,item3,item4;
	item1.Chave=2;
	item2.Chave=5;
	item3.Chave=3;
	item4.Chave=4;
	FLVazia(&lista);
	Vazia(lista);
	Insere(item1,&lista);
	Insere(item2,&lista);
	Insere(item3,&lista);
	Insere(item4,&lista);
	
	Imprime(lista);
	RetiraTodos(&lista,&item1);
	printf("\n\n");
    Imprime(lista);
    
    
    
    
    
    
    
    
    
    
}
