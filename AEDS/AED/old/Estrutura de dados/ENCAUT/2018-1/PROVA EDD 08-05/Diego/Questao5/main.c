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
void InverterPosicao(TipoPilha *Pilha){
    TipoPilha P;
    TipoApontador Aux;
    TipoItem Item;

    Aux = Pilha->Topo->Prox;

    while(Aux != NULL){
        Desempilha(Pilha,&Item);
        Empilha(Item,&P);
        Aux = Aux->Prox;
    }

    Aux = P.Topo->Prox;

    while(Aux != NULL){

        Aux = Aux->Prox;
    }
}

void Imprime(TipoPilha Pilha){
    TipoApontador Aux;

    Aux = Pilha.Topo->Prox;

    while(Aux != NULL){
        printf(" %d\n",Aux->Item.Chave);
        Aux = Aux->Prox;
    }
}

int Tamanho(TipoPilha Pilha)
{ return (Pilha.Tamanho); }

int main()
{
    TipoPilha MP;
    TipoItem Item;

    FPVazia(&MP);
    Item.Chave = 1;
    Empilha(Item,&MP);
    Item.Chave = 2;
    Empilha(Item,&MP);
    Item.Chave = 3;
    Empilha(Item,&MP);
    Item.Chave = 4;
    Empilha(Item,&MP);
    Item.Chave = 5;
    Empilha(Item,&MP);
    Item.Chave = 6;
    Empilha(Item,&MP);
    InverterPosicao(&MP);
    Imprime(MP);

    return 0;
}
