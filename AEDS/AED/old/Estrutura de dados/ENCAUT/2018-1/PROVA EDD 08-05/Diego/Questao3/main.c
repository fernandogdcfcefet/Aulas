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

void RemocaoNegativo(TipoFila *Fila){
    int i,j;

    for(i = Fila->Frente-1; i < Fila->Tras-1;i++){
        if(Fila->Item[i].Chave < 0){
            for(j = i; j < Fila->Tras-1;j++){
                Fila->Item[j] = Fila->Item[j+1];
            }
            Fila->Tras--;
        }
    }
}

void Imprime(TipoFila Fila){
    int i;

    for(i = Fila.Frente-1; i < Fila.Tras-1;i++){
        printf("%d ",Fila.Item[i].Chave);
    }
}

int main()
{
    TipoFila MF;
    TipoItem Item;

    FFVazia(&MF);
    Item.Chave = 1;
    Enfileira(Item,&MF);
    Item.Chave = 2;
    Enfileira(Item,&MF);
    Item.Chave = 3;
    Enfileira(Item,&MF);
    Item.Chave = 4;
    Enfileira(Item,&MF);
    Item.Chave = -2;
    Enfileira(Item,&MF);
    Item.Chave = 5;
    Enfileira(Item,&MF);
    Item.Chave = 6;
    Enfileira(Item,&MF);
    RemocaoNegativo(&MF);
    Imprime(MF);


    return 0;
}
