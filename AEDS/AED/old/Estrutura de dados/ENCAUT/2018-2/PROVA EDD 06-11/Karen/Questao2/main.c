#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAXTAM 3

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

void imprime(TipoFila Fila){
    int i;
    if(Fila.Frente < Fila.Tras){
        for(i=Fila.Frente-1;i<Fila.Tamanho;i++)
            printf("%d ",Fila.Item[i].Chave);
    }
    else if(Fila.Frente == Fila.Tras){
        for(i=Fila.Frente-1;i<Fila.Tamanho;i++)
            printf("%d",Fila.Item[i].Chave);
    }
    else {
        for(i=Fila.Frente-1;i<Fila.Tras-1;i++)
            printf("%d",Fila.Item[i].Chave);
    }
}

int main(int argc, char *argv[])
{
    TipoFila MF;
    TipoItem item;
    FFVazia(&MF);
    item.Chave = 5;
    Enfileira(item,&MF);
    item.Chave = 10;
    Enfileira(item,&MF);
    item.Chave = 9;
    Enfileira(item,&MF);
    imprime(MF);
}
