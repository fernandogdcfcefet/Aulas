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
  int Tamanho;
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
  Fila->Tamanho=0;

}

int Vazia(TipoFila Fila)
{ return (Fila.Tamanho == 0); }

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->Tras % MAXTAM +1 == Fila->Frente)
  printf(" Erro   fila est  a  cheia\n");
  else { Fila->Item[Fila->Tras - 1]  = x;
         Fila->Tras =Fila->Tras % MAXTAM + 1;
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
void Imprime(TipoFila Fila){
int aux;
    if(Fila.Frente<Fila.Tras){
        /*for(aux=Fila.Frente-1;aux<=Fila.Tamanho-1;aux++){
            printf("%d",Fila.Item[aux].Chave);

        }*/
        for(aux=0;aux<Fila.Tras-1;aux++){
            printf("\t%d",Fila.Item[aux].Chave);
        }
    }
    else if(Fila.Frente==Fila.Tras){
        for(aux=Fila.Frente-1;aux<=Fila.Tamanho-1;aux++){
            printf("\t%d",Fila.Item[aux].Chave);

        }
    }
    else{
        for(aux=Fila.Frente-1;aux<Fila.Tras-1;aux++){
            printf("\t%d",Fila.Item[aux].Chave);

        }
    }


}
int main()
{

    TipoFila Mf;
    TipoItem Item;
    FFVazia(&Mf);
    Vazia(Mf);

    Item.Chave=1;
    Enfileira(Item,&Mf);
    Item.Chave=2;
    Enfileira(Item,&Mf);
    Item.Chave=3;
    Enfileira(Item,&Mf);
    Item.Chave=4;
    Enfileira(Item,&Mf);
    Imprime(Mf);
    Vazia(Mf);

    return 0;
}

