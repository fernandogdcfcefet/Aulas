#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>

#define TAM 10

typedef  char TipoChave;
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

typedef  struct 
{
    TipoLista hash[];
}  Hash ;


void InicializaHash(TipoLista *Hash)
{
	int i;
	for(i=0;i<TAM;i++)
	{
		FLVazia(&Hash[i]);
	}
}

int CalculaHash(char chave[])
{
	int i,q=0;
	for(i=0;i != '\0';i++)
	{
		q+=chave[i];
	}
	return q%10;
}

void InsereHash(TipoItem it,TipoLista *hash )
{
	int h=CalculaHash(it.Chave);
	int i=0;
	
	for(i=0;i<TAM; i++)
	{
		Insere(it,hash[h]);
	}	
}



typedef  struct 
{
    TipoLista hash[];
} Item ;




int main()
{
    TipoLista ML;
    TipoItem item;
    FLVazia(&ML);
    item1.Chave="sharon";Insere(item,&ML);
    item2.Chave="hsaron";Insere(item,&ML);
    item3.Chave="sos";Insere(item,&ML);
    item4.Chave="vida";Insere(item,&ML);
    
    imprime(ML);
    
    TipoLista hash[TAM];
    
    InicializaHash(hash);
    
    InsereHash(item1,hash);
    InsereHash(item2,hash);
	InsereHash(item3,hash);
    InsereHash(item4,hash);
    
    Insere
    return 0;
}
