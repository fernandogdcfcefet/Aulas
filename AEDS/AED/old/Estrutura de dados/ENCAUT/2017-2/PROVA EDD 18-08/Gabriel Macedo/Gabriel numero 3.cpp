#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>

#define pi 3,14
#define N 5

typedef struct{
	char nome;
	int idade;
	int CPF;
}inforautor;

typedef struct{
	inforautor autor[N];
	
	char titulo;
	int ano;
}obra;
void livros(){
	int i;
	obra livro[N];
	inforautor autor[N];
	
	for(i=0; i<N; i++){
		printf("\nInforme o titulo do livro - ");
		fflush(stdin);
		scanf("%s", &livro[i].titulo);
		fflush(stdin);
		printf("\n Informe o nome do autor - ");
		fflush(stdin);
		scanf("%s", &livro[i].autor[i].nome);
		fflush(stdin);
		printf("\n Informe a idade do autor - ");
		scanf("%d", &livro[i].autor[i].idade);
		
		printf("\n Informe o CPF do autor - ");
		scanf("%d", &livro[i].autor[i].CPF);
		
		printf("\n Informe o ano do livro - ");
		scanf("%d", &livro[i].ano);
	}

}

int livro(){
	char nomedolivro;
	int busca, i;
	printf("\n Qual o titulo do livro desejado - ");
	scanf("%s", nomedolivro);
	for(i=0; i<N; i++){
		busca=strcmp (nomedolivro, livro[i].titulo)
		if(busca==0){
			printf("\nTitulo - %s", livro[i].titulo)
			printf("\nAutor - %s", livro[i].autor[i].nome);
			printf("\nIdade - %d", livro[i].autor[i].idade);
			printf("\nCPF - %d", livro[i].autor[i].CPF);
			printf("\nAno - %d", livro[i].ano);
		}
		else{
			printf("Livro nao encontrado")
		}

		return 0;
	}
	
	
}
int main(){
	
	livros();
	
	return 0;
}
	
	
	
	
	

