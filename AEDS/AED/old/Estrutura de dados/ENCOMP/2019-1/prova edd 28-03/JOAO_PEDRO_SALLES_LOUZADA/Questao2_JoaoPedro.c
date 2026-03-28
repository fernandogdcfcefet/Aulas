#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINHA 3
#define COLUNA 3

void lematriz(int mat[LINHA][COLUNA])
{
	int i, j;
	for(i = 0; i < LINHA; i++)
		for (j = 0; j < COLUNA; j++)
		{
			printf("Introduza os elementos da matriz: \n");
			printf("O elemento da linha %d coluna %d: \n", i, j);
			 scanf("%d", &mat[i][j]);
		}
}

void imprimematriz (int mat[LINHA][COLUNA])
{
	int i, j;
	for(i = 0; i < LINHA; i++)
		for (j = 0; j < COLUNA; j++)
		{
			printf("%d", mat[i][j]);
		}
		printf("\n");
}

void minimax (int mat[LINHA][COLUNA], int *menor, int pos[0][0])
{
	int i, j, x = 0, y = 0;
	for(i = 0; i < LINHA; i++)
	{
		for (j = 0; j < COLUNA; j++)
		{
			if (mat[i][j] > x)
			{
				x = mat[i][j]; 
				y = i;
			}
		}
	}			

	for (j = 0; j < COLUNA; j++)
	{
		if (mat[y][j] < x)
		{
			*menor = x;
			pos[0][0] = mat[y][j];
		}
	}
}

int main() {
	
	int menor;
	int vet[LINHA][COLUNA], posicao[0][0];	

	lematriz(vet);
	imprimematriz(vet);
	minimax(vet, &menor, posicao);
	printf("O elemento minimax: %d\n", menor);
	printf("A posicao do elemento minimax: %d", posicao[0][0]);
	
	return 0;
}

