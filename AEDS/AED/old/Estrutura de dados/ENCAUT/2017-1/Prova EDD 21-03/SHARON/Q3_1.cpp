#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

#define n 3

typedef struct
{
	char rua[50];
}Endereco;

typedef struct
{
	char nome[50];
	int telefone;
	Endereco end;
}Pessoa;
	
	
int main()
{
	Pessoa p[n];
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("Nome: ");
		fflush(stdin);
		gets(p[i].nome);
		printf("Rua: ");
		fflush(stdin);
		gets(p[i].end.rua);
		printf("Telefone: ");
		scanf("%d",&p[i].telefone);
	}
	
	for(i=0;i<n;i++)
	{
		printf("\nPessoas que moram na mesma rua de %s: ", p[i].nome);
		
		for(j=0;j<n;j++)
		{
			if(((strcmp(p[i].end.rua,p[j].end.rua))==0)&&(!(strcmp(p[i].nome,p[j].nome))==0)) printf("%s\n", p[j].nome);
		}
	}
	getch();
	return 0;

}
