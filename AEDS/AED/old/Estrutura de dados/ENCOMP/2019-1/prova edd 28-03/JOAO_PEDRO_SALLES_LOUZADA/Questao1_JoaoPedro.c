#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 60

typedef struct struct1
{
	char ano[12][30];
} DATA;

typedef struct struct2
{
	char[N][N] compromissos;
	DATA data;	
} AGENDA;

void levetor (tipo1, tipo2)
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			printf("Introduza os elementos do vetor:\n")
			printf("O elemento da linha %d coluna %d: \n", i, j);
			 scanf("%d", &vet[i][j]);

		}
}


int main() {
	
	
	levetor(AGENDA.compromissos);
	
	
	
	return 0;
}
