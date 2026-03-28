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
  int tamanho;
} TipoFila;

void FFVazia(TipoFila *Fila){
  Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
  Fila->tamanho = 0;

}

int Vazia(TipoFila Fila)
{ return (Fila.tamanho == 0); }

void Enfileira(TipoItem x, TipoFila *Fila){
    if (Fila->tamanho == MAXTAM)
        printf(" Erro   fila est  a  cheia\n");

    else {
        Fila->Item[Fila->Tras - 1] = x;
        Fila->Tras = Fila->Tras % MAXTAM + 1;
        Fila->tamanho = Fila->tamanho + 1;
    }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item){
    if (Vazia(*Fila))
        printf("Erro fila esta vazia\n");
    else {
        *Item = Fila->Item[Fila->Frente - 1];
        Fila->Frente = Fila->Frente % MAXTAM + 1;
        Fila->tamanho = Fila->tamanho - 1;
    }
}

void Imprime(TipoFila *Fila) {
    int i;
    for(i = Fila->Frente - 1; i < Fila->Tras - 1; i = i%MAXTAM + 1) {
        printf("%d ", Fila->Item[i].Chave);
    }
    printf("\n");
}

void Empilha(TipoItem x, TipoFila *Fila1, TipoFila *Fila2) {
    TipoItem itemAux;
    TipoFila FilaAux;

    int i;
    for(i = Fila1->Tras - 1; i >= Fila1->Frente - 1; i--) {
        Desenfileira(Fila1, &itemAux);
        Enfileira(itemAux, &FilaAux);
    }


}

int main(int argc, char *argv[]) {
    TipoFila MF1, MF2;
    FFVazia(&MF1);
    FFVazia(&MF2);
    TipoItem item;

    item.Chave = 1;
    Enfileira(item, &MF1);
    item.Chave = 2;
    Enfileira(item, &MF1);
    item.Chave = 3;
    Enfileira(item, &MF1);
    item.Chave = 4;
    Enfileira(item, &MF1);
    item.Chave = 5;
    Enfileira(item, &MF1);


    return 0;

}
