#include <stdio.h>
#include <stdlib.h>

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

void Inverte(TipoPilha *Pilha){
  TipoApontador aux;
  aux->Item=Pilha->Topo->Item;
  Pilha->Topo->Item=Pilha->Fundo->Item;
  Pilha->Fundo->Item=aux->Item;

}

void Imprime(TipoPilha Pilha){
  TipoApontador aux;
  aux=(TipoApontador) malloc(sizeof(TipoCelula));
  aux=Pilha.Topo->Prox;
  while(aux!=NULL){
    printf("%d\n",aux->Item.Chave);
    aux=aux->Prox;
  }
}


int main()
{
  TipoPilha MP;
  FPVazia(&MP);
  TipoItem a,b,c,d;
  a.Chave=5;
  b.Chave=8;
  c.Chave=3;
  d.Chave=1;
  Empilha(a,&MP);
  Empilha(b,&MP);
  Empilha(c,&MP);
  Empilha(d,&MP);
  Imprime(MP);
  system("pause");
  Inverte(&MP);
  Imprime(MP);
}
