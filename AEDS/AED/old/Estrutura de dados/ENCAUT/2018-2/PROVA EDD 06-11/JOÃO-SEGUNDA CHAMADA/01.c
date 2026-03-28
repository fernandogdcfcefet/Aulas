#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAX 10

typedef int TipoChave;
typedef struct {
  char Chave;
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

void palindomo(TipoPilha* pilha)
{
    int teste;
    TipoApontador aponta, testep1, testep2;
    TipoItem item;
    TipoPilha *pilha2;

    FPVazia(pilha2);

    aponta = pilha->Topo->Prox;
    item.Chave = aponta->Item.Chave;

    {
        Empilha(item,pilha2);
        aponta = aponta->Prox;
    } while(aponta->Prox!=NULL);

    testep1 = pilha->Topo->Prox;
    testep2 = pilha2->Topo->Prox;
    teste = 0;

    {
        if(testep1->Prox->Item.Chave != testep2->Prox->Item.Chave)
        {
            teste = 1;
        }
        testep1 = testep1->Prox;
        testep2 = testep2->Prox;
    } while(testep1->Prox!=NULL || testep2->Prox!=NULL);

    if(teste == 1)
    {
        printf("Não é um palíndromo");
    } else {
        printf("É um palíndromo");
    }
}

int main(int argc, char *argv[])
{
    TipoPilha pilha;
    TipoItem a, b, c, d , e, f, g, h;
    a.Chave = 'a';
    b.Chave = 'b';
    c.Chave = 'c';
    d.Chave = 'd';
    e.Chave = 'e';
    f.Chave = 'f';
    g.Chave = 'g';
    h.Chave = 'h';

    FPVazia(&pilha);

    Empilha(a,&pilha);
    Empilha(b,&pilha);
    Empilha(a,&pilha);
    Empilha(b,&pilha);
    Empilha(a,&pilha);

    palindomo(&pilha);

    return 0;
}

