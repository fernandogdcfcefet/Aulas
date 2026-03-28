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

//Procedimento para testar se as listas são iguais:
//se forem retorna 1, se não forem retorna 0
//OBS:Para listas de um mesmo tamanho

int LIguais(TipoLista a, TipoLista b)
{
	TipoApontador aux= a.Primeiro->Prox;
	
	TipoApontador aux2= b.Primeiro->Prox;
	
	
	while(aux != NULL)
	{
		if(aux->Item.Chave!= aux2->Item.Chave)
		{
			return 0;
		}
		aux=aux->Prox;
		aux2=aux2->Prox;
	}
	return 1;
	
}


int main()
{
	
	TipoLista a,b;
	
	TipoItem c, d, e, f, g;
	
	c.Chave=1;
	d.Chave=2;
	e.Chave=3;
	f.Chave=4;
	g.Chave=5;
	
	
	FLVazia(&a);
	
	printf("%d\n",Vazia(a));
	
	Insere(c, &a);
	Insere(d, &a);
	Insere(e, &a);
	Insere(f, &a);
	
	printf("%d\n",Vazia(a));

	printf("Lista a\n");
	imprime(a);
	
	FLVazia(&b);
	
	Insere(c, &b);
	Insere(d, &b);
	Insere(e, &b);
	Insere(g, &b);
	
	printf("Lista b\n");
	imprime(b);
	
	printf("Mostrando se as Listas são iguais: \n1 para iguais e 0 para diferentes.\nResposta: %d",LIguais(a, b));
	
    return 0;
}
