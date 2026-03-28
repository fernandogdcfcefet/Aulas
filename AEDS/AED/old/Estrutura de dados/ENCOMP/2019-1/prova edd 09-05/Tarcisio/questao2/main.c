#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 10
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
void Imprime(TipoFila Fila)
{
    if (Vazia(Fila))
    printf("Erro fila esta vazia\n");
    else{
        TipoApontador aux;
        if(Fila.Frente<Fila.Tras)
        {
            for(aux=Fila.Frente-1;aux<Fila.Tras-1;aux++)
            {
                printf("%d \n", Fila.Item[aux].Chave);
            }
        }
        else{
            if(Fila.Frente<Fila.Tras)
            {
                for(aux=Fila.Frente-1;aux<MAXTAM-1;aux++)
                {
                    printf("%d \n", Fila.Item[aux].Chave);
                }
                for(aux=0;aux<Fila.Tras-1;aux++)
                {
                    printf("%d \n", Fila.Item[aux].Chave);
                }
                printf("%d \n", Fila.Item[aux].Chave);
            }
        }

    }
}

int main()
{
    TipoFila MF;
    FFVazia(&MF);
    TipoItem item;
    for(int i=0;i<3;i++)
        {item.Chave=rand()%10;
        Enfileira(item, &MF);
        }
    Imprime(MF);
    Desenfileira(&MF, &item);
    item.Chave=rand()%10;
        Enfileira(item, &MF);
        Imprime(MF);
    return 0;
}
