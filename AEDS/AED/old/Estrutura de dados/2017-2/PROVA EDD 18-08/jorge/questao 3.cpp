#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define N 2

typedef struct{
	char nome[100];
	int idade;
	int cpf;
	int ano;
}autor;

typedef struct{
	char titulo[30];
	autor a;
}livro;


void leitura(livro l[N]){
	int i;
	
	for(i=0;i<N;i++){
		printf("livro %d \n",i+1);
		printf(" titulo do livro:");
		fflush(stdin);
		gets(l[i].titulo);
		printf("autor:");
		fflush(stdin);
		gets(l[i].a.nome);
		printf("idade:");
		scanf("%d",&l[i].a.idade);
		printf("cpf:");
		scanf("%d",&l[i].a.cpf);
		printf("ano:");
		scanf("%d",&l[i].a.ano);
		
	}
}

int busca(livro l[N],char t[30]){
	int i;
	for(i=0;i<N;i++){
		printf(" digite o titulo do livro: \n");
		fflush(stdin);
		gets(l[i].titulo);
			if(l[i].titulo==t){
			return 1;
			printf(" o nome do livro %s  \t o nome do autor %s \t idade %d cpf %d ano %d",l[i].titulo,l[i].a.nome,l[i].a.idade,l[i].a.cpf,l[i].a.ano);
			
		}
		//printf(" o nome do livro %s  \t o nome do autor %s \t idade %d cpf %d ano %d",l[i].titulo,l[i].a.nome,l[i].a.idade,l[i].a.cpf,l[i].a.ano);
			
		else{
			return 0;
		}
	}
}

int main(){
	livro l[N];
	char t[30];
	leitura(l);
	printf("%d",busca(l,t));
	getch();
	return 0;
}
