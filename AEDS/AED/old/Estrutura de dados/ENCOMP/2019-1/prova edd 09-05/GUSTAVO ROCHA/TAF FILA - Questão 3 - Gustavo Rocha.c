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

void Empilha(TipoItem x, TipoFila *Fila1, TipoFila *Fila2)
{
	int i;
	TipoItem aux;
	
	if(Vazia(*Fila1))
		Enfileira(x, Fila1);
	else
	{	
		for(i = Fila1->Frente-1;!Vazia(*Fila1);i++){
			Desenfileira(Fila1, &aux);
			Enfileira(aux, Fila2);
		}
		
		Enfileira(x, Fila1);
		
		for(i = Fila2->Frente-1;!Vazia(*Fila2);i++){
			Desenfileira(Fila2, &aux);
			Enfileira(aux, Fila1);
		}
	}
}

void Imprime(TipoFila MF)
{
	if(!Vazia(MF))
	{
		int i = MF.Frente-1;
		while(i != (MF.Tras % MAXTAM-1))
		{
			printf("%d\n", MF.Item[i].Chave);
			i++;
		}
	}
}

int main()
{
	TipoFila f1, f2;
	TipoItem aux;
	
	FFVazia(&f1);
	FFVazia(&f2);
	
	aux.Chave = 3;
	Empilha(aux, &f1, &f2);
	
	aux.Chave = 4;
	Empilha(aux, &f1, &f2);
	
	aux.Chave = 5;
	Empilha(aux, &f1, &f2);
	
	aux.Chave = 6;
	Empilha(aux, &f1, &f2);
	
	
	Imprime(f1);	
	
}
