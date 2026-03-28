#include<stdio.h>
#include<conio.h>
#define LINHA 4
#define COLUNA 4
int Minimax(int mat[LINHA][COLUNA],int *linhaminimax, int *colunaminimax)
{
	int i,j,maiorl,maiorc,maiore=mat[0][0],minimax=mat[0][0];
	for(i=0;i<LINHA;i++)
	{
		for(j=0;j<COLUNA;j++)
		{
			maiore<mat[i][j];
			maiore=mat[i][j];
			maiorl=i;
			maiorc=j;
		}
	}
	minimax=mat[maiorl][0];
	*linhaminimax=maiorl;
	for(i=0;i<COLUNA;i++)
	{
		if(minimax>mat[maiorl][i])
		{
			minimax=mat[maiorl][i];
			*colunaminimax=i;
		}
	}
	return minimax;
}
void preencheMatriz(int mat[LINHA][COLUNA])
{
	int i,j;
	for(i=0;i<LINHA;i++)
	{
		for(j=0;j<COLUNA;j++)
		{
			mat[i][j]=(j+i);
		}
	}
}
void imprimeMatriz(int mat[LINHA][COLUNA])
{
	int i,j;
	for(i=0;i<LINHA;i++)
	{
		printf("\n");
		for(j=0;j<COLUNA;j++)
		{
			printf(" %d",mat[i][j]);
		}
	}
}
int main()
{
	int l=0,c=0;
	int matriz[LINHA][COLUNA];
	preencheMatriz(matriz);
	imprimeMatriz(matriz);
	printf("\nMinimax: %d",Minimax(matriz,&l,&c));
	printf("\nLinha: %d \nColuna: %d",l,c);
	return 0;
}
