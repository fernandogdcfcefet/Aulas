#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<locale>
#define N 3
#define x 3


int menor(int a[][x])
{
	int b[N];
	int i=0;
		for(int j=(x-1); j>=0; j--)
		{ 
			b[i]=a[i][j];
			i++;
		}
	
	int aux=b[0];
	for(int i=0; i<N; i++)
	{
			if(aux>b[i])
			aux=b[i];
	}
	return aux;
}

int main()
{
	int A[N][x], a=0;
	
	printf("Informe os valores para a matriz:\n");
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<x; j++)
		{
			scanf("%d",&A
			[i][j]);
		}
	}
	
	a=menor(A);
	
	printf("Menor valor: %d ",a);
	
	return 0;
}
