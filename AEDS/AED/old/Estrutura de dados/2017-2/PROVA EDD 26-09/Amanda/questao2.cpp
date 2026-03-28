#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAXTAM  10

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
	int i;
	
	aux=Fila->Frente;
	
		if(Vazia(*Fila))printf("Erro fila esta vazia\n");
			for(i=0;i<MAXTAM;i++){
				
				printf("%d ",Fila->Item[i].Chave);
				
			}

	
	
}

int main(int argc, char *argv[])
{
	TipoFila MF;
	TipoItem item;
	FFVazia(&MF);
	item.Chave=1;
	Enfileira(item,&MF);
	item.Chave=2;
	Enfileira(item,&MF);
	item.Chave=3;
	Enfileira(item,&MF);
	item.Chave=4;
	Enfileira(item,&MF);
	Imprime(&MF);
}
