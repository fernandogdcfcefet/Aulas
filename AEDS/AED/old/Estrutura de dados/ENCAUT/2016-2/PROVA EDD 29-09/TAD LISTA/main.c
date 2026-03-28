#include <stdio.h>
#include <stdlib.h>

typedef  int  TipoChave;

typedef  struct TipoItem {
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
void RetiraTodos(TipoLista*lista , TipoItem item){

	if(Vazia(*lista)){
		printf(" erro");
		return;
	}

	TipoApontador q=lista->Primeiro;
	TipoApontador p=lista->Primeiro->Prox;
	while(p!=NULL){
		if(p->Item.Chave==item.Chave){
			q->Prox=p->Prox;
			free(p);
			p=q->Prox;
		}
		else{
			q=p;
			p=p->Prox;
		}
	}
}

void insereOrdenado(TipoItem x,TipoLista *lista){
	TipoApontador aux;
	TipoApontador anterior=lista->Primeiro;
	TipoApontador novo=(TipoApontador) malloc(sizeof(TipoCelula));
	novo->Item.Chave=x.Chave;
	for(aux=lista->Primeiro->Prox;aux!=NULL;aux=aux->Prox){
		if(x.Chave<aux->Item.Chave){
			novo->Prox=aux;
			anterior->Prox=novo;
		}
		anterior=aux;
	}
}

int main()
{

    TipoLista ML;
    TipoItem item;
    FLVazia(&ML);

    item.Chave=11;
    insereOrdenado(item,&ML);
    item.Chave=2;
    insereOrdenado(item,&ML);
    item.Chave=3;
    insereOrdenado(item,&ML);
    item.Chave=10;
    insereOrdenado(item,&ML);
    item.Chave=4;
    insereOrdenado(item,&ML);
    item.Chave=15;
    insereOrdenado(item,&ML);

    Imprime(ML);
    puts("");

//    RetiraTodos(&ML,item);
    Imprime(ML);

    return 0;
}
