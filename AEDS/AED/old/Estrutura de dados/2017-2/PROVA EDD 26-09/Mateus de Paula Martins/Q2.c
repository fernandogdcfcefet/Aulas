#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define max  5


typedef struct {
  int Chave;
} TipoItem;

typedef struct {
  TipoItem Item[max];
  int Frente, Tras;
  int tam; // pode ser implementado para verificar se esta cheia ou vazia
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
  Fila->tam=0;
}

int Vazia(TipoFila Fila)
{ return (Fila.Frente == Fila.Tras); }

void Enfileira(TipoItem x, TipoFila *Fila)
{
  if (Fila->Tras % max + 1 == Fila->Frente){
    printf(" Erro   fila est  a  cheia\n");
}
  else
{
    Fila->Item[Fila->Tras - 1] = x;
    Fila->Tras = Fila->Tras % max + 1;
    Fila->tam++;
}
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = Fila->Frente % max + 1;
       }
}

void Imprime (TipoFila fila)
{
    int i;
    printf("\nTamanho: %d\t", fila.tam);
    printf("Frente: %d\t", fila.Frente);
    printf("Tras: %d\n", fila.Tras);

    if (fila.Frente> fila.Tras)
    {
        for (i=fila.Frente-1; i<max; i++)
        {
            printf("Chave: %d\n", fila.Item[i].Chave);
        }
        for (i=0; i<fila.Tras-1; i++)
        {
            printf("Chave: %d\n", fila.Item[i].Chave);
        }
    }
    else
    {
        for (i=fila.Frente-1; i<fila.Tras-1; i++)
        {
            printf("Chave: %d\n", fila.Item[i].Chave);
        }
    }
}

int main(int argc, char *argv[])
{
    TipoFila fila;
    TipoItem item;

    FFVazia(&fila);

    item.Chave=1;
    Enfileira(item, &fila);
    item.Chave=2;
    Enfileira(item, &fila);
    item.Chave=3;
    Enfileira(item, &fila);
    item.Chave=4;
    Enfileira(item, &fila);

    Imprime(fila);

    printf("_________________________________________\n");

    Desenfileira(&fila, &item);
    Enfileira(item, &fila);
    Desenfileira(&fila, &item);
    Enfileira(item, &fila);
    Imprime(fila);

    printf("_________________________________________\n");



}
