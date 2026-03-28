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

void RetiraTodos(TipoLista *Lista, TipoItem Item)
{
	TipoApontador aux = Lista->Primeiro;
	TipoApontador q;

	do
	{
		if(aux->Prox->Item.Chave == Item.Chave)
		{
			q = aux->Prox;
			aux->Prox = q->Prox;
			free(q);
		}
		Lista->Ultimo = aux;
		aux = aux->Prox;
	}while(aux != NULL);
}

void InsereOrdenado(TipoItem x, TipoLista *Lista)
{
	TipoApontador aux = Lista->Primeiro;

	if(Vazia(*Lista))//se a lista estiver vazia utiliza a função que já existe
	{
		Insere(x, Lista);
		return;
	}

	if(Lista->Ultimo->Item.Chave < x.Chave)//se o ultimo item for menor insere o novo item por ultimo
	{
		TipoApontador novo = (TipoApontador)  malloc( sizeof ( TipoCelula ) );
		novo->Item = x;
		novo->Prox = NULL;
		Lista->Ultimo->Prox = novo;
		Lista->Ultimo = novo;
		return;
	}

	do//insere o item no meio da lista
	{
		if(aux->Prox->Item.Chave > x.Chave || aux->Prox==NULL)
		{
			TipoApontador novo = (TipoApontador)  malloc( sizeof ( TipoCelula ) );
			novo->Item = x;
			novo->Prox = aux->Prox;
			aux->Prox = novo;

			if(novo->Prox==NULL)
				Lista->Ultimo = novo;

			return;
		}
		aux = aux->Prox;
	}while(aux != NULL);
}

int main()
{
	TipoLista ML;

	TipoItem x;

	FLVazia(&ML);

	x.Chave = 5;
	Insere(x, &ML);

	x.Chave = 2;
	Insere(x, &ML);

	x.Chave = 3;
	Insere(x, &ML);

	x.Chave = 5;
	Insere(x, &ML);

	printf("Vetor Inicial:\n");
	imprime(ML);

	printf("Retira todos %d:\n", x.Chave);
	RetiraTodos(&ML, x);
	imprime(ML);

	printf("Insere ordenado:\n");
	InsereOrdenado(x, &ML);
	x.Chave = 4;
	InsereOrdenado(x, &ML);
	imprime(ML);


    return 0;
}
