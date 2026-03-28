
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


typedef  int  TipoChave;

typedef  struct  { TipoChave Chave;
int cod;
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

void RetiraTodos(TipoItem Item, TipoLista *Lista)
{
	TipoItem guarda;
	TipoApontador Aux=Lista->Primeiro;

	
	while(Aux!=NULL)
	{
		if(Aux->Prox->Item.cod==Aux->Prox->Prox->Item.cod)
		{
			Retira(Aux, Lista, &guarda);
			Aux++;
		}
		else
		{
			Aux++;	
		}
		
	}
}
void  Imprime( TipoLista  Lista )
{
    TipoApontador  Aux;
    Aux =  Lista . Primeiro->Prox ;
    if(Vazia(Lista)) printf("Lista vazia");
    else{
	
    while  (Aux  !=  NULL){
    	printf("\n--\n");
        printf ( "Chave:%d\n" ,  Aux->Item .Chave) ;
        printf ( "Mat:%d\n" ,  Aux->Item.cod) ;
        Aux = Aux->Prox ;
    }
}
}

int main() //repetição de acordo com o cod
{
	
	TipoItem it1;
	it1.Chave=0;
	it1.cod=0;
	
	TipoItem it2;
	it1.Chave=1;
	it1.cod=1;
	
	TipoItem it3;
	it1.Chave=0;
	it1.cod=0;
	
	TipoLista ml;
	FLVazia(&ml);
	
	Imprime(ml);
	
	Insere(it1,&ml);
	Insere(it2,&ml);
	Insere(it3,&ml);
	
	Imprime(ml);
	
	RetiraTodos(it1,&ml);
	
	//Imprime(ml);
	
	
	
	
	getch();
	return 0;
}
