#include <stdio.h>
#include <stdlib.h>
#define MAXTAM  3

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
  printf(" Erro: a fila esta cheia\n");
  else { Fila->Item[Fila->Tras - 1] = x;
         Fila->Tras = Fila->Tras % MAXTAM + 1;
       }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro: a fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
       }
}
//////////////////////////////////////////////////////////////////////////////
void Imprime(TipoFila *Fila) /* Passagem por ponteiro para não precisar copiar toda a lista, aumentado eficiência*/
{   int i;
    for(i = Fila->Frente; i < Fila->Tras; i++) /* Percorre o arranjo de Frente a Tras, imprimindo as chaves na orderm First-In, First-Out */
        printf(" %d\n", Fila->Item->Chave);
    printf("\n");
}
//////////////////////////////////////////////////////////////////////////////
int main()
{   TipoFila ML;
    TipoItem a, b, c;
    a.Chave = 1;
    b.Chave = 2;
    c.Chave = 3;
    Enfileira(a, &ML);
    Enfileira(b, &ML);
    Enfileira(c, &ML);
    Imprime(&ML);
    return 0;
}
