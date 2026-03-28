#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAX 10

typedef int TipoChave;
typedef struct {
  int Chave;
  /* outros componentes */
} TipoItem;
typedef struct TipoCelula *TipoApontador;
typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;
typedef struct {
  TipoApontador Fundo, Topo;
  int Tamanho;
} TipoPilha;


int Tamanho(TipoPilha Pilha)
{ return (Pilha.Tamanho); }

void Inverte(){
    TipoApontador aux;
    int a,i,count;
    a = Tamaho(TipoPilha Pilha);
    for (i=0;i<a;i++){
        if (i!=count){
            a = TipoApontador->Prox
            TipoItem->Chave = TipoPilha->Fundo;
        }
    }
}

int main()
{
}
