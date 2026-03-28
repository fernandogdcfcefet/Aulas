#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef  char TipoChave;
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

void Palindromo(TipoPilha Pilha)
{
	TipoApontador aux, aux2, aux3;
	TipoPilha p1,p2;
	TipoItem guarda, item[Pilha.Tamanho];
	int i,c;

	aux=Pilha.Fundo->Prox;
	aux3=p2.Fundo->Prox;
	aux2=p1.Fundo->Prox;

	while(aux != NULL)//for(aux=Pilha.Fundo->Prox; aux!=NULL;aux=aux->Prox)
	{


		for(i=0;i<Pilha.Tamanho; i++)
		{
			Desempilha(&Pilha,&guarda);
			item[i]=guarda;
			Empilha(item[i],&p1);
			Empilha(item[i],&p2);
		}

		aux=aux->Prox;
	}/*
	Imprime(p1);
	Imprime(p2);*/

	while(aux2 != NULL && aux3 != NULL)//for(aux=Pilha.Fundo->Prox; aux!=NULL;aux=aux->Prox)
	{
		if(aux2->Prox->Item.Chave == aux->Prox->Item.Chave ) c=0;
		else c++;
		aux=aux->Prox;
	}
	if(c==0) printf("Palindromo");
	else printf("Nao palinmdromo");
}
int main()
{
	TipoPilha pilha;
	FPVazia(&pilha);

	TipoItem item1, item2, item3, item4;

	item1.Chave='o';Empilha(item1,&pilha);
    item2.Chave='v';Empilha(item2,&pilha);
    item3.Chave='o';Empilha(item3,&pilha);

    Imprime(pilha);

	Palindromo(pilha);
	system("pause");
    return 0;
}
