#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#define n 2



int norma(int mat[n][n])
{
	int i, j, soma[n]={0}, maior;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Digite os elementos da matriz[%d][%d]:\n",i,j);
			scanf("%d", &mat[i][j]);
		}
	}	
	
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(mat[i][j]>0)
			{
				soma[i]=soma[i]+mat[i][j];
			}
			else if(mat[i][j]<0)
			{
				soma[i]=soma[i]+mat[i][j]*(-1);
			}	
		}
	}
	soma[0]=maior;
	for(i=0;i<n;i++)
	{
		if(soma[i]>maior)
		{
			maior = soma[i];
		}
	}
	
	return maior;
}

int main()
{
	int mat[n][n];
	
	printf("A maior soma das linhas da matriz eh: %d", norma(mat));
	return 0;
}
