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
void imprime(TipoFila ML){
    for(int i=0;i<ML.tamanho;i++){
        printf("%d",ML.Item[i].Chave);
    }
}
void FFVazia(TipoFila *Fila)
{ Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
  Fila->tamanho=0;
}

int Vazia(TipoFila Fila)
{ return (Fila.tamanho==0); }

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->tamanho>=MAXTAM)
  printf(" Erro   fila est  a  cheia\n");
  else {
        Fila->Item[Fila->tamanho]=x;
        Fila->Item[Fila->Tras - 1] = x;
        Fila->Tras = Fila->Tras % MAXTAM + 1;
        Fila->tamanho++;
       }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
         Fila->tamanho--;
       }
}
int main(int argc, char *argv[])
{
    TipoFila f;
    TipoItem a;
    FFVazia(&f);
    a.Chave=1;
    Enfileira(a,&f);
    a.Chave=2;
    Enfileira(a,&f);
    a.Chave=3;
    Enfileira(a,&f);
    imprime(f);
}
