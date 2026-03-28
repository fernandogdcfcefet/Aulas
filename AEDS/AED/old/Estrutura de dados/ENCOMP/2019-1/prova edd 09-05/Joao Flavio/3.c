#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 10
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

typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Frente, Tras;
} TipoFila;

void FPVazia(TipoPilha *Pilha)
{ Pilha->Topo = (TipoApontador) malloc(sizeof(TipoCelula));
  Pilha->Fundo = Pilha->Topo;
  Pilha->Topo->Prox = NULL;
  Pilha->Tamanho = 0;
}

int Vazia(TipoPilha Pilha)
{ return (Pilha.Topo == Pilha.Fundo); }

void Epilha(TipoItem x, TipoPilha *Pilha)
{ TipoApontador Aux;
  Aux = (TipoApontador) malloc(sizeof(TipoCelula));
  Pilha->Topo->Item = x;
  Aux->Prox = Pilha->Topo;
  Pilha->Topo = Aux;
  Pilha->Tamanho++;
}

void Desepilha(TipoPilha *Pilha, TipoItem *Item)
{ TipoApontador q;
  if (Vazia(*Pilha)) { printf("Erro: lista vazia\n"); return; }
  q = Pilha->Topo;
  Pilha->Topo = q->Prox;
  *Item = q->Prox->Item;
  free(q);  Pilha->Tamanho--;
}

int Tamanho(TipoPilha Pilha)
{ return (Pilha.Tamanho); }

void Empilha(TipoItem x,TipoFila *Fila1,TipoFila *Fila2)
{
    TipoPilha p;
    TipoApontador aux=Fila1->Frente;
    while(aux!=NULL)
    {
        Epilha(x,&p);
        aux=aux->Prox;
    }
    aux=Fila2->Frente;
    while(aux!=NULL)
    {
        Epilha(x,&p);
        aux=aux->Prox;
    }
}
void Desempilha(TipoItem x,TipoFila *Fila1,TipoFila *Fila2)
{
    TipoPilha p;
    TipoApontador aux=Fila1->Frente;
    while(aux!=NULL)
    {
        Desepilha(&p,&x);
        aux=aux->Prox;
    }
    aux=Fila2->Frente;
    while(aux!=NULL)
    {
        Desepilha(&p,&x);
        aux=aux->Prox;
    }
}

int main()
{
}

