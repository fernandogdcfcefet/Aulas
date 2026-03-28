#include <stdio.h>
#include <stdlib.h>

#define MAXTAM  10

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
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
       }
}

void Imprime(TipoFila f)
{
    int i;
    if(f.Frente<f.Tras)
    for(i=0;i<MAXTAM;i++)
    {
        printf(" %d",f.Item[i].Chave);
    }
    else
    {
        for(i=f.Frente;i<MAXTAM;i++)
        {
            printf(" %d",f.Item[i].Chave);
        }
        for(i=0;i<f.Tras;i++)
        {
            printf(" %d",f.Item[i].Chave);
        }
    }
}

int main()
{
    TipoFila MF;
    FFVazia(&MF);
    TipoItem x;
    int i;
    for(i=0;i<MAXTAM;i++)
    {
        x.Chave=rand()%10;
        MF.Item[i]=x;
    }
    Imprime(MF);
}
