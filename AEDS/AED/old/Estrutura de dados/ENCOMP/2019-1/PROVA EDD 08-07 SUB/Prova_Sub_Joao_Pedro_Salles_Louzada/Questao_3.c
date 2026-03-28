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
/**-------------------------------------------------------------------------------------------------------------------------------------------------------*/
void FFVazia(TipoFila *Fila)
{ Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
}
/**-------------------------------------------------------------------------------------------------------------------------------------------------------*/
int Vazia(TipoFila Fila)
{ return (Fila.Frente == Fila.Tras); }
/**-------------------------------------------------------------------------------------------------------------------------------------------------------*/
void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->Tras % MAXTAM + 1 == Fila->Frente)
  printf(" Erro   fila est  a  cheia\n");
  else { Fila->Item[Fila->Tras - 1] = x;
         Fila->Tras = Fila->Tras % MAXTAM + 1;
       }
}
/**-------------------------------------------------------------------------------------------------------------------------------------------------------*/
void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
       }
}
/**-------------------------------------------------------------------------------------------------------------------------------------------------------*/
void concatena_duas_filas(TipoFila *F1, TipoFila *F2){
    TipoItem aux;
    TipoFila aux1 = F1;
    TipoFila aux2 = F2;

        while(aux2->Frente != aux2->Tras) {
            Enfileira(&aux, F1);
            Desenfileira(F2, &aux);
            aux2->Frente = aux2->Frente+1;
        }

    Enfileira(&aux, F1);
    Desenfileira(F2, &aux);
    FFVazia(F2);
}
/**-------------------------------------------------------------------------------------------------------------------------------------------------------*/
int main()
{

}
