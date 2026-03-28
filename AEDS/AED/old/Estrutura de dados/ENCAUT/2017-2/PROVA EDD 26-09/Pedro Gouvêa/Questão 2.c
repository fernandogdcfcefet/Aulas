#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAXTAM  6

typedef int TipoApontador;

typedef int TipoChave;
typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;
typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Frente, Tras;
  int tamanho;                   // Na letra b criei uma variável na estrutura da fila chamada tamanho para poder verificar se a mesma está vazia tomando como referência o tamanho
} TipoFila;

void FFVazia(TipoFila *Fila){
  Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
  Fila->tamanho = 0;

}

int Vazia(TipoFila Fila)
{ return (Fila.tamanho == 0); }                   // Letra b da questão 2

void Enfileira(TipoItem x, TipoFila *Fila){
    if (Fila->tamanho == MAXTAM)                                    // Faz parte da letra B
        printf(" Erro   fila est  a  cheia\n");

    else {
        Fila->Item[Fila->Tras - 1] = x;
        Fila->Tras = Fila->Tras % MAXTAM + 1;
        Fila->tamanho = Fila->tamanho + 1;            // Faz parte da letra B
    }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item){
    if (Vazia(*Fila))
        printf("Erro fila esta vazia\n");
    else {
        *Item = Fila->Item[Fila->Frente - 1];
        Fila->Frente = Fila->Frente % MAXTAM + 1;
        Fila->tamanho = Fila->tamanho - 1;               // Faz parte da letra B
    }
}

void Imprime(TipoFila *Fila) {                         // Letra A da questão 2
    int i;
    for(i = Fila->Frente - 1; i < Fila->Tras - 1; i = i%MAXTAM + 1) {
        printf("%d ", Fila->Item[i].Chave);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    TipoFila MF;
    FFVazia(&MF);
    TipoItem item;

    item.Chave = 1;
    Enfileira(item, &MF);
    item.Chave = 2;
    Enfileira(item, &MF);
    item.Chave = 3;
    Enfileira(item, &MF);
    item.Chave = 4;
    Enfileira(item, &MF);
    item.Chave = 5;
    Enfileira(item, &MF);

    Desenfileira(&MF,&item);
    item.Chave = 6;
    Enfileira(item, &MF);

    Imprime(&MF);

    return 0;

}
