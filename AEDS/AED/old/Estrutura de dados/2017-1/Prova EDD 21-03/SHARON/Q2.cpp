#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

#define n 3
#define x 2
typedef struct
{
	int mat;
	char nome[50];
	float nota[x];	
}Aluno;

void Aprovados(Aluno a[])
{
	float soma[n]={0};
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<x;j++)
		{
			soma[i]+=a[i].nota[j];	
		}
		if((soma[i]/x)>=6) printf("\nAluno %s: -Status: Aprovado",a[i].nome );
		else printf("\nAluno %s: -Status: Reprovado",a[i].nome);
	}
}

int AlunoMaiorMedia(Aluno a[])
{
	float soma[n]={0}, media[n]={0}, maior=0;
	int i,j,t;
	char nome[50];
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<x;j++)
		{
			soma[i]+=a[i].nota[j];	
		}
		media[i]=soma[i]/x;
		//printf("%f",media[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==0) maior=media[j];
			
			else if(media[j]>maior)
			{
				maior=media[j];
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		if(media[i]==maior) t=i;
	}
	return t;
}
int main()
{
	Aluno a[n];
	
	int i,j;
	
	for(i=0;i<n;i++)
	{
		printf("\nInforme o nome: ");
		fflush(stdin);
		gets(a[i].nome);
		printf("Informe a matricula: ");
		scanf("%d",&a[i].mat);
		
		for(j=0;j<x;j++)
		{
			printf("Informe a nota %d: ",j+1);
			scanf("%f",&a[i].nota[j]);
		}
	}
	Aprovados(a);
	
	int k=AlunoMaiorMedia(a);
	printf("\nNome do aluno com maior media: %s",a[k].nome);
	
	getch();
	return 0;
}
