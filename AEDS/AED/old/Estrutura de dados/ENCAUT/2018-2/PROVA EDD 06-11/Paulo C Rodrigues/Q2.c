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
  printf(" Erro   fila est  a  cheia\n");
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

void imprimeFila(TipoFila Fila){
  int i;
  for(i=Fila.Frente-1; i != Fila.Tras-1; (i+1) % MAXTAM){
    printf("%d", Fila.Item[i].Chave);
  }
}

int main(int argc, char *argv[]){
    TipoFila MF;
    TipoItem f1, f2, f3;
    f1.Chave = 1;
    f2.Chave = 2;
    f3.Chave = 3;

    FFVazia(&MF);

   //Enfileira(f1, &MF);
   //Enfileira(f2, &MF);
   //Enfileira(f3, &MF);

    //Desenfileira(&MF, &f1);

    imprimeFila(MF);

    return 0;
}
