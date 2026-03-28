#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define N 1

typedef struct{
	
	char nome[N][100];
	int idade[N];
	int CPF[N];
	
	
}Criador;


typedef struct{
	
	char titulo[N][30];
	Criador autor;
	int ano[N];
	
}Livro;


void Leitura(Livro L){
	
	
	
	int i=0;
	
	for(i=0;i<N;i++){
		printf("Digite o titulo do livro: ");
		gets(L.titulo[i]);
		fflush(stdin);
		printf("Digite o nome do autor: ");
		gets(L.autor.nome[i]);
		fflush(stdin);
		printf("Digite o CPF do autor: ");
		scanf("%d",&L.autor.CPF[i]);
		fflush(stdin);
		printf("Digite a idade do autor: ");
		scanf("%d",&L.autor.idade[i]);
		fflush(stdin);
		printf("Digite o ano do livro: ");
		scanf("%d",&L.ano[i]);
		fflush(stdin);
	}
	
	for(i=0;i<N;i++){
		printf("Livro: ");
		puts(L.titulo[i]);
		
	}
	
	
	
}

int main(){
	
	
	
	Livro l;
	Leitura(&l);
	int i=0;
	
	
	
	
	
	
	
	
	return 0;
}
