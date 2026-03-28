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
  TipoApontador Frente, Tras,cont;
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
  Fila->cont=0;
}

int Vazia(TipoFila Fila)
{ return (Fila.Frente == Fila.Tras); }

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->Tras % MAXTAM + 1 == Fila->Frente)
  printf(" Erro   fila est  a  cheia\n");
  else { Fila->Item[Fila->Tras - 1] = x;
         Fila->Tras = Fila->Tras % MAXTAM + 1;
         Fila->cont++;
    }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
       }
}

void Imprime(TipoFila *Fila){
    int i;
    for(i=0;i<Fila->Tras-1;i++){
        printf("%d\n",Fila->Item[i].Chave);
    }
    if(Vazia(*Fila)) printf("i\n");
}

void Empilha(TipoItem x, TipoFila *Fila1, TipoFila *Fila2){
    int i;
    for(i=0;i<Fila1->Tras-2;i++){
        TipoItem item;
        Desenfileira(Fila1,&item);
        printf("%d\n",item.Chave);
        Enfileira(item,Fila2);
    }
    Enfileira(x,Fila1);
    for(i=0;i<Fila2->Tras-2;i++){
        TipoItem item;
        Desenfileira(Fila2,&item);
        Enfileira(item,Fila1);
        if(Vazia(*Fila2))printf("ola");
    }
}

void Desempilha(TipoItem x, TipoFila *Fila1, TipoFila *Fila2){
    int i;
    for(i=0;i<Fila1->Tras-2;i++){
        TipoItem item;
        Enfileira(item,Fila2);
        Desenfileira(Fila1,&item);
    }
    TipoItem y;
    Desenfileira(Fila1,&y);
    for(i=0;i<Fila2->Tras-1;i++){
        TipoItem item;
        Desenfileira(Fila2,&item);
        Enfileira(item,Fila1);
    }
}

int main(){

    TipoFila Fila1,Fila2;
    FFVazia(&Fila1);
    FFVazia(&Fila2);
    TipoItem item;
    item.Chave=1;
    Empilha(item,&Fila1,&Fila2);

    item.Chave=2;
    Empilha(item,&Fila1,&Fila2);

    item.Chave=3;
    Empilha(item,&Fila1,&Fila2);

    Imprime(&Fila1);

    return 0;
}
