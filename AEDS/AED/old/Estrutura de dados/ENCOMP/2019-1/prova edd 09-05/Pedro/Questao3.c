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

void Empilha(TipoItem x, TipoFila *Fila1, TipoFila *Fila2){

    int i;
    TipoItem item;

    Enfileira(x,&Fila1);
    Desenfileira(Fila2,&item);
    Enfileira(x,&Fila2);


}

void Imprime(TipoFila Fila){

    TipoApontador aux = Fila.Frente -1;

    while(aux < Fila.Tras -1){
        printf("%d\n",Fila.Item[aux].Chave);
        aux++;
    }


}

void Desempilha(TipoItem *x, TipoFila *Fila1, TipoFila *Fila2){
    int i;
    for(i = 0; i <= Fila1->Tras; i++){
            if(i == Fila1.Tras){
                Desenfileira(Fila1,&item);
                Enfileira(Fila1,item);
            }
    }

}

int main()
{

    TipoFila F1,F2;

    FFVazia(&F1);
    FFVazia(&F2);

    TipoItem i1,i2,i3;

    i1.Chave = 1;
    i2.Chave = 2;
    i3.Chave = 3;

    Enfileira(i1,&F1);
    Enfileira(i2,&F1);
    Enfileira(i3,&F1);
    Enfileira(i1,&F2);
    Enfileira(i2,&F2);
    Enfileira(i3,&F2);

     Imprime(F1);

    Empilha(i1,&F1,&F2);

    Imprime(F1);

}
