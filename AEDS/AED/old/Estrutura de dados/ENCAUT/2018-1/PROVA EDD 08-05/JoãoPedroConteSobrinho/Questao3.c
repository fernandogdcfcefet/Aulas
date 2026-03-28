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
  Fila->Tamanho = 0;
}

int Vazia(TipoFila Fila)
{ return (Fila.Tamanho == 0); }

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->Tras % MAXTAM + 1 == Fila->Frente)
  printf(" Erro   fila est  a  cheia\n");
  else { Fila->Item[Fila->Tras - 1] = x;
         Fila->Tras = Fila->Tras % MAXTAM + 1;
        Fila->Tamanho++;
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

void ExcluiNegativos(TipoFila *Fila){ // Tentei fazer com procedimento de imprime, mas deu errado
    int i; // inteiro auxiliar
    TipoItem ItemAux; // Item auxiliar
    int tamanho = Fila->Tamanho; // Tamanho da fila
    for(i=0; i<tamanho; i++) //percorr a fila (errado, pois deveria ser como o imprime)
        if(Fila->Item[i].Chave<0)//se achar item negativo
            Desenfileira(Fila, &ItemAux);//retira ele da fila
}

void Imprime(TipoFila Fila){ /*Procedimento de imprimir*/
    int i;
    if(Fila.Frente > Fila.Tras){
        for(i=Fila.Frente-1; i<Fila.Tamanho; i++)
            printf("%d \t", Fila.Item[i].Chave);
        for(i=0; i<=Fila.Tras-1; i++)
            printf("%d \t", Fila.Item[i].Chave);
    }else if(Fila.Frente == Fila.Tras){
        for(i=Fila.Frente-1; i<Fila.Tamanho; i++)
            printf("%d \t", Fila.Item[i].Chave);
    }else /*if(Fila.Frente < Fila.Tras)*/{
        for(i=Fila.Frente-1; i<Fila.Tras-1; i++)
            printf("%d \t", Fila.Item[i].Chave);
    }
    printf("\n\n");
}

int main()
{
    TipoFila MF; // Cria fila
    FFVazia(&MF); // Faz ela vazia
    TipoItem Item; // Cria item

    //Enfileira
    Item.Chave = -1;
    Enfileira(Item, &MF);
    Item.Chave = 2;
    Enfileira(Item, &MF);
    Item.Chave = -3;
    Enfileira(Item, &MF);
    Item.Chave = 4;
    Enfileira(Item, &MF);
    Item.Chave = 5;
    Enfileira(Item, &MF);
    //Imprime
    Imprime(MF);

    //Exclui negativos e imprime
    ExcluiNegativos(&MF);
    Imprime(MF);
}
