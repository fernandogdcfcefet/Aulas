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

}

void Negativos(TipoFila *Fila, TipoItem *Item){
    if (Fila->Tras % MAXTAM + 1 == Fila->Frente){
        else {Fila->Item[Fila->Tras-1] = x};

    }
    if (Vazia(*Fila)) {
        *Item = Fila->Item[Fila->Frente];
    }
    else { *Item = Fila->Item[Fila->Frente -1];}
}

int main()
{
}
