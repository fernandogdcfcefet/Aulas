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


void troca(TipoLista *Lista, TipoApontador a, TipoApontador b){
	TipoItem aux;
	aux=a->Item;
	a->Item=b->Item;
	b->Item=aux;
}

void bubblesort(TipoLista *Lista){
	TipoApontador i,j;
	for(j=Lista->Primeiro->Prox;j!=NULL;j=j->Prox){
		for(i=Lista->Primeiro->Prox;i!=Lista->Ultimo;i=i->Prox){
		if(i->Item.Chave>i->Prox->Item.Chave){
			troca(Lista,i,i->Prox);
		}
	}
}
}


//void retiratodos(tipolista *lista, tipoitem *item){
	//if(vazia(*lista)){
	//	printf("vazia");
	//	return;
//	}
//	tipoapontador q=lista->primeiro;
	//tipopoantador p=lista->primeiro->proximo;

//	while(p!=NULL){
	//	if(p->item.chave==item->chave){
		//	q->proximo=p->proximo;
		//	free(p);
		//	p=q->proximo;
	//	}
	//	else{
		//	q=p;
		//	p=p->proximo;
	//	}
	//}
//}

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

    bubblesort(&ML);


    imprime(ML);
    return 0;
}
