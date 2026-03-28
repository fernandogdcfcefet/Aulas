#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAXTAM  10

typedef int TipoApontador;
typedef int TipoChave;

typedef struct {
  TipoChave Chave;
} TipoItem;

typedef struct {
    int Tamanho;
    TipoItem Item[MAXTAM];
} TipoFila;

void FFVazia(TipoFila *Fila){
     Fila->Tamanho = 0;
}

int Vazia(TipoFila Fila)
{ return (Fila.Tamanho == 0); }

void Enfileira(TipoItem x, TipoFila *Fila){
    if(Fila->Tamanho == MAXTAM){
        printf(" Erro   fila esta  cheia\n");
    }else{
        Fila->Item[Fila->Tamanho] = x;
        Fila->Tamanho++;
       }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item){
    int i;
     if (Vazia(*Fila)){
        printf("Erro fila esta vazia\n");
    }else {
        Fila->Item[0] = *Item; //Pois sempre quem ira sair da fila é o primeiro item.
        for(i=0;i<Fila->Tamanho-1;i++){
            Fila->Item[i] = Fila->Item[i+1]; //"Puxando" todos os elementos da fila para a esquerda.
         }
         Fila->Tamanho--;
       }
}

void Imprime(TipoFila *Fila){
    int i;
    TipoChave aux;

    for(i=0;i<Fila->Tamanho;i++){
        aux = Fila->Item[i].Chave;
        printf("(%d): %d\n",i+1,aux);

    }
}

int main(int argc, char *argv[])
{
    TipoFila Fila;
    FFVazia(&Fila);
    int i;
    TipoItem aux;

    for(i=0;i<MAXTAM;i++){
        aux.Chave = i;
        Enfileira(aux, &Fila);
    }
    Imprime(&Fila);
}

