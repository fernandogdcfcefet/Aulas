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
  int Tamanho;
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

//Pocedimento imprime
void Imprime(TipoFila *Fila){
    int i;
    if(Fila.Frente > Fila.Tras){
        for(i=Fila.Frente-1; i<Fila.Tamanho; i++)
            printf("%d \t", Fila.Item[i].Chave);
        for(i=0; i<=Fila.Tras-1; i++)
            printf("%d \t", Fila.Item[i].Chave);
    }else if(Fila.Frente == Fila.Tras){
        for(i=Fila.Frente-1; i<Fila.Tamanho; i++)
            printf("%d \t", Fila.Item[i].Chave);
    }else{
        for(i=Fila.Frente-1; i<Fila.Tras-1; i++)
            printf("%d \t", Fila.Item[i].Chave);
    }
    printf("\n\n");
}

int main(int argc, char *argv[])
{
    TipoFila MF; // Cria fila
    FFVazia(&MF); // Faz fila vazia
    TipoItem Item;
    //Insere itens na pilha
    Item.Chave = 1;
    Enfileira(Item, &MF);
    Item.Chave = 2;
    Enfileira(Item, &MF);
    Item.Chave = 3;
    Enfileira(Item, &MF);
    Item.Chave = 4;
    Enfileira(Item, &MF);
    Item.Chave = 5;
    Enfileira(Item, &MF);

    Imprime(MF);
}
