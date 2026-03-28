#include <stdio.h>
#include <stdlib.h>
#define n 5
typedef struct
{
	char nome[50];
	int idade;
	char cpf[20];
}Autor;

typedef struct
{
	char titulo[30];
	Autor a;
	int ano;
}Livro;

void cadastro (Livro l[n])
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Nome do livro:\t");
		fflush(stdin);
		gets(l[i].titulo);
		printf("Ano livro:\t");
		scanf("%d", &l[i].ano);
		
		printf("Autor do livro:\t");
		fflush(stdin);
		gets(l[i].a.nome);
		printf("Idade do Autor do livro:\t");
		scanf("%d", &l[i].a.idade);
		printf("CPF do Autor do livro:\t");
		fflush(stdin);
		gets(l[i].a.cpf);
		printf("\n");
	}
}

char busca(Livro l[n], char buscar[30])
{
	int i,j, h=8;
	for(i=0;i<n;i++)
	{
		h=strcmp(buscar,l[i].titulo)
		
		if (h==0)
		{
			puts(l[i].titulo);
			printf("Ano livro: %d\t", l[i].ano);
			puts(l[i].a.nome);
			printf("Idade do Autor do livro:%d\t", l[i].a.idade);
			puts(l[i].a.cpf);
		}
		else
		{
			printf("nao foi encontrado");	
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	
	Livro l[n];
	char buscar[30];
	 
	cadastro(l);
	
	printf("Qual Livro deseja buscar?\t");
	fflush(stdin);
	gets(buscar);
	
	busca(l,buscar);
	
	
	return 0;
}
