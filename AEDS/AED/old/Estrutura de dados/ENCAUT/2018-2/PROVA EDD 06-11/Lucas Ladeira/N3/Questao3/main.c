#include <stdio.h>
#include <stdlib.h>
#define MAXTAM  1000

typedef int TipoApontador;

typedef int TipoChave;
typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;
typedef struct {
  TipoItem Item[MAXTAM], x;
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

void Empilha(TipoItem x, TipoFila *Fila1, TipoFila *Fila2){
    if (Fila1->Tras % MAXTAM + 1 == Fila1->Frente)
    printf(" Erro   fila est  a  cheia\n");
    else { Fila1->Item[Fila1->Tras - 1] = x;
         Fila1->Tras = Fila1->Tras % MAXTAM + 1;
       }
       if (Vazia(*Fila1))
        printf("Erro fila esta vazia\n");
    else { x = Fila2->x[Fila2->Frente - 1];
         Fila2->Frente = Fila2->Frente % MAXTAM + 1;
       }
}

void Desempilha(TipoItem x, TipoFila *Fila1, TipoFila *Fila2){
   if (Fila2->Tras % MAXTAM + 1 == Fila2->Frente)
    printf(" Erro   fila est  a  cheia\n");
    else { Fila2->Item[Fila2->Tras - 1] = x;
         Fila2->Tras = Fila2->Tras % MAXTAM + 1;
       }
    if (Vazia(*Fila2))
        printf("Erro fila esta vazia\n");
    else { x = Fila1->Item[Fila1->Frente - 1];
         Fila1->Frente = Fila1->Frente % MAXTAM + 1;
       }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
