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

void Imprime(TipoPilha Pilha){
     if(Vazia(Pilha)){printf("PILHA VAZIA");}

     TipoApontador i;
     i=Pilha.Topo->Prox;
     while(i!= NULL){
        printf("%d\n", i->Item.Chave);
        i=i->Prox;
    }
}

int main(int argc, char *argv[])
{

    // EXERCICIO 2

    TipoPilha p1, p2, p3;
    TipoItem e1, e2, e3, aux;
    e1.Chave=1;
    e2.Chave=11;
    e3.Chave=111;

    FPVazia(&p1);
    FPVazia(&p2);
    FPVazia(&p3);

    Empilha(e3, &p1);
    Empilha(e2, &p1);
    Empilha(e1, &p1);
    printf("Pilha 1\n");
    Imprime(p1);
    printf("Pilha 2\n");
    Imprime(p2);
    printf("\nPilha 3\n");
    Imprime(p3);

    printf("\n-----------------------------\n\n");

    // PRIMEIRO MOVIMENTO
    Desempilha(&p1, &aux);
    Empilha(aux, &p3);
    printf("Pilha 1\n");
    Imprime(p1);
    printf("Pilha 2\n");
    Imprime(p2);
    printf("\nPilha 3\n");
    Imprime(p3);

    printf("\n-----------------------------\n\n");

    //SEGUNDO MOVIMENTO
    Desempilha(&p1, &aux);
    Empilha(aux, &p2);
    printf("Pilha 1\n");
    Imprime(p1);
    printf("Pilha 2\n");
    Imprime(p2);
    printf("\nPilha 3\n");
    Imprime(p3);

    printf("\n-----------------------------\n\n");

    //TERCEIRO MOVIMENTO
    Desempilha(&p3, &aux);
    Empilha(aux, &p2);
    printf("Pilha 1\n");
    Imprime(p1);
    printf("Pilha 2\n");
    Imprime(p2);
    printf("\nPilha 3\n");
    Imprime(p3);

    printf("\n-----------------------------\n\n");

    //QUARTO MOVIMENTO
    Desempilha(&p1, &aux);
    Empilha(aux, &p3);
    printf("Pilha 1\n");
    Imprime(p1);
    printf("Pilha 2\n");
    Imprime(p2);
    printf("\nPilha 3\n");
    Imprime(p3);

    printf("\n-----------------------------\n\n");

    //QUINTO MOVIMENTO
    Desempilha(&p2, &aux);
    Empilha(aux, &p1);
    printf("Pilha 1\n");
    Imprime(p1);
    printf("Pilha 2\n");
    Imprime(p2);
    printf("\nPilha 3\n");
    Imprime(p3);

    printf("\n-----------------------------\n\n");
    //SEXTO MOVIMENTO
    Desempilha(&p2, &aux);
    Empilha(aux, &p3);
    printf("Pilha 1\n");
    Imprime(p1);
    printf("Pilha 2\n");
    Imprime(p2);
    printf("\nPilha 3\n");
    Imprime(p3);

    printf("\n-----------------------------\n\n");

    //SETIMO MOVIMENTO
    Desempilha(&p1, &aux);
    Empilha(aux, &p3);
    printf("Pilha 1\n");
    Imprime(p1);
    printf("Pilha 2\n");
    Imprime(p2);
    printf("\nPilha 3\n");
    Imprime(p3);

    printf("\n-----------------------------\n\n");

}

