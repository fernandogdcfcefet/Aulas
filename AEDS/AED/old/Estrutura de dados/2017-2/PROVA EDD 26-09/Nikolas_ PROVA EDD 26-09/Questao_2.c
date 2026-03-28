#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAXTAM 6

typedef int TipoApontador;

typedef int TipoChave;
typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;
typedef struct {
  TipoItem Item[MAXTAM];
  TipoChave Tamanho;
  TipoApontador Frente, Tras;
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 0;
  Fila->Tras = Fila->Frente;
  Fila->Tamanho = 0;
}

int Vazia(TipoFila Fila)
{
    if((Fila.Frente == Fila.Tras) && (Fila.Tamanho == 0))
        return 1;
    else
        return 0;
}

void Enfileira(TipoItem x, TipoFila *Fila)
{
    if ((Fila->Tamanho == MAXTAM))
        printf(" Erro   fila esta  cheia\n");
    else {
        Fila->Item[Fila->Tras] = x;
        Fila->Tras = (Fila->Tras % MAXTAM) + 1;
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
    if(!Vazia(*Fila)){
        if(Fila->Frente < Fila->Tras){
            for(i=Fila->Frente; i<Fila->Tamanho ;i++)
                printf("%d ",Fila->Item[i].Chave );
        }else{
            for(i=Fila->Frente; i<MAXTAM ;i++)
                printf("%d ",Fila->Item[i].Chave );
            for(i=0; i<Fila->Tras; i++)
                printf("%d ",Fila->Item[i].Chave );
        }
    }else{
        printf("Fila esta vazia\n");
    }
}

int main(int argc, char *argv[])
{
    TipoFila F;
    FFVazia(&F);
     Imprime(&F);
    TipoItem I;

    I.Chave = 5;
    Enfileira(I, &F);
    I.Chave = 4;
    Enfileira(I, &F);
    I.Chave = 3;
    Enfileira(I, &F);
    I.Chave = 2;
    Enfileira(I, &F);
    I.Chave = 1;
    Enfileira(I, &F);
    I.Chave = 0;
    Enfileira(I, &F);
    I.Chave = 0;
    Enfileira(I, &F);


    Imprime(&F);

    return 0;
}
