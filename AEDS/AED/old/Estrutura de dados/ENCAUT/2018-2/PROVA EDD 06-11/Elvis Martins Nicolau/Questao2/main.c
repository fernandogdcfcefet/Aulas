#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAXTAM  1000

typedef int TipoApontador;
typedef int TipoTamanho;//letra b

typedef int TipoChave;
typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;
typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Frente, Tras;
  TipoTamanho Tamanho;
} TipoFila;

void FFVazia(TipoFila *Fila)
{
    Fila->Frente = 0;
    Fila->Tras = 0;
    Fila->Tamanho = 0;
}

int Vazia(TipoFila Fila) //letra b
{ return (Fila.Tamanho == 0); }

void Enfileira(TipoItem x, TipoFila *Fila) //letra b
{ if (Fila->Tamanho == MAXTAM-1)
  printf(" Erro   fila esta  cheia\n");
  else { Fila->Item[Fila->Tras] = x;
        Fila->Tamanho++;
         if(Fila->Tras == MAXTAM -1) Fila->Tras = 0;
         else Fila->Tras++;
       }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)//letra b
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente];
            Fila->Tamanho--;
            if(Fila->Frente == MAXTAM -1) Fila->Frente = 0;
            else Fila->Frente++;
       }
}

void Imprime(TipoFila *Fila) //letra a
{
    if(Vazia(*Fila)) printf("A Fila esta vazia!\n");
    else if(Fila->Frente < Fila->Tras)
    {
        int i;

        for(i=Fila->Frente;i<=Fila->Tras;i++)
        {
            printf("%d ",Fila->Item[i].Chave);
        }
    }
    else if(Fila->Frente > Fila->Tras)
    {
        int i;

        for(i=Fila->Frente;i>=Fila->Tras;i--)
        {
            printf("%d ",Fila->Item[i].Chave);
        }
    }

}

int main()
{
    return 0;
}
