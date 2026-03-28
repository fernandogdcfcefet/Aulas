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
  TipoApontador Frente;
  int n;//numero de elementos da fila
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 0;
  Fila->n = 0;
}

int Vazia(TipoFila Fila)
{ return (Fila.n == 0); }

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->n == MAXTAM)
  printf(" Erro   fila est  a  cheia\n");
  
  else { (Fila->Item[Fila->n + Fila->Frente)%MAXTAM] = x;
         Fila->n = Fila->n + 1;
       }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  
  else { *Item = Fila->Item[Fila->Frente];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
       }
}

int main(int argc, char *argv[])
{
	
	
	
	
	
}
