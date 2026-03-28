#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define N 3
#define X 3

typedef struct Aluno{
	char nome[50];
	int matricula, nota[X]; 
}Aluno;

void aprovados(Aluno a[N]){
	int media, soma; 
	printf("Alunos aprovados: \n");
	for (int i=0; i<N; i++){
		media=0; soma=0; 
		for (int j=0; j<X; j++){
			soma=soma+a[i].nota[j]; 
		} 
		media = soma/X;
		if (media >= 60){
			printf("%d- %s \n", i+1, a[i].nome); 
		}
	}
	printf ("\n \n");
}

Aluno maiormedia(Aluno a[N]){
	int aux=0, ind=0;
	char maiorm[50];
	for (int i=0; i<N; i++){
		int media=0, soma=0; 
		for (int j=0; j<X; j++){
			soma=soma+a[i].nota[j]; 
		} 
		media = soma/X;
		if (media>aux){
			aux = media; 
			ind = i;
		}
	}
	return a[ind]; 	
}

void ler_dados (Aluno a[N]){
	system ("cls");

	for (int i=0; i<N; i++){
		printf("\t\t\t\tCADASTRO DE ALUNOS\n\n");
		printf("\t\t\t\t-ALUNO %d-\n", i+1);
		printf("Nome:"); 
		fflush(stdin); 
		gets(a[i].nome);
		printf("\nMatricula: ");
		scanf("%d", &a[i].matricula);
		for (int j=0; j<X; j++){
			printf("\nInforme a nota %d: ", j+1);
			scanf("%d", &a[i].nota[j]); 
		}
		system ("cls");
	}
}

int main() {
	Aluno a[N]; 
	ler_dados(a); 
	aprovados(a);
	printf ("Aluno com maior media: %s\n", maiormedia(a).nome); 
}
