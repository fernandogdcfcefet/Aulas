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

void Desenfilera(TipoItem x, TipoPilha *Pilha1, TipoPilha *Pilha2){
    //Passa tudo pra Pilha2, desenfilera o topo da Pilha2 e volta tudo pra Pilha1 sem o elemento retirado.
    TipoApontador aux1 = Pilha1->Topo->Prox;
    while(aux1 != NULL){
        Empilha(aux1->Item, Pilha2);
        aux1 = aux1->Prox;
    }

    Desempilha(&x, Pilha2);
    printf("\n");
    Imprime(Pilha2);

    FPVazia(Pilha1);
    TipoApontador aux2 = Pilha2->Topo->Prox;
    while(aux2 != NULL){
        Empilha(aux2->Item, Pilha1);
        aux2 = aux2->Prox;
    }
    Imprime(Pilha1);
}

void Enfilera(TipoItem x, TipoPilha *Pilha1, TipoPilha *Pilha2){
    Empilha(x, Pilha1);
}

void Imprime(TipoPilha Pilha){
    TipoApontador aux = Pilha.Topo->Prox;
    while(aux != NULL){
        printf("%d\n", aux->Item.Chave);
        aux = aux->Prox;
    }
}

int main(int argc, char *argv[])
{
    TipoItem a,b,c;
    a.Chave = 3;
    b.Chave = 2;
    c.Chave = 1;

    TipoPilha p1, p2;
    FPVazia(&p1);
    FPVazia(&p2);

    Enfilera(a, &p1, &p2);
    Enfilera(b, &p1, &p2);
    Enfilera(c, &p1, &p2);

    Desenfilera(a, &p1, &p2);
}

