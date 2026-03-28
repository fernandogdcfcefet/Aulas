#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAXTAM  4

typedef int TipoApontador;

typedef int TipoChave;
typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;
typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Frente, Tras;
  int tam;
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
  Fila->tam=0;
}

int Vazia(TipoFila Fila)
{ return (Fila.Frente == Fila.Tras); }

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->Tras % MAXTAM + 1 == Fila->Frente)
  printf(" Erro   fila est  a  cheia\n");
  else { Fila->Item[Fila->Tras - 1] = x;
         Fila->Tras = Fila->Tras % MAXTAM + 1;
         Fila->tam++;
       }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
         Fila->tam++;
       }
}

void ImprimeFila(TipoFila fila)
{
	int i;
	for(i=0;i<fila.tam;i++)
	{
		printf("\n %d",fila.Item[i].Chave);
	}
}

int main()
{
	
	TipoItem IT1,IT2,IT3,IT4,IT5;
	
	IT1.Chave=1;
	IT2.Chave=2;
	IT3.Chave=3;
	IT4.Chave=4;
	IT5.Chave=5;
	
	TipoFila fila;
	FFVazia(&fila);
	ImprimeFila(fila);
	
	Enfileira(IT1,&fila);
	Enfileira(IT2,&fila);
	Enfileira(IT3,&fila);
	Enfileira(IT4,&fila);
	
	Enfileira(IT5,&fila);
	
	ImprimeFila(fila);
}
