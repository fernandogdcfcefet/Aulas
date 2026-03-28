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
void Imprime(TipoFila *Fila){
	TipoApontador aux;
	aux=Fila->Frente;
	
	while(aux!=NULL){
		printf("%d", Fila->Item.Chave);	
		aux=aux->Frente;
	}
}

int main(int argc, char *argv[]){
	TipoFila Fila;
	FFVazia(&Fila);
	
	TipoItem item1, item2, item3;
	item1.Chave=20;
	item2.Chave=21;
	item3.Chave=22;
	
	Enfileira(item1,&Fila);
	Enfileira(item2,&Fila);
	Enfileira(item3,&Fila);
	
	Imprime(&Fila);
	
	
	
	
	system("pause");
	return 0;
}
