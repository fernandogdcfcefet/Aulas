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

int Tamanho(TipoPilha Pilha)
{ return (Pilha.Tamanho); }

void ImprimePilha(TipoPilha pilha) 
{
	if(Vazia(pilha))
	{
		printf("Lista Vazia\n");
	}
	else
	{
		TipoApontador aux;
		aux=pilha.Topo;
		while(aux->Prox!=NULL)
		{
			printf("%d\n", aux->Prox->Item.Chave);
			aux=aux->Prox;
		}
	}
}

void Palindromo(TipoPilha Pilha1)
{
	TipoPilha Pilha2, Pilha3, Pilha4;
	FPVazia(&Pilha2);
	FPVazia(&Pilha3);
	FPVazia(&Pilha4);
	int i;
	TipoItem guarda[MAX];
	
	for(i=0;i<MAX;i++)
	{
		Desempilha(&Pilha1,&guarda[i]);
		Empilha(guarda[i],&Pilha2);
		Empilha(guarda[i],&Pilha3);
	}
	
	ImprimePilha(Pilha2);
	ImprimePilha(Pilha3);
	
	for(i=0;i<MAX;i++)
	{	
		Desempilha(&Pilha2,&guarda[i]);
		Empilha(guarda[i],&Pilha4);
	}
	ImprimePilha(Pilha4);
	
	int x=0;
	for(i=0;i<MAX;i++)
	{
		if(Pilha3.Item[i].Chave==Pilha4.Item[i].Chave) x++;
	}
	if(x==MAX) printf("\nPalindromo");
	else printf("\nNao palindromo");
}

int main(int argc, char *argv[])
{
}

