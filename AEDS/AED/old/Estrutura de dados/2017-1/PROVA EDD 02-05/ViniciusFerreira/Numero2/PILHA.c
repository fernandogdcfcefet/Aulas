#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    TipoPilha p1;
    TipoPilha p2;
    TipoPilha p3;
    FPVazia(&p1);
    FPVazia(&p2);
    FPVazia(&p3);

    Empilha(a, &p1);
    Empilha(b, &p1);
    Empilha(c, &p1);

    printf("\n\nPilha 1: \n");
    Imprime(p1);
    printf("\nPilha 2: \n");
    Imprime(p2);
    printf("\nPilha 3: \n");
    Imprime(p3);

    printf("\n##### MOVIMENTO 1 #####\n");
    Desempilha(&p1, &p1.Topo->Prox);
    Empilha(c, &p3);

    printf("\n\nPilha 1: \n");
    Imprime(p1);
    printf("\nPilha 2: \n");
    Imprime(p2);
    printf("\nPilha 3: \n");
    Imprime(p3);
    printf("\n#######################\n");

    printf("\n##### MOVIMENTO 2 #####\n");
    Desempilha(&p1, &p1.Topo->Prox);
    Empilha(b, &p2);

    printf("\n\nPilha 1: \n");
    Imprime(p1);
    printf("\nPilha 2: \n");
    Imprime(p2);
    printf("\nPilha 3: \n");
    Imprime(p3);
    printf("\n#######################\n");

    printf("\n##### MOVIMENTO 3 #####\n");
    Desempilha(&p3, &p3.Topo->Prox);
    Empilha(c, &p2);

    printf("\n\nPilha 1: \n");
    Imprime(p1);
    printf("\nPilha 2: \n");
    Imprime(p2);
    printf("\nPilha 3: \n");
    Imprime(p3);
    printf("\n#######################\n");

    printf("\n##### MOVIMENTO 4 #####\n");
    Desempilha(&p1, &p1.Topo->Prox);
    Empilha(a, &p3);

    printf("\n\nPilha 1: \n");
    Imprime(p1);
    printf("\nPilha 2: \n");
    Imprime(p2);
    printf("\nPilha 3: \n");
    Imprime(p3);
    printf("\n#######################\n");

    printf("\n##### MOVIMENTO 5 #####\n");
    Desempilha(&p2, &p2.Topo->Prox);
    Empilha(c, &p1);

    printf("\n\nPilha 1: \n");
    Imprime(p1);
    printf("\nPilha 2: \n");
    Imprime(p2);
    printf("\nPilha 3: \n");
    Imprime(p3);
    printf("\n#######################\n");

    printf("\n##### MOVIMENTO 6 #####\n");
    Desempilha(&p2, &p2.Topo->Prox);
    Empilha(b, &p3);

    printf("\n\nPilha 1: \n");
    Imprime(p1);
    printf("\nPilha 2: \n");
    Imprime(p2);
    printf("\nPilha 3: \n");
    Imprime(p3);
    printf("\n#######################\n");

    printf("\n##### MOVIMENTO 7 #####\n");
    Desempilha(&p1, &p1.Topo->Prox);
    Empilha(c, &p3);

    printf("\n\nPilha 1: \n");
    Imprime(p1);
    printf("\nPilha 2: \n");
    Imprime(p2);
    printf("\nPilha 3: \n");
    Imprime(p3);
    printf("\n#######################\n");
}

