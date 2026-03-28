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

void Enfileira(TipoItem x, TipoPilha *Pilha1, TipoPilha *Pilha2)
{ if (Pilha1->Tras % MAXTAM + 1 == Pilha2->Frente)
  printf(" Erro   fila est  a  cheia\n");
  else { Pilha1->Item[Pilha1->Tras - 1] = x;
         Pilha2->Tras = Pilha2->Tras % MAXTAM + 1;
       }
}

void Desenfileira(TipoItem x, TipoPilha *Pilha1, TipoPilha *Pilha2)
{ if (Vazia(*Pilha1))
  printf("Erro fila esta vazia\n");
  else { *Item = Pilha1->Item[Fila1->Frente - 1];
         Pilha2->Frente = Pilha2->Frente % MAXTAM + 1;
       }
}

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

int main(int argc, char *argv[])
{
}

