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

void Imprime(TipoFila *Fila)
{
    int i;
    TipoChave chave;
    TipoItem item;

    do
    {
        chave = Fila->Item[Fila->Frente].Chave;
        printf(chave);
        Desenfileira(Fila,&item);
    } while(Fila->Tras % MAXTAM + 1 != Fila->Frente);
}

int main(int argc, char *argv[])
{
    TipoFila fila;
    TipoItem a, b, c, d, e, f, g, h;
    a.Chave = 1;
    b.Chave = 2;
    c.Chave = 3;
    d.Chave = 4;
    e.Chave = 5;
    f.Chave = 6;
    g.Chave = 7;
    h.Chave = 8;

    FFVazia(&fila);

    Enfileira(a,&fila);
    Enfileira(b,&fila);
    Enfileira(c,&fila);
    Enfileira(d,&fila);
    Enfileira(e,&fila);
    Enfileira(f,&fila);
    Enfileira(g,&fila);
    Enfileira(h,&fila);

    Imprime(&fila);

    return 0;
}
