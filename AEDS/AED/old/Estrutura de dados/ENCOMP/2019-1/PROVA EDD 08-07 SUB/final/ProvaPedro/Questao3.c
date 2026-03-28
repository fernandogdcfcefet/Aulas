#include <stdio.h>
#include <stdlib.h>

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

void concatena(TipoFila *MF1, TipoFila *MF2){

    TipoApontador aux;
    TipoItem item;

    aux = MF2->Frente;

    while(aux != NULL){
            Desenfileira(&MF2,&item);
            Enfileira(item,&MF1);
    }
}


int main()
{

    TipoFila MF1,MF2;

    FFVazia(&MF1);
    FFVazia(&MF2);

    TipoItem item;

    item.Chave = 0;
    Enfileira(item,&MF1);
    item.Chave = 1;
    Enfileira(item,&MF1);
    item.Chave = 2;
    Enfileira(item,&MF2);
    item.Chave = 3;
    Enfileira(item,&MF2);


    concatena(&MF1,&MF2);

}
