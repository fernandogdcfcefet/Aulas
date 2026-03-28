#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
typedef  char  TipoChave;
typedef  struct  {
int  Chave;
/*  outros  componentes  */
}  TipoItem;
typedef  struct  TipoCelula  *TipoApontador;
typedef  struct  TipoCelula  {
    TipoItem  Item;
    TipoApontador  Prox;
}  TipoCelula;
typedef  struct  {
    TipoApontador  Fundo,  Topo;
    int  Tamanho;
}  TipoPilha ;

void  FPVazia( TipoPilha  *Pilha)
{
    Pilha->Topo =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Pilha->Fundo =  Pilha->Topo;
    Pilha->Topo->Prox  = NULL;
    Pilha->Tamanho =  0;
}
int  Vazia( TipoPilha  Pilha)
{
    return  ( Pilha .Topo == Pilha .Fundo) ;
}

void  Empilha(TipoItem  x ,	TipoPilha  *Pilha)
{
    TipoApontador  Aux;
    Aux =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Pilha->Topo->Item  =  x;
    Aux->Prox  =  Pilha->Topo;
    Pilha->Topo = Aux; Pilha->Tamanho++;
}

void  Desempilha( TipoPilha  *Pilha ,  TipoItem  *Item)
{
    TipoApontador  q;
    if	( Vazia(*Pilha ) )  {
            printf ( "Erro :lista vazia\n");
            return ;
    }
    q =  Pilha->Topo;
    Pilha->Topo =  q->Prox ;
    *Item  =  q->Prox->Item ;
    free (q) ;
    Pilha->Tamanho--;
}

int  Tamanho( TipoPilha  Pilha)
{
    return  ( Pilha .Tamanho) ;
}

void  Imprime( TipoPilha  Lista )
{
    TipoApontador  Aux;
    Aux =  Lista.Topo->Prox ;
    while  (Aux  !=  NULL){
        printf ( "%d\n" ,  Aux->Item .Chave) ;
        Aux = Aux->Prox ;
    }
}

int Palindromo(TipoPilha pilha)
{
	TipoPilha p1,p2,p3;

	FPVazia(&p1);
	FPVazia(&p2);
	FPVazia(&p3);
	TipoApontador a,b,c,d;

	a=pilha.Topo;
	b=p1.Topo;
	c=p2.Topo;
	d=p3.Topo;

	TipoItem guarda;

	while(a->Prox != NULL)
	{
		Desempilha(&pilha,&guarda);
		Empilha(guarda,&p1);
		Empilha(guarda, &p2);
		a=a->Prox;
	}
	Imprime(pilha);/*
	Imprime(p1);
	Imprime(p2);
	*/
	while(b->Prox != NULL)
	{
		Desempilha(&p1,&guarda);
		Empilha(guarda,&p3);
	}


	while(d->Prox != NULL && c->Prox != NULL)
	{
		if(c->Item.Chave == d->Item.Chave) return 0;
		else return 1;
	}
}
int main()
{
	TipoPilha pilha;
	FPVazia(&pilha);
	TipoItem a,b,c;
	a.Chave='p';
	b.Chave='v';
	c.Chave='o';

	Empilha(a,&pilha);
	Empilha(b,&pilha);
	Empilha(c,&pilha);

printf("1 palindromo, 0 não palindromo: %d", Palindromo(pilha));

	getch();

    return 0;
}
