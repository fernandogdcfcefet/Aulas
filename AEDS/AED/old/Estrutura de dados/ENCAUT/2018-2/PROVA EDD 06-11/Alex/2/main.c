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
  int tam;
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 0;
  Fila->Tras = Fila->Frente;
  Fila->tam=0;
}

int Vazia(TipoFila Fila)
{
    if(Fila.tam==0){
        return 1;
    }
    else return 0;;
}

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->tam==MAXTAM)
  printf(" Erro fila esta cheia\n");
  else { Fila->Item[Fila->Tras] = x;
         Fila->Tras = Fila->Tras % MAXTAM +1;
       }
  Fila->tam=Fila->tam+1;
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente];
         Fila->Frente = Fila->Frente % MAXTAM;
       }
}

void imprime(TipoFila *Fila){
    int i;
    for(i=Fila->Frente;i<Fila->Tras;i++){
        printf("\n%d",Fila->Item[i].Chave);
    }
    for(i=0;i<Fila->Frente;i++){
        printf("\n%d",Fila->Item[i].Chave);
    }
}

int main(int argc, char *argv[])
{
    TipoFila Fila;
    FFVazia(&Fila);
    TipoItem a;
    a.Chave=1;
    Enfileira(a,&Fila);
    a.Chave=2;
    Enfileira(a,&Fila);
    a.Chave=3;
    Enfileira(a,&Fila);
    a.Chave=4;
    Enfileira(a,&Fila);
    imprime(&Fila);

    printf("\n\n%d",Fila.tam);

}
