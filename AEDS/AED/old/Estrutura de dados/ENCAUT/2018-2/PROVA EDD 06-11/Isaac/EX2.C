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
  int tam;
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 0;
  Fila->Tras = Fila->Frente;
  Fila->tam = 0;
}

int Vazia(TipoFila Fila)
{ return (Fila.tam==0); }

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->Tras % MAXTAM + 1 == Fila->Frente)
  printf(" Erro   fila est  a  cheia\n");
  else { Fila->Item[Fila->Tras] = x;
         Fila->Tras = Fila->Tras % MAXTAM + 1;
         Fila->tam++;
       }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
         Fila->tam--;
       }
}

void imprime(TipoFila *fila) {
    int i;
    for(i=0; i < fila->tam; i++) {
        printf("%d, ", fila->Item[i].Chave);
    }
}

int main(int argc, char *argv[])
{
    TipoItem item;
    TipoFila fila1;
    FFVazia(&fila1);

    item.Chave = 1;
    Enfileira(item, &fila1);
    item.Chave = 2;
    Enfileira(item, &fila1);
    item.Chave = 3;
    Enfileira(item, &fila1);
    item.Chave = 4;
    Enfileira(item, &fila1);

    //Desenfileira(&fila1, &item);

    imprime(&fila1);




}
