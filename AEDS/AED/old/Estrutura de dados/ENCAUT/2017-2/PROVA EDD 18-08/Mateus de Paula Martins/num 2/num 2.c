#include <stdio.h>
#include <stdlib.h>
#define n 2
#define x 2

typedef struct
{
	char nome[50];
	int matricula;
	float nota[x];
}Aluno;

void aprovados (Aluno a[n])
{
	int i,j; 
	float media[x];
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<x; j++)
		{
			media[j]=(a[i].nota[j]+a[i].nota[j+1])/x;
		}
	}
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<x; j++)
		{	
			if(media[j]>=60.00)
			{
				printf ("Aluno aprovado:\t");
				puts(a[i].nome);
			}
		}
	}
}

int maiormedia(Aluno a[n])
{
	int i,j; 
	float media[x];
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<x; j++)
		{
			media[j]=(a[i].nota[j]+a[i].nota[j+1])/x;
		}
	}
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<x; j++)
		{	
			if(media[0]>media[j])
			{
				printf ("Aluno com media maior:\t");
				puts(a[i].nome);
			}
		}
	}
	return 0;
}

int main(int argc, char *argv[]) 
{
	Aluno a[n];
	int i,j;
	float media[x];
	for(i=0; i<n; i++)
	{
		printf ("\nInforme o nome do aluno %d:\t", i+1);
		fflush(stdin);
		gets(a[i].nome);
		
		printf ("Informe a matricula aluno %d:\t", i+1);
		scanf("%d", &a[i].matricula);
		
		for(j=0; j<x; j++)
		{
			printf ("Informe a nota do aluno %d:\t", i+1);
			scanf("%f", &a[i].nota[j]);
		}
	}

	aprovados(a);
	maiormedia(a);
	
	return 0;
}
