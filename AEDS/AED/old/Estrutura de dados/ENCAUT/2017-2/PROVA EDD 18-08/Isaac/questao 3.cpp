#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#define A 5



typedef struct {
	char nome[50];
	int idade;
	int cpf;
} autor;

typedef struct {
	char titulo[30][A];
	autor a[A];
	int ano[A];
} livro;

livro dados;

void busca (char titulo[30]) {

	for (int i=0; i<A; i++) {
		if(strcmp(titulo, dados.titulo[i]) == 0) {
			printf("\n\t%s", dados.titulo[i]);
			printf("\n\tAutor: %s, %d anos, Cpf: %d", dados.a[i].nome, dados.a[i].idade, dados.a[i].cpf);
			printf("\n\tAno: %d", dados.titulo[i]);
		}
	}
	system("pause");
}


int main() {

	char nomelivro[30];
	
	for (int i=0; i<A; i++) {
		printf("\n\tInsira o nome do livro %d", i+1);
		fflush(stdin);
		gets(dados.titulo[i]);
		fflush(stdin);
		printf("\n\tInsira o nome do autor");
		gets(dados.a[i].nome);
		fflush(stdin);
		printf("\n\tInsira a idade do autor");
		scanf("%d", &dados.a[i].idade);
		fflush(stdin);
		printf("\n\tInsira o cpf do autor");
		scanf("%d", &dados.a[i].cpf);
		fflush(stdin);
		printf("\n\tInsira o ano do livro");
		scanf("%d", &dados.ano[i]);	
		fflush(stdin);
	}
	system("cls");
	
	printf("\n\tDigite o nome do livro que quer pesquisar: ");
		fflush(stdin);
	gets(nomelivro);
		fflush(stdin);
	
	busca(nomelivro);
	
 return 0;	
}
