#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAXTAM  4

typedef int TipoApontador;

typedef int TipoChave;
typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;

typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Frente, Tras;
  int tam;
} TipoFila;

//======================================================

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
  Fila->tam=0;
}

//======================================================

int Vazia(TipoFila Fila)
{ return (Fila.Frente == Fila.Tras); }

//======================================================

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->tam==MAXTAM)
  printf(" Erro   fila est  a  cheia\n");
  else { Fila->Item[Fila->Tras - 1] = x;
         Fila->Tras = Fila->Tras % MAXTAM + 1;
         Fila->tam= Fila->tam % MAXTAM +1;
       }
}

//======================================================

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
         Fila->tam= Fila->tam % MAXTAM -1;
       }
}

//======================================================
/*
//Somente para teste:
void Imprime (TipoFila fila)
{
    int i;
    printf("\ntamanho: %d \n", fila.tam);
    for(i=fila.tam; i>0; i--)
    {
        printf("\n Item: %d \n", fila.Item[fila.Frente-1].Chave);
        fila.Frente++;
    }
}
*/
//======================================================
// Desenfileira um item negativo de cada vez
// o tam delimita o tamanho fa fila para poder percorrer

void RetiraNegativo (TipoFila *fila)
{
    int i, k=0;
    TipoFila filaAux;
    TipoItem itemAux;

    FFVazia(&filaAux);

    for(i=fila->tam; i>0; i--)
    {
        if (fila->Item[fila->Frente-1].Chave<0)
        {
            k=i;
        }
    fila->Frente++;
    }
    for (i=k;i>0;i--)
    {
        Desenfileira(fila, &itemAux);
        Enfileira(itemAux, &filaAux);
    }
    Desenfileira(fila, &itemAux);

    for (i=k-filaAux.tam; i>0 ;i--)
    {
        Desenfileira(fila, &itemAux);
        Enfileira(itemAux, &filaAux);
    }
     for(i=filaAux.tam; i>0; i--)
    {
        Desenfileira(&filaAux, &itemAux);
        Enfileira(itemAux, fila);
    }
}

//======================================================

void InverteOrdem (TipoFila *fila)
{
    TipoFila filaAux1, filaAux2;
    TipoItem itemAux;

    FFVazia(&filaAux1);
    FFVazia(&filaAux2);

    while(!Vazia(*fila))
    {

        Desenfileira(fila, &itemAux);
        Enfileira(itemAux, &filaAux1);
    }
    while(!Vazia(filaAux1))
    {

        Desenfileira(&filaAux1, &itemAux);
        Enfileira(itemAux, &filaAux2);
    }
    while(!Vazia(filaAux2))
    {

        Desenfileira(&filaAux2, &itemAux);
        Enfileira(itemAux, &fila);
    }
}

//======================================================

int main()
{
    TipoFila fila;
    TipoItem item;

    FFVazia(&fila);

    item.Chave=1;
    Enfileira(item,&fila);
    item.Chave=2;
    Enfileira(item,&fila);
    item.Chave=-3;
    Enfileira(item,&fila);
    item.Chave=4;
    Enfileira(item,&fila);

    //Imprime(fila);

    printf("\n_______________________________________________\n");

    //RetiraNegativo(&fila);
    //Imprime(fila);

    printf("\n_______________________________________________\n");

    //InverteOrdem(&fila);
    //Imprime(fila);

 return 0;
}
