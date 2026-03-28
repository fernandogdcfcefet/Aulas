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
{
	Fila->Frente = 1; //recebe 0 para não inutilizar uma posição, porém não deu tempo de ajustar as funçoes pra funcionarem de acordo
	Fila->Tras = 1;
}

int Vazia(TipoFila Fila)
{
	return (Fila.Frente == Fila.Tras);
}

void Enfileira(TipoItem x, TipoFila *Fila)
{
	if (Fila->Tras % MAXTAM + 1  == Fila->Frente)
		printf(" Erro fila esta cheia\n");
	else
	{
		Fila->Item[Fila->Tras - 1] = x;
        Fila->Tras = Fila->Tras % MAXTAM + 1;
    }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{
	if (Vazia(*Fila))
		printf("Erro fila esta vazia\n");
	else
	{
		*Item = Fila->Item[Fila->Frente - 1];
        Fila->Frente = Fila->Frente % MAXTAM + 1;
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
	TipoFila MF;
	TipoItem x;

	FFVazia(&MF);

	x.Chave = 3;
	Enfileira(x, &MF);

	x.Chave = 4;
	Enfileira(x, &MF);

	x.Chave = 5;
	Enfileira(x, &MF);

	x.Chave = 6;
	Enfileira(x, &MF);

	Imprime(MF);

}
