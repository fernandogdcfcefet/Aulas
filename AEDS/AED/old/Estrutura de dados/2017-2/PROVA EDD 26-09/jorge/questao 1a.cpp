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





void RetiraTodos(TipoLista *Lista, TipoItem *Item){
	if(Vazia(*Lista)){
		printf("vazia");
		return;
	}
	TipoApontador q=Lista->Primeiro;
	TipoApontador p=Lista->Primeiro->Prox;

	while(p!=NULL){
		if(p->Item.Chave==Item->Chave){
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
    FLVazia(&ML);
    TipoItem item;
    item.Chave=1;
    Insere(item,&ML);
    item.Chave=2;
    Insere(item,&ML);
    item.Chave=1;
    Insere(item,&ML);
    item.Chave=3;
    Insere(item,&ML);
    item.Chave=4;
    Insere(item,&ML);
    item.Chave=1;
    Insere(item,&ML);


    RetiraTodos(&ML,&item);
    imprime(ML);
    return 0;
}
