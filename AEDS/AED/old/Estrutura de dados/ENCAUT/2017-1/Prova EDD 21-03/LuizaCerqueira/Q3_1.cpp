#include <stdio.h>
#include <string.h>
#define TAM 3

// Estruturas necessárias para que o programa funcione corretamente
// ***************************
typedef struct endereco{
	char rua[50];
}endereco;

typedef struct pessoa{
	char nome[50];
	int telefone;
	endereco end; 
}pessoa;

// ***************************

int main ()
{
	pessoa d[TAM];
	int i, j;
	for (i=0; i<TAM; i++)
	{
		printf("Nome\n");
		scanf("%s", d[i].nome);
		printf ("Rua\n");
		scanf ("%d", d[i].end.rua);
		printf("Telefone \n");
		scanf ("%d", &d[i].telefone);
	}
	for (i=0;i<TAM;i++)
	{
		printf("Pessoas que moram na mesma rua de %s\n", d[i].nome);
		for (j=0;j<TAM;j++)
		{
			if((strcmp(d[i].end.rua,d[j].end.rua)==0)&&(!(strcmp(d[i].nome,d[j].nome))==0))
			/* RESPOSTA DA QUESTÃO 3 
			A linha 23 compara os nomes das ruas de duas pessoas para saber se são da mesma e 
			garante que não esteja comparando com a própria pessoa. */ 
			{	
				printf("%s\n",d[j].nome);
			}
		}
	}
	return 0; 
	
}
