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

void Empilha(TipoItem Item, TipoFila *Fila) {
	TipoItem ItemAux;
	TipoFila FilaAux;
	FFVazia(&FilaAux);

	while(!Vazia(*Fila)) {      //guarda os elementos em uma fila temporária
		 Desenfileira(&*Fila, &ItemAux);
		 Enfileira(ItemAux, &FilaAux); 
	}
	
	Enfileira(Item, &*Fila);      //adiciona o item no topo
	
	while(!Vazia(FilaAux)) {     //volta os elementos para a fila principal
		 Desenfileira(&FilaAux, &ItemAux);
		 Enfileira(ItemAux, &*Fila);	  
	}
}

int main(int argc, char *argv[])
{
	TipoFila MF;
	TipoItem Item;
	FFVazia(&MF);
	Item.Chave = 1;
	Enfileira(Item, &MF);
	Item.Chave = 2;
	Enfileira(Item, &MF);
	
	Item.Chave = 3;
	Empilha(Item, &MF);

}
