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
{ Fila->Frente = 0;
  Fila->Tras = Fila->Frente;
}

int Vazia(TipoFila Fila)
{ return (Fila.Frente == Fila.Tras); }

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->Tras % MAXTAM + 1 == Fila->Frente)
  printf(" Erro   fila est  a  cheia\n");
  else { Fila->Item[Fila->Tras] = x;
         Fila->Tras = Fila->Tras % MAXTAM + 1;
       }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
       }
}

void Imprime(TipoFila *Fila)
{
    if(Vazia(*Fila))
    {
        printf("\n erro: fila vazia");
        return;
    }
    else
    {
        printf("\n");
        if(Fila->Tras>Fila->Frente) for(int i=Fila->Frente; i<=Fila->Tras; i++) printf("\t%d", Fila->Item[i].Chave);
        if(Fila->Tras<Fila->Frente)
        {
            for(int i=Fila->Frente; i<MAXTAM; i++) printf("\t%d", Fila->Item[i].Chave);
            for(int i=0; i<=Fila->Tras; i++) printf("\t%d", Fila->Item[i].Chave);
        }
    }
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
