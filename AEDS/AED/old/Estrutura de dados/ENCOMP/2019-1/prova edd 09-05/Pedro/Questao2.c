#include <stdio.h>
#include <stdlib.h>

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

void imprime(TipoFila Fila){

    TipoApontador aux = Fila.Frente -1;

    while(aux < Fila.Tras -1){
        printf("%d\n",Fila.Item[aux].Chave);
        aux++;
    }


}

int main()
{

    TipoFila MF;

    FFVazia(&MF);

    TipoItem coisa1;
    TipoItem coisa2;
    TipoItem coisa3;
    TipoItem coisa4;

    coisa1.Chave = 1;
    coisa2.Chave = 2;
    coisa3.Chave = 3;
    coisa4.Chave = 4;

    Enfileira(coisa1,&MF);
    Enfileira(coisa2,&MF);
    Enfileira(coisa3,&MF);
    Enfileira(coisa4,&MF);

    imprime(MF);





}
