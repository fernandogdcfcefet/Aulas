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

void Imprime(TipoFila *Fila){
    TipoApontador i=Fila->Frente-1;
    while(i<Fila->Tras-1){
        printf("%d ", Fila->Item[i].Chave);
        i++;
    }
}
int main(int argc, char *argv[])
{
    TipoFila f;
    FFVazia(&f);

    TipoItem a, b, c, d, e;

    a.Chave = 1;
    b.Chave = 2;
    c.Chave = 3;
    d.Chave = 4;
    e.Chave = 5;

    Enfileira(a, &f);
    Enfileira(b, &f);
    Enfileira(c, &f);
    Enfileira(d, &f);
    Enfileira(e, &f);

    Imprime(&f);
    printf("\n\n %d \n\n", Vazia(f));
    Imprime(&f);
}
