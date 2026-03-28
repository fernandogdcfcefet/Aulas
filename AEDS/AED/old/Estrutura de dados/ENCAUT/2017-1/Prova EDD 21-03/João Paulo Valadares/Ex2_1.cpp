#include <stdio.h>

typedef struct alunos {
	char nome[50];
	int d, matricula;
	float notas;
};

void aprovados (float notas, char nome, int n, int x)
{
	int a;
	float somatorio, media;
	
	alunos d[n][x];
	somatorio = 0;
	
	for (a=0; a<n; a++)
	{
		somatorio = somatorio + notas[a];
	}
}

int main ()
{
 	int n, i, x, aux;
	
	printf ("Digite o numero de alunos");
	scanf ("%i",&n);
	printf ("Digite a quantidade de materias cada aluno cursa (numero de notas)");
	scanf ("%i",&x);
	
	alunos d[n][x];
	
	for (i=0; i<n; i++) 
	{
		printf ("Digite o numero de matricula");
		scanf ("%i",&d[i][0].matricula);
		printf ("Digite o nome do aluno");
		scanf ("%s",&d[i][0].nome);
		
		for (aux=0; aux<x; aux++) 
		{
			printf ("Digite a nota do aluno");
			scanf ("%f",&d[i][aux].notas);
		}
	}
}
