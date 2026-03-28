#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>

int main()
{
	int l, j, c, i;
	
	printf("Informe a quantidade de linhas de sua matriz: \n");
	scanf("%d",&l);
	printf("Informe a quantidde de colunas de sua matriz: \n");
	scanf("%d",&c);
	
	int val[l][c], aux=0, linha=0, coluna=0, maior=0;
	
	for(i=0; i<l; i++)
	{
		for(j=0; j<c; j++)
		{
			printf("Informe os valore que sera armazenado na matriz: \n");
			scanf("%d",&val[i][j]);
		}
	}
	
	for(i=0; i<l; i++)
	{
		for(j=0; j<c; j++)
		{
			if((i==0)&&(j==0))
			{
				maior = val[i][j];
			}
			
			if(val[i][j] > maior)
			{
				aux = val[i][j];
				val[i][j]= maior;
				maior = aux;
				
				linha = i;
				coluna = j;
			}
		}
	}
	
	for(i=0; i<l; i++)
	{
		for(j=0; j<c; j++)
		{
			if((i==linha)&&(j==coluna))
			{
				
			}
		}
	}
}
