#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAXTAM 100


//Adicionei uma Fila para ajudar a inverter a pilha




typedef struct {
  int Chave;
  /* outros componentes */
} TipoItem;
typedef struct {
  TipoItem Item[MAXTAM];
  int Frente, Tras;
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
}

int FVazia(TipoFila Fila)
{ return (Fila.Frente == Fila.Tras); }

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->Tras % MAXTAM + 1 == Fila->Frente)
  printf(" Erro   fila est  a  cheia\n");
  else { Fila->Item[Fila->Tras - 1] = x;
         Fila->Tras = Fila->Tras % MAXTAM + 1;
       }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
       }
}




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
{ 
  Pilha->Topo = (TipoApontador) malloc(sizeof(TipoCelula));
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

void Imprime(TipoPilha p)
{
	TipoApontador aux= p.Topo->Prox;
	while(aux!= NULL)
	{
		printf("%d\n",aux->Item);
		aux=aux->Prox;
	}
}

void Inverte(TipoPilha *p)
{
	TipoItem Item;
	TipoFila a;
	FFVazia(&a);
	int c= 0;
	
	while(Vazia(*p)==1)
	{
		Desempilha( p, &Item);
		Enfileira(Item, &a);
	}
	while(FVazia(a)==0)
	{
		Desenfileira(c, &a, &Item);
		Empilha(Item, p);
	}
}

int main()
{
	TipoPilha p;
	FPVazia(&p);
	
	TipoItem c, d, e, f, g;
	
	c.Chave=1;
	d.Chave=2;
	e.Chave=3;
	f.Chave=4;
	g.Chave=5;
	
	printf("%d\n",Vazia(p));
	
	Empilha(c, &p);
	Empilha(d, &p);
	Empilha(e, &p);
	Empilha(f, &p);
	
	printf("%d\n",Vazia(p));
	
	printf("Imprimindo pilha:\n");
	Imprime(p);
	
	printf("%d",Vazia(p));
	
	Inverte(&p);
	
	printf("Imprimindo pilha:\n");
	
	Imprime(p);
	
}

