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

void imprime(TipoFila *Fila){
    int i;
    TipoItem ItemAux;
    if(Fila->Tras > Fila->Frente){
        for(i=Fila->Frente - 1; i<Fila->Tras - 1; i++){
            ItemAux = Fila->Item[i];
            printf("%d\n", ItemAux.Chave);
        }
    }else if(Fila->Tras < Fila->Frente){
        for(i=Fila->Frente - 1; i<Fila->Tras % MAXTAM; i++){
            ItemAux = Fila->Item[i];
            printf("%d\n", ItemAux.Chave);
        }
        for(i=Fila->Tras - 1; i<Fila->Frente % MAXTAM; i++){
            ItemAux = Fila->Item[i];
            printf("%d\n", ItemAux.Chave);
        }
    }else{
        printf("FILA VAZIA!\n");
    }
}

int main(int argc, char *argv[])
{
    TipoFila Fila;
    FFVazia(&Fila);
    TipoItem Item;

    Item.Chave = 3;
    Enfileira(Item, &Fila);
    Item.Chave = 2;
    Enfileira(Item, &Fila);
    Item.Chave = 4;
    Enfileira(Item, &Fila);
    Item.Chave = 7;
    Enfileira(Item, &Fila);
    Item.Chave = 6;
    Enfileira(Item, &Fila);

    imprime(&Fila);
    return 0;
}
