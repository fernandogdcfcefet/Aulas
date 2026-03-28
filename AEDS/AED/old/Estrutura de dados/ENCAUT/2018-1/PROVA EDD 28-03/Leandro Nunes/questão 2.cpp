#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<locale>
#define N 2
#define x 2

typedef struct
{
	char rua[10], cidade[10];
	
}endereco;

typedef struct
{
	int matricula=0;
	char nome[10];
	endereco end;
	int notas[x];
	
	
}alunos;

void cadastro(alunos a[])
{
	for(int i=0; i<N; i++)
	{
		printf("Informe o nome do aluno:\n");
		gets(a[i].nome);
		printf("Informe a matrícula do aluno :\n");
		scanf("%d",&a[i].matricula);
		printf("Informe a rua:\n ");
		fflush(stdin);
		gets(a[i].end.rua);
		printf("Informe a cidade:\n ");
		fflush(stdin);
		gets(a[i].end.cidade);
		for(int j=0; j<x ;j++)
		{
			printf("Informe a nota:\n");
			scanf("%d",&a[i].notas[j]);
		}	
	}
}

float media( int a[])
{
	int soma=0;
	float m=0.0;
	
	for(int i=0; i<x; i++)
	{
		soma=soma+a[i];	
	}
	m=(soma/x);
	
	return m;
}

int maiormedia(alunos a[])
{
	float m=0, med=0, n=0;
	for(int i=0; i<N; i++)
	{
		med=media(a[i].notas);
		if(m<med)
		{
			m=med;
			n=i;
		}
	}
	
	return n;
}

void aprovado(alunos a)
{
	float b=media(a.notas);
	if(b>=6)
	{
		printf("Aprovado:\n");
	}
	else
	printf("Reprovado");
}



int main()
{
	setlocale(LC_ALL,"Portuguese");
	int b=0;
	alunos a[N];
	
	cadastro(a);
	
	b=maiormedia(a);
	
	printf("Aluno com maior média: %s\n",a[b].nome);
	
	aprovado(a[0]);
	
	return 0;
}
