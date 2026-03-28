#include<string.h>
#include<stdio.h>
#define tam 3

typedef struct
{
	char rua[50];
}endereco;

typedef struct
{
	char nome[50];
	endereco end;
	int telefone;
}pessoa;

int main()
{
	pessoa d[tam];
	int i,j;
	for(i=0;i<tam;i++)
	{
		printf("Nome:\n");
		scanf("%s", &d[i].nome);
		printf("Rua:\n");
		scanf("%s", &d[i].end.rua);
		printf("Telefone:\n");
		scanf("%d",&d[i].telefone);
	}
	
	for(i=0;i<tam;i++)
	{
		printf("Pessoas que moram na mesma rua de %s\n",d[i].nome);
		for(j=0;j<tam;j++)
		{
			if((strcmp(d[i].end.rua,d[j].end.rua)==0)&&(!(strcmp(d[i].nome,d[j].nome))==0))
			{
				/*Na primeira parte dessa linha 23 de codigo, compara o nome das ruas, se sao iguais ou nao. 
			    E para a verificacao ficar correta, verifica-se se nao eh o mesmo nome, para nao imprimir o nome da mesma pessoa*/ 
				printf("%s\n", d[j].nome);
				
			}
		}
	}
	return 0;
}

