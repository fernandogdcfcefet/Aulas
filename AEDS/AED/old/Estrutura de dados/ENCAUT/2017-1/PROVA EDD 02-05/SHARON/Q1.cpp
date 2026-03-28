#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include <sys/time.h>
#define MAX 10

typedef int TipoChave;
typedef struct {
  TipoChave Chave;
} TipoItem;

typedef struct TipoCelula *TipoApontador;
typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;

typedef struct {
  TipoApontador Fundo, Topo;
  int Tamanho;
} TipoPilha;

void FPVazia(TipoPilha *Pilha)
{ Pilha->Topo = (TipoApontador) malloc(sizeof(TipoCelula));
  Pilha->Fundo = Pilha->Topo;
  Pilha->Topo->Prox = NULL;
  Pilha->Tamanho = 0;
}

int Vazia(TipoPilha Pilha)
{ return (Pilha.Topo == Pilha.Fundo); }

void Empilha(TipoItem x, TipoPilha *Pilha)
{ TipoApontador Aux;
  Aux = (TipoApontador) malloc(sizeof(TipoCelula));
  Pilha->Topo->Item = x;
  Aux->Prox = Pilha->Topo;
  Pilha->Topo = Aux;
  Pilha->Tamanho++;
}

void Desempilha(TipoPilha *Pilha, TipoItem *Item)
{ TipoApontador q;
  if (Vazia(*Pilha)) { printf("Erro: lista vazia\n"); return; }
  q = Pilha->Topo;
  Pilha->Topo = q->Prox;
  *Item = q->Prox->Item;
  free(q);  Pilha->Tamanho--;
}

int Tamanho(TipoPilha Pilha)
{ return (Pilha.Tamanho); }


void Imprime(TipoPilha pilha)
{
	TipoApontador i;
	i=pilha.Topo->Prox;
	
	if(pilha.Tamanho==0) printf("Pilha vazia");
	else
	{
		for(i=pilha.Topo->Prox; i != NULL; i=i->Prox)//while(i != NULL)
		{
			printf("\n %s",i->Item.Chave);
			//i=i->Prox;
		}
	
	}
}
void Palindromo(TipoPilha *pilha1)
{
	TipoPilha pilha2, pilha3,pilha4;
	
	TipoApontador i;
	i=pilha1->Topo->Prox;
	
	TipoItem guarda;
	
	FPVazia(&pilha2);
	FPVazia(&pilha3);
	FPVazia(&pilha4);
	
	while(i!=NULL)
	{
		Desempilha(pilha1,&guarda);
		Empilha(guarda,&pilha2);
		Empilha(guarda,&pilha3);
		i=i->Prox;
	}
	
	TipoApontador j;
	j=pilha3.Topo->Prox;
	
	while(j!=NULL)
	{
		Desempilha(&pilha3,&guarda);
		Empilha(guarda,&pilha4);
		j=j->Prox;
	}
	
	int x=0;
	TipoApontador k,l;
	k=pilha2.Topo->Prox;
	l=pilha4.Topo->Prox;
	
	while(k!=NULL && l!= NULL )
	{
		if(i->Item.Chave == l->Item.Chave) x++;
		k=k->Prox;
		l=l->Prox;
	}
	if(x==pilha4.Tamanho) printf("Palindromo");
	else printf("Nao palindromo");
}

int main()
{
	TipoItem a,b,c;
	a.Chave='o';
	b.Chave='v';
	c.Chave='o';
	TipoPilha p;
	FPVazia(&p);
	
	Empilha(a,&p);
	Empilha(b,&p);
	Empilha(c,&p);
	
	Imprime(p);
	
	Palindromo(&p);
	
	getch();
	return 0;
}

