#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAXTAM  2

typedef int TipoApontador;

typedef int TipoChave;
typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;
typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Frente, Tras;
  int Tamanho;
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
  Fila->Tamanho = 0;
}

int Vazia(TipoFila Fila)
{ return (Fila.Tamanho == 0); }

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->Tras % MAXTAM + 1 == Fila->Frente)
  printf(" Erro   fila esta  cheia\n");
    else { Fila->Item[Fila->Tamanho] = x;
         Fila->Tras = Fila->Tamanho % MAXTAM + 1;
         Fila->Tamanho ++;
       }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
         Fila->Tamanho--;
       }
}

void Empilha(TipoItem x, TipoFila *Fila1, TipoFila *Fila2){
    if(Vazia(*Fila1)) {Enfileira(x,Fila1);return;};
    if(Vazia(*Fila2)) {Enfileira(x,Fila2);return;};
    if(Fila1->Tras==Fila1->Tamanho)
        Enfileira(x,Fila2);
    if(Fila2->Tras==Fila2->Tamanho)
            Enfileira(x,Fila1);
}

void Desempilha(TipoItem x, TipoFila *Fila1, TipoFila *Fila2){
    TipoApontador aux = Fila1->Frente;
    int cont=0,cont1=0;
    while(aux!=Fila1->Tamanho){
        if(Fila1->Item->Chave == x.Chave){
            Desenfileira(Fila1,Fila1->Item);
            cont++;
        }
        else aux=aux++;
    }
    if(cont=0){
        while(aux!=Fila2->Tamanho){
        if(Fila2->Item->Chave == x.Chave){
            Desenfileira(Fila2,Fila2->Item);
            cont1++;
        }
        else aux=aux++;
        }
    }
    if(cont1++ == 0) printf("O item nao esta contido na pilha.");
}

int main(int argc, char *argv[])
{
    TipoFila F1, F2;
    TipoItem item1, item2;
    item1.Chave = 1;
    Empilha(item1,&F1,&F2);
    item1.Chave = 3;
    Empilha(item1,&F1,&F2);
    item2.Chave = 10;
    Empilha(item2,&F1,&F2);
    item2.Chave = 4;
    Empilha(item2,&F1,&F2);
    return 0;
}
