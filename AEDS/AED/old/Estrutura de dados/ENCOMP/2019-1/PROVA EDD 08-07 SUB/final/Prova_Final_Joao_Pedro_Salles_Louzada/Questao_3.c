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
         Fila->Tras = Fila->Tras %(int) MAXTAM + 1;
       }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
       }
}

/**=====================================================================================================================================================================================*/

void concatenaDuasFilas(TipoFila* Fila_destino, TipoFila fila1, TipoFila* fila2){

    TipoApontador pont_aux1 = fila1.Frente;     /**      Declaração e inicialização de auxiliadores       */
    TipoApontador pont_aux2 = fila2->Frente;    /**                                                       */
    TipoFila fila_aux; FFVazia(&fila_aux);      /**                                                       */
    TipoItem item_aux;                          /**                                                       */

    while(pont_aux1 != NULL) {  /** Percorre a primeira fila, inserindo os elementos na fila de destino */
        Desenfileira(&fila1, &item_aux);
        Enfileira(item_aux, &Fila_destino);
        pont_aux1 = pont_aux1->Prox;
    }
    while(pont_aux2 != NULL) { /** Percorre a segunda fila, inserindo os elementos na fila de destino, no fim a fila 2 será esvaziada pelas repetidas chamadas da função desenfileira */
        Desenfileira(&fila2, &item_aux);
        Enfileira(item_aux, &Fila_destino);
        pont_aux2 = pont_aux2->Prox;
    }

}

/**=====================================================================================================================================================================================*/

int main()
{
    TipoFila MinhaFila1, MinhaFila2, MinhaFila3;
    TipoItem tipo1 = 1, tipo2 = 2, tipo3 = 3, tipo4 = 4, tipo5 = 5;
    Enfileira(tipo1, &MinhaFila1);
    Enflieira(tipo2, &MinhaFila1);
    Enflieira(tipo3, &MinhaFila2);
    Enflieira(tipo4, &MinhaFila2);
    Enflieira(tipo5, &MinhaFila2);

    concatenaDuasFilas(&MinhaFila3, MinhaFila1, &MinhaFila2);

    return 0;
}
