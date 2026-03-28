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

void Imprime(TipoFila Fila){
    int i;
    if(Vazia(Fila)) printf("LISTA VAZIA");
    for(i=Fila.Frente-1; i<=Fila.Tras-2; i++){
        printf("%d\n", Fila.Item[i]);
    }

}

int main(int argc, char *argv[])
{
    TipoFila fila;
    TipoItem a, b, c, d, aux;
    a.Chave=2;
    b.Chave=5;
    c.Chave=10;
    d.Chave=55;
    FFVazia(&fila);
    Enfileira(a, &fila);
    Enfileira(b, &fila);
    Enfileira(c, &fila);
    Enfileira(d, &fila);
    Desenfileira(&fila, &aux);

    Imprime(fila);
}
