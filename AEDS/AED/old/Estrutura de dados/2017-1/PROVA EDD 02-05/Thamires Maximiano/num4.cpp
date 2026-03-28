#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
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

void ImprimePilha(TipoPilha Pilha) 
{
	if(Vazia(Pilha))
	{
		printf("Lista Vazia\n");
	}
	else
	{
		TipoApontador aux;
		aux=Pilha.Topo;
		while(aux->Prox!=NULL)
		{
			printf("%d\n", aux->Prox->Item.Chave);
			aux=aux->Prox;
		}
	}
}

void inicializaFila(TipoPilha *PilhaA, TipoPilha *PilhaB)
{
	FPVazia(PilhaA);
	FPVazia(PilhaB);
}

void Desenfileira(TipoPilha *PilhaA, TipoPilha *PilhaB, TipoItem x)
{
	TipoItem a;
	while(!Vazia(*PilhaA))
	{
		Desempilha(PilhaA,&a);
		Empilha(a,PilhaB);
	}
		printf("pilha A");
		ImprimePilha(PilhaA);
		printf("Pilha B");
		ImprimePilha(PilhaB);
}

int Tamanho(TipoPilha Pilha)
{ return (Pilha.Tamanho); }

int main(int argc, char *argv[])
{
	TipoPilha p1,p2;
	TipoItem x,y;
	FPVazia(&p1);
	FPVazia(&p2);
	Vazia(p1);
	Vazia(p2);
	x.Chave=1;
	y.Chave=2;
	
}

