#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define TAM 3
typedef struct
{
	char rua[100];
}end;
typedef struct
{
	char nome[100];
	int telefone;
	d[TAM].end;
}pessoa;
leiapessoa(pessoa d[TAM])
{
	int i;
	for(i=0;i<TAM;i++)
	{
		printf("Nome: \n");
		scanf("%s",&d[i].nome);
		printf("Rua: \n");
		scanf("%s",&d[i].end.rua);
		printf("Telefone: \n");
		scanf("%d",&d[i].telefone);
	}
}

int main()
{
	pessoa d[TAM];
	leiapessoa(d);
	
	return 0;
}
