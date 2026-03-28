#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAXTAM  1000

typedef int TipoApontador;

typedef int TipoChave;
typedef struct {
  TipoChave Chave;
} TipoItem;

typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Frente, Tras;
  int Tamanho;
} TipoFila;

void FFVazia(TipoFila *Fila){
    Fila->Frente = 1;
    Fila->Tras = Fila->Frente;
    Fila->Tamanho=0;
}

int Vazia(TipoFila Fila){
    return (Fila.Tamanho == 0);
}

void Enfileira(TipoItem x, TipoFila *Fila){
    if (Fila->Tamanho == MAXTAM)
        printf(" Erro   fila esta  cheia\n");
    else {
        Fila->Item[Fila->Tamanho] = x;
        Fila->Tras = Fila->Tras % MAXTAM + 1;
        Fila->Tamanho++;
    }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item){
    if (Vazia(*Fila))
       printf("Erro fila esta vazia\n");
    else {
        *Item = Fila->Item[Fila->Frente - 1];
        Fila->Frente = Fila->Frente % MAXTAM + 1;
        Fila->Tamanho--;
    }
}

void Imprime(TipoFila *Fila){
    int i;
    for(i=0; i<Fila->Tamanho; i++){
        printf("%d", Fila->Item[i]);
    }
}

int main(){

    TipoFila MF;
    TipoItem a;

    FFVazia(&MF);
    a.Chave = 2;
    Enfileira(a,&MF);
    a.Chave = 4;
    Enfileira(a,&MF);
    a.Chave = 6;
    Enfileira(a,&MF);
    Imprime(&MF);
    printf("\n");
    Desenfileira(&MF,&a);
    Imprime(&MF);
    printf("\n");


}
