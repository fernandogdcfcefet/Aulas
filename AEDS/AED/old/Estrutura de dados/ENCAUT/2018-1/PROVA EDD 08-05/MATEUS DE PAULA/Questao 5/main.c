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

void InverteOrdem (TipoPilha *pilha)
{
    TipoPilha pilhaAux1, pilhaAux2;
    TipoItem itemAux;

    FPVazia(&pilhaAux1);
    FPVazia(&pilhaAux2);

    while(!Vazia(*pilha))
    {

        Desempilha(pilha, &itemAux);
        Empilha(itemAux, &pilhaAux1);
    }
    while(!Vazia(pilhaAux1))
    {

        Desempilha(&pilhaAux1, &itemAux);
        Empilha(itemAux, &pilhaAux2);
    }
    while(!Vazia(pilhaAux2))
    {

        Desempilha(&pilhaAux2, &itemAux);
        Empilha(itemAux, &pilha);
    }
}


int Tamanho(TipoPilha Pilha)
{ return (Pilha.Tamanho); }

int main()
{
    TipoPilha pilha;

    FPVazia(&pilha);

}

