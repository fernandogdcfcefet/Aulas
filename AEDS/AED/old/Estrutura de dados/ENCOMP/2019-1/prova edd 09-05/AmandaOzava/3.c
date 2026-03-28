#include <stdio.h>
#include <stdlib.h>

#define MAXTAM  5

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
void Empilha(TipoFila *fila, TipoFila *fila1, TipoItem item)
{
// A cada chamada do Empilha, sempre o ultimo a entrar torna-se o primeiro da fila.
    TipoItem item1;
    while(!Vazia(*fila)) //Aqui, esvazio a fila, adiciono todos na fila1
    {
        Desenfileira(fila, &item1);
        Enfileira(item1,fila1);
    }
    Enfileira(item, fila);// insiro na fila.
    while(!Vazia(*fila1))//Aqui desenfileiro da fila1 para fila
    {
        Desenfileira(fila1, &item1);
        Enfileira(item1, fila);
    }

}
void Desempilha (TipoFila *fila, TipoItem *item)
{
    //Como a fila ficou invertida, ou seja, tornou-se uma pilha, basta remover o primeiro elemento, procedimento já realizado pelo desenfileira.
    Desenfileira(fila, item);
}
void Imprime (TipoFila fila)
{
    if(fila.Frente<fila.Tras)
    {
        for(int i=fila.Frente-1;i<fila.Tras-1;i++)
            printf("%d\n", fila.Item[i].Chave);
    }
    else
    {
        for(int i=fila.Frente-1;i<MAXTAM;i++)
            printf("%d\n", fila.Item[i].Chave);
        for(int i=0;i<fila.Tras-1;i++)
            printf("%d\n", fila.Item[i].Chave);
    }
}
int main()
{
    TipoFila fila, fila1;
    TipoItem item;
    FFVazia(&fila);
    FFVazia(&fila1);
    for(int i=0;i<MAXTAM-1;i++)
    {
        scanf("%d", &item.Chave);
        //Enfileira(item, &fila);
        Empilha(&fila, &fila1, item);
    }
    printf("FILA INVERTIDA - PILHA\n");
    Imprime(fila);
    printf("APOS REMOVER ITEM:\n");
    Desempilha(&fila, &item);
    Imprime(fila);

}
