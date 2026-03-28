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
  int Tamanho;
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
  Fila->Tamanho = 0;
}

int Vazia(TipoFila Fila)
{ return (Fila.Tamanho == 0); }

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->Tras % MAXTAM + 1 == Fila->Frente)
  printf(" Erro   fila est  a  cheia\n");
  else { Fila->Item[Fila->Tras - 1] = x;
         Fila->Tras = Fila->Tras % MAXTAM + 1;
         Fila->Tamanho++;
       }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
         Fila->Tamanho--;
       }
}

void Imprime(TipoFila Fila){
    int i;
    if(Fila.Frente < Fila.Tras)
    for(i= Fila.Frente; i<Fila.Tras - 1; i++){
        printf("%d ", Fila.Item[i].Chave);
    }
    else{
        for(i= Fila.Frente; i<MAXTAM; i++){
        printf("%d ", Fila.Item[i].Chave);
    }
        for(i= 0; i<Fila.Tras- 1; i++){
        printf("%d ", Fila.Item[i].Chave);
    }
    }
}

int main(){
    TipoFila Fila;
    FFVazia(&Fila);
    TipoItem Item;
    int i;
    for(i = 0 ; i<10; i++){
        Item.Chave = i;
        Enfileira(Item, &Fila);
    }
    Imprime(Fila);

}
