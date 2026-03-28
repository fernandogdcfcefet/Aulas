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
  TipoApontador Frente, Tras,cont;
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
  Fila->cont=0;
}

int Vazia(TipoFila Fila)
{ return (Fila.Frente == Fila.Tras); }

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->Tras % MAXTAM + 1 == Fila->Frente)
  printf(" Erro   fila est  a  cheia\n");
  else { Fila->Item[Fila->Tras - 1] = x;
         Fila->Tras = Fila->Tras % MAXTAM + 1;
         Fila->cont++;
    }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
       }
}

void Imprime(TipoFila *Fila){
    int i;
    for(i=0;i<Fila->Tras-1;i++){
        printf("%d\n",Fila->Item[i].Chave);
    }
}

int main(){
    TipoFila Fila;
    FFVazia(&Fila);
    TipoItem item;
    item.Chave=1;
    Enfileira(item,&Fila);
    item.Chave=2;
    Enfileira(item,&Fila);
    item.Chave=3;
    Enfileira(item,&Fila);
    Imprime(&Fila);
    printf("\nTOTAL ITENS = %d\n",Fila.cont);

    return 0;
}
