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


void Empilha(TipoItem x,TipoFila *fila1, TipoFila *fila2){

    int i;
    for ( i = 0 ; i < fila1->Tras -1; i++){
        if ( i < fila1->Tras-1){
            x = fila1->Item[i];
            Enfileira(x,&fila2);
        }
    }

}

int main()
{
    TipoFila fila1,fila2;
    TipoItem item;
    FFVazia(&fila1);
    item.Chave = 3;
    Enfileira(item,&fila1);
    item.Chave = 5;
    Enfileira(item,&fila1);
    FFVazia(&fila2);
    item.Chave = 6;
    Enfileira(item,&fila2);
    item.Chave = 10;
    Enfileira(item,&fila2);

}
