#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAXTAM  1000

typedef int TipoApontador;

typedef int TipoChave;
typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;
typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Frente, Tras;
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
}

int Vazia(TipoFila Fila)
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

void empilha(TipoItem x, TipoFila *fila1, TipoFila *fila2) {
    TipoItem aux;
    while(Vazia(*fila1)==0) {
        Desenfileira(fila1, &aux);
        Enfileira(aux, fila2);
    }
    Enfileira(x, fila1);
    while(Vazia(*fila2)==0) {
        Desenfileira(fila2, &aux);
        Enfileira(aux, fila1);
    }
}

void desempilha(TipoItem x, TipoFila *Fila1, TipoFila *Fila2) {
    Desenfileira(Fila1, &x);
}

int main(int argc, char *argv[])
{
    TipoItem item;
    TipoFila fila1, fila2;
    FFVazia(&fila1);
    FFVazia(&fila2);

    item.Chave=1;
    empilha(item, &fila1, &fila2);
    desempilha(item, &fila1, &fila2);

}
