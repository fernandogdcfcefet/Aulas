#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define tam 3 //de acordo com a quantidade de itens
typedef  char*  TipoChave;
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

typedef struct
{
	TipoLista lista[tam];
}Hash;

void FHVazia(Hash *lista[tam])
{
	int i;

	for(i=0;i<tam;i++)
	{
		FLVazia(&lista[i]);
	}
}

int CalculaPos(char* chave)
{
	int i,q=0;
	for(i=0;i!='\0';i++)
	{
		q+=chave[i];
	}
	return q%10;
}

void InsereNoHash(TipoItem it,TipoLista *lista[])
{
	int x=CalculaPos(it.Chave);
	int i;

	for(i=0;i<tam;i++)
	{
		Insere(it,&lista[x]);
	}


}

int Esta(TipoItem it, TipoLista lista[])
{
	int x= CalculaPos(it.Chave);
	int i;
	TipoApontador aux;=lista[].

	while(aux->Prox != NULL)
	{
		if(strcmp(it.Chave==aux->Prox->Item.Chave)==1)
	}
}*/
int main()
{
	Hash lista;

	TipoItem a,b,c;
	a.Chave="sharon";
	b.Chave="sharno";

	FHVazia(&lista);

	InsereNoHash(a,&lista);
	InsereNoHash(b,&lista);
	InsereNoHash(c,&lista);


    return 0;
}
