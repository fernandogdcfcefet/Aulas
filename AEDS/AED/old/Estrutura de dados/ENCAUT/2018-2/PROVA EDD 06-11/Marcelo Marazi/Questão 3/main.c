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

void Empilha(TipoItem x, TipoFila *Fila1, TipoFila *Fila2){
    if (Fila1->Tamanho == MAXTAM || Fila2->Tamanho == MAXTAM)
        printf(" Erro, as filas estao cheias\n");
    else {
        Fila1->Item[Fila1->Tamanho] = x;
        Fila2->Item[Fila2->Tamanho] = x;
        Fila1->Tras = Fila1->Tras % MAXTAM + 1;
        Fila2->Tras = Fila2->Tras % MAXTAM + 1;
        Fila1->Tamanho++;
        Fila2->Tamanho++;
    }
}

void Desempilha(TipoItem x, TipoFila *Fila1, TipoFila *Fila2){
    if (Vazia(*Fila1) || Vazia(*Fila2)){
       printf("Erro, as filas estao vazia\n");
    }
    else {
       *Item = Fila1->Item[Fila1->Frente - 1];
       *Item = Fila2->Item[Fila2->Frente - 1];
        Fila1->Frente = Fila1->Frente % MAXTAM + 1;
        Fila2->Frente = Fila2->Frente % MAXTAM + 1;
        Fila1->Tamanho--;
        Fila2->Tamanho--;

    }
}

void Imprime(TipoFila *Fila1, TipoFila *Fila2){
    int i;
    printf("Fila 1");
    for(i=0; i<Fila1->Tamanho; i++){
        printf("%d", Fila1->Item[i]);
    }
    printf("Fila 2");
    for(i=0; i<Fila2->Tamanho; i++){
        printf("%d", Fila2->Item[i]);
    }
}

int main(){

    TipoFila MF1, MF2;
    TipoItem a;

    FFVazia(&MF1);
    FFVazia(&MF2);
    a.Chave = 2;
    Empilha(a,&MF1,&MF2);
    Imprime(&MF1,&MF2);
    printf("\n");


}
