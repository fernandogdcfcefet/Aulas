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
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
}

int Vazia(TipoFila Fila)
{ return (Fila.Frente == Fila.Tras); }

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->Tras % MAXTAM + 1 == Fila->Frente)
  printf(" Erro   fila esta  cheia\n");
  else { Fila->Item[Fila->Tras - 1] = x;
         Fila->Tras = Fila->Tras % MAXTAM + 1;
       }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
       }
}

void Empilha(TipoItem x, TipoFila *Fila1, TipoFila *Fila2){
    TipoItem aux;
    while(!Vazia(*Fila1)){
        Desenfileira(Fila1,&aux);
        Enfileira(aux, Fila2);
    }
    Enfileira(x,Fila1);
    while(!Vazia(*Fila2)){
        Desenfileira(Fila2,&aux);
        Enfileira(aux, Fila1);
    }
}

void Desempilha(TipoItem x, TipoFila *Fila1, TipoFila *Fila2){

}

int main(int argc, char *argv[])
{
    TipoFila Fila1, Fila2;
    FFVazia(&Fila1);
    FFVazia(&Fila2);
    TipoItem a;
    a.Chave=1;
    Empilha(a,&Fila1,&Fila2);
    a.Chave=2;
    Empilha(a,&Fila1,&Fila2);
    a.Chave=3;
    Empilha(a,&Fila1,&Fila2);
    a.Chave=4;
    Empilha(a,&Fila1,&Fila2);
    a.Chave=5;
    Empilha(a,&Fila1,&Fila2);


}
