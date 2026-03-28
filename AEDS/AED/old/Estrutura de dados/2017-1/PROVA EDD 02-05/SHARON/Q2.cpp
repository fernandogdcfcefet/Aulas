#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

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
/*
void Imprime(TipoPilha pilha)
{
	TipoApontador i;
	i=pilha.Topo->Prox;
	
	while(i != NULL)
	{
		printf("\n %d",i->Item.Chave);
		i=i->Prox;
	}
}
*/

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
void ImprimeTres(TipoPilha p1, TipoPilha p2, TipoPilha p3)
{
	Imprime(p1);
	printf("\n\n");
	Imprime(p2);
	printf("\n\n");
	Imprime(p3);
	printf("\n\n");
}
void TorreDeHanoi()
{
	TipoPilha p1,p2,p3;
	
	FPVazia(&p1);
	FPVazia(&p1);
	FPVazia(&p1);
	
	TipoItem a,b,c;
	
	a.Chave=3;
	b.Chave=2;
	c.Chave=1;
	
	Empilha(a,&p1);
	Empilha(b,&p1);
	Empilha(c,&p1);
	Imprime(p1);
	
	TipoItem guarda;
	
	Desempilha(&p1,&guarda);
	
	Empilha(guarda,&p3);
	ImprimeTres(p1,p2,p3);

	Desempilha(&p1,&guarda);
	ImprimeTres(p1,p2,p3);
	Empilha(guarda,&p2);
	ImprimeTres(p1,p2,p3);
	Desempilha(&p3,&guarda);
	ImprimeTres(p1,p2,p3);
	Empilha(guarda,&p2);
	ImprimeTres(p1,p2,p3);
	Desempilha(&p1,&guarda);
	ImprimeTres(p1,p2,p3);
	Empilha(guarda,&p3);
	ImprimeTres(p1,p2,p3);
	Desempilha(&p2,&guarda);
	ImprimeTres(p1,p2,p3);
	Empilha(guarda,&p1);
	ImprimeTres(p1,p2,p3);
	Desempilha(&p2,&guarda);
	ImprimeTres(p1,p2,p3);
	Empilha(guarda,&p3);
	ImprimeTres(p1,p2,p3);
	Desempilha(&p1,&guarda);
	ImprimeTres(p1,p2,p3);
	Empilha(guarda,&p3);
}

int main()//(int argc, char *argv[])
{
	TorreDeHanoi();
	
	getch();
	return 0;
}
