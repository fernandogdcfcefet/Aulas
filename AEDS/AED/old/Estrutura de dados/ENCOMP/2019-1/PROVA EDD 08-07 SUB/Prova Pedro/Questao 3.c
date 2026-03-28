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

void imprime(TipoFila MF){
    TipoApontador aux = 0;
    while(aux != MF.Tras-1){
        printf("%d\n", MF.Item[aux]);
        aux++;
    }
}

void concatena(TipoFila *F1, TipoFila *F2){
    TipoApontador aux = 0;
    while(aux != F2->Tras-1){
        Enfileira(F2->Item[aux],F1);
        aux++;
    }
    FFVazia(F2);
}

int main()
{
    TipoItem coisa1,coisa2,coisa3,coisa4;
    coisa1.Chave = 1;
    coisa2.Chave = 2;
    coisa3.Chave = 3;
    coisa4.Chave = 4;


    TipoFila MF1,MF2;

    FFVazia(&MF1);
    FFVazia(&MF2);

    Enfileira(coisa1,&MF1);
    Enfileira(coisa2,&MF2);
    Enfileira(coisa3,&MF1);
    Enfileira(coisa4,&MF2);


    imprime(MF1);
    imprime(MF2);

    printf("Depois de concatenar:\n");

    concatena(&MF1,&MF2);

    imprime(MF1);



}
