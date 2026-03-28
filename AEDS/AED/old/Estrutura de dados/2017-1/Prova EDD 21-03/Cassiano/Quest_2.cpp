#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#define N 2
#define X 3
typedef struct{
	char nome[30];
	char matricula[13];
	float nota[X];
}Aluno;

void leitura(Aluno a[N]){
	int i, j;
	printf("--CADASTRO DE ALUNOS--\n");
	for(i=0; i<N; i++){
		printf("Aluno %d\n", i+1);
		printf("\tNome: ");
		scanf("%s", &a[i].nome);
		printf("\tMatricula: ");
		scanf("%s", &a[i].matricula);
		printf("\tNotas de %s com PESO 100\n", a[i].nome);
		for(j=0; j<X; j++){
			printf("\t\tP%d=", j+1);
			scanf("%f", &a[i].nota[j]);
		}
	}	
}
void diario(Aluno a[N]){
	system("cls");
	printf("ALUNOS APROVADOS:\n");
	int i, j;
	float soma[N]={0}, media[N]={0};
	for(i=0; i<N; i++){
		for(j=0; j<X; j++){
			soma[i]+=a[i].nota[j];
		}
		media[i]=soma[i]/X;
		if(media[i]>=60){
			printf("\t%s\n", a[i].nome);	
		}
	}
	
}

int main(){
	Aluno a[N];
	leitura(a);
	diario(a);

	system("pause");
	return 0;
}
