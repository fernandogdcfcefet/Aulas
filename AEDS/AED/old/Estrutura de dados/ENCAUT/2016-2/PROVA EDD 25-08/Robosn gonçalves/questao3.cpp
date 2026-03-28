#include <stdio.h>
#include <string.h>
#define TAM 2

typedef struct{
	char rua[20];
	char bairro[20];	
}endereco;

typedef struct{
	char nome[20];
	endereco end;
	int telefone;	
}pessoa;

int main()
{
	pessoa d[TAM];
	int i,j;
	for(i=0;i<TAM;i++){
		printf("Nome\n");
		fflush(stdin);
		gets(d[i].nome);
		printf("Rua\n");
		fflush(stdin);
		gets(d[i].end.rua);
		printf("Telefone\n");
		fflush(stdin);
		scanf("%d",&d[i].telefone);	
	}
	for(i=0;i<TAM;i++){
		printf("Pessoas que moram na mesma rua de %s\n",d[i].nome);
		for(j=0;i<TAM;j++){
			if((strcmp(d[i].end.rua,d[j].end.rua)==0) && (!(strcmp(d[i].nome,d[j].nome))==0)) //verifica se a rua de duas pessoas sao iguais e se os nomes sao diferentes, utilizando a funcao strcmp para comparar strings
			{
				puts(d[j].nome);
			}
		}
	}
	return 0;
	
}
