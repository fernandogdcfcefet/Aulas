#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


void FFVazia(TipoFila *Fila)
{
    Fila->Frente = 1;
    Fila->Tras = Fila->Frente;
}

int Vazia(TipoFila Fila)
{
    return (Fila.Frente == Fila.Tras);
}

void Enfileira(TipoItem x, TipoFila *Fila)
{
    if (Fila->Tras % MAXTAM + 1 == Fila->Frente)
        printf(" Erro   fila est  a  cheia\n");
    else
    {
        Fila->Item[Fila->Tras - 1] = x;
        Fila->Tras = Fila->Tras % MAXTAM + 1;
    }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{
    if (Vazia(*Fila))
        printf("Erro fila esta vazia\n");
    else
    {
        *Item = Fila->Item[Fila->Frente - 1];
        Fila->Frente = Fila->Frente % MAXTAM + 1;
    }
}
