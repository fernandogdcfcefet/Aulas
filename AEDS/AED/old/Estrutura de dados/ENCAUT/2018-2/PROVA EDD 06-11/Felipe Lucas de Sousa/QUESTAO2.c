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
  int Tamanho;
} TipoFila;

void FFVazia(TipoFila *Fila){
    Fila->Tamanho = 0;
}

int Vazia(TipoFila Fila)
{ return (Fila.Tamanho == 0); }

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->Tamanho > MAXTAM)
  printf(" Erro: A fila está cheia!\n");
  else { Fila->Item[Fila->Tamanho] = x;
         Fila->Tamanho++;
       }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item){
    int i;
    if (Vazia(*Fila)){
        printf("Erro: A fila está vazia!\n");
    }else{
        *Item = Fila->Item[0];
        Fila->Tamanho--;

        for(i=0; i<Fila->Tamanho; i++){
            Fila->Item[i] = Fila->Item[i+1];
        }
    }
}

void Imprime(TipoFila *Fila){
    int i;
    printf("\n--Fila--\n");
    for(i=0;i<Fila->Tamanho;i++){
        printf("(%d) - Chave: %d \n",(i), Fila->Item[i].Chave);
    }
}

void main(){
    int i;
    TipoFila fila;
    TipoItem aux;
    FFVazia(&fila);

    for(i=0;i<20;i++){
        aux.Chave = i;
        Enfileira(aux,&fila);
    }

    Imprime(&fila);
}
