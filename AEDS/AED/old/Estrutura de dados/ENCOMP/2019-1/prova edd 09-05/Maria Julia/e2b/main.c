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
  TipoItem Item[MAXTAM];
  TipoApontador Frente, Tras;
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 0;
  Fila->Tras = 1;
}

int Vazia(TipoFila Fila)
{
    if (Fila.Frente==0 && Fila.Tras==1){
        return 1;
    }

    return 0;

}

void Enfileira(TipoItem x, TipoFila *Fila){
    if ((Fila->Tras==MAXTAM && Fila->Frente==0) || (Fila->Tras==Fila->Frente-1)){
        printf(" Erro   fila est  a  cheia\n");
    }
    else {
        Fila->Item[Fila->Tras] = x;
        Fila->Tras = Fila->Tras % MAXTAM + 1
    }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else {
        *Item = Fila->Item[Fila->Frente];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
       }
}
int main()
{
}
