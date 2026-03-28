#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
//#include <sys/time.h>
#define MAX 10

typedef int TipoChave;
typedef struct {
  int Chave;
  /* outros componentes */
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

void Enfileira(TipoItem x, TipoPilha *p1, TipoPilha *p2)
{
	Empilha(x,p1);
}

void Desenfileira(TipoItem *x,TipoPilha *p1)
{
	TipoPilha p2;
	FPVazia(&p2);
	Desempilha(p1,x);
	Empilha(x,&p2);
	Desempilha(&p2,&x)
}

void Imprime(TipoPilha pilha)
{
	TipoApontador i;
	i=pilha.Topo->Prox;
	
	if(pilha.Tamanho==0) printf("Pilha vazia");
	else
	{
		while(i != NULL)
		{
			printf("\n %s",i->Item.Chave);
			i=i->Prox;
		}
	
	}
}
int Tamanho(TipoPilha Pilha)
{ return (Pilha.Tamanho); }

int main(int argc, char *argv[])
{
	TipoPilha p1;
	FPVazia(&p1)
	TipoItem a,b,c;
	
	a.Chave=3;
	b.Chave=2;
	c.Chave=1;
	
	Enfileira(a,&p1);
	Enfileira(b,&p1);
	Enfileira(c,&p1);
	
	Imprime(p1);
	
	TipoItem guarda;
	
	Desenfileira(&p1,&guarda)
	Imprime(p1);
	
}

