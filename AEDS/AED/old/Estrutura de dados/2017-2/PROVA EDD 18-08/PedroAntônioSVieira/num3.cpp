#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<strings.h>
#define N 1


//as 2 structs para livros
typedef struct {
	char nome[50];
	int idade, cpf;
}autor;

typedef struct{
	char titulo[30];
	autor autor;
	int ano;
}livro;


//preenche o vetor de livros
void preenche(livro vetor[N]){
	int i;
	
	for(i=0;i<N;i++){
		printf("\ninforme o titulo do livro:");
		fflush(stdin);
		gets(vetor[i].titulo);
		fflush(stdin);
		
		printf("\ninforme o nome do autor do livro:");	
		fflush(stdin);
		gets(vetor[i].autor.nome);
		fflush(stdin);
		
		printf("\ninforme o ano do livro:");
		scanf("%d", &vetor[i].ano);
		
		printf("\ninforme a idade do autor do livro:");		
		scanf("%d", &vetor[i].autor.idade);
		
		printf("\ninforme o cpf do autor do livro:");
		scanf("%d", &vetor[i].autor.cpf);	
				
	}
	
	
}

//procura o livro pelo titulo
char procura(char titulo[N], livro liv[] ){
	int i,j,ncost=0;
	
	for (j=0;j<N;j++){

		i=strcmp(titulo, liv[j].titulo);
		if(i==0){
			printf("titulo: %s \nano do livro: %d \nnome do autor: %s \ncpf do autor: %d \nidade do autor: %d",liv[j].titulo, liv[j].ano, liv[j].autor.nome, liv[j].autor.cpf, liv[j].autor.idade);
		}
		else{
			ncost++;	
		}	
	}
	
	if(ncost!=0){
		printf("O livro nao consta");
	}
}



//funcao principal
int main(){
	livro colec[N];
	char titulo[30];
	
	
	preenche(colec);
	
	printf("qual titulo estas buscando? ");
	fflush(stdin);
	gets(titulo);
	fflush(stdin);
			
	
	procura(titulo,colec);	
	
}
