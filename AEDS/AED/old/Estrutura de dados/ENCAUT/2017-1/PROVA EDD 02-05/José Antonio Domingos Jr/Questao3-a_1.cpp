#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAXTAM  1000
// OBS: Código da letra-b, usado para fazer a letra-a.

typedef int TipoApontador;

typedef int TipoChave;
typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;

typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Frente;
  int n;//numero de elementos da fila
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 0;
  Fila->n = 0;
}

int Vazia(TipoFila Fila)
{ return (Fila.n == 0); }

void Enfileira(TipoItem x, TipoFila *Fila)

{ if (Fila->n == MAXTAM)
  printf(" Erro   fila esta  cheia\n");
  
  else { (Fila->Item[(Fila->n + Fila->Frente)%MAXTAM] = x;
         Fila->n = Fila->n + 1;
       }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)

{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  
  else { *Item = Fila->Item[Fila->Frente];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
       }
}

void Imprime(TipoFila *Fila){
	
	int i;
	while(i< Fila->n){
		
		printf("\nItem: %d", i);
		printf("\nChave: %d", Fila->Item[(Fila->Frente + i)%MAXTAM].Chave);
		
	i++;	
		
	}
	
	
	
}






int main(int argc, char *argv[])
{
	
	
	
	
	
}
