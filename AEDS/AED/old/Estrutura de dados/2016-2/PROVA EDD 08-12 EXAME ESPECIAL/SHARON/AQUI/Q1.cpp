#include <stdio.h>
#include <stdlib.h>
typedef  char  TipoChave;

typedef  struct  TipoCelula  *TipoApontador;

typedef  struct  {
    TipoApontador  Primeiro ,  Ultimo;
}  TipoLista ;

typedef  struct  {
    TipoChave Chave;
    int mat;
    float n1,n2, media;
    
}  TipoItem;
//typedef  struct  TipoLista  *TipoApontador1;

typedef  struct  TipoCelula  {
    TipoItem  Item;
    TipoApontador  Prox;
}  TipoCelula;




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


float media(float a, float b)
{
	return (a+b)/2;
}


Aluno Maior(TipoLista lista)
{
	TipoApontador aux=lista->Primeiro;
	
	float maior=media()
	
	while(aux->Prox != NULL)
	{
		
		aux=aux->Prox;
	}
}
*/
int main()
{
	TipoLista aluno;
	FLVazia(&aluno);
	
	TipoItem a,b,c;
	a.mat=1;
	a.Chave='a';
	a.n1=5
	a.n2=3;
	
	
    a.n1=5;
    a.n2=7;
    
	b.mat=2;
	b.Chave='b';
	b.n1=8;
	b.n2=3
	
	c.mat=3;
	c.Chave='c';
	c.n1=4;
	c.n2=9;
	
	Insere(a,&aluno);
	Insere(b,&aluno);
	Insere(c,&aluno);
	

    return 0;
}
