#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

#define x 3
#define n 2


typedef struct{
	int matricula;
	char nome[50];
	float notas[x];
}alunos;

void aprovados (alunos a[n])
{
	int j,i;
	float soma[n]={0},media[n]={0};
	
	for(i=0;i<n;i++)
	{
		printf("Nome:\n");
		fflush(stdin);
		gets(a[i].nome);
		printf("Matricula:\n");
		scanf("%d", &a[i].matricula);
		
		for(j=0;j<x;j++)
		{
			printf("Notas:\n");
			scanf("%f", &a[i].notas[j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<x;j++)
		{
			soma[i]=soma[i]+a[i].notas[j];
			
		}
		media[i]=soma[i]/x;
		if(media[i]>=60)
		{
			printf("Alunos aprovados:\n %s", a[i].nome);
		}
	}
	
}

int main()
{
	alunos a[n];
	aprovados(a);
	
	return 0;
}
