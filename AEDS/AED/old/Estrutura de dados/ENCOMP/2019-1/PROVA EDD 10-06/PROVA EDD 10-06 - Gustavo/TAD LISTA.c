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
    TipoApontador  Prox, Ant; ///adiciona um apontador para o anterior
}  TipoCelula;

typedef  struct  {
    TipoApontador  Primeiro ,  Ultimo;
}  TipoLista ;

void  FLVazia( TipoLista  * Lista ){
	Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
    Lista->Primeiro->Ant  =  NULL; ///o anterior recebe nulo
}

int  Vazia( TipoLista  Lista )
{  return  ( Lista . Primeiro ==  Lista . Ultimo ) ;  }

void  Insere(TipoItem  x ,	TipoLista  * Lista ){
	Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    if(Vazia(*Lista))
		Lista->Ultimo->Prox->Ant = NULL;
	else
		Lista->Ultimo->Prox->Ant = Lista->Ultimo; ///o anterior do novo item recebe o ultimo
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
    q =  p->Prox;
	*Item  =  q->Item ;
    p->Prox  =  q->Prox ;
    if(q->Prox != NULL)
    	q->Prox->Ant = q->Ant;
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

void imprimeSUBSEQUENCIA(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
    	if(aux->Ant==NULL){

			printf("null");
        	printf(" < %d > %d\n", aux->Item.Chave, aux->Prox->Item.Chave);
        }else if(aux->Prox==NULL){
        	printf("%d < %d > ", aux->Ant->Item.Chave, aux->Item.Chave);
        	printf("null\n");
        }else
        	printf("%d < %d > %d\n", aux->Ant->Item.Chave, aux->Item.Chave, aux->Prox->Item.Chave);
		aux=aux->Prox;
    }
}

int main()
{
	TipoLista ML;
	TipoItem x;

	FLVazia(&ML);

	int i;
	for(i=0;i<4;i++)
	{
		x.Chave = i;
		Insere(x, &ML);
	}
	imprimeSUBSEQUENCIA(ML); //testa a implementacao de lista encadeada

	return 0;
}
