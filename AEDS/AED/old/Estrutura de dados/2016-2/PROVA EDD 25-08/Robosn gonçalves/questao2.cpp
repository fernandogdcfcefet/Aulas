#include <stdio.h>
#include <stdlib.h>
#define N 2
#define X 2

typedef struct{
	int matricula;
	char nome[20];
	float notas[X];
	
}aluno;

void leraluno(aluno al[N]){
	int i;
	int j;
	for(i=0;i<N;i++){
		printf("nome: ");
		fflush(stdin);
		gets(al[i].nome);
		printf("matricula: ");
		fflush(stdin);
		scanf("%d",&al[i].matricula);
		printf("notas: ");
		fflush(stdin);
		for(j=0;j<X;j++){
			scanf("%f",&al[i].notas[j]);
		}
	}	
}
void aprovados(aluno al[N]){
	int i;
	int j;
	float soma[N]={0.0};
	printf("aprovados:");
	for(i=0;i<N;i++){
		for(j=0;j<X;j++){
			soma[i]=soma[i]+al[i].notas[j];
			if(soma[i]/X>60) puts(al[i].nome);
		}
	}
}
int main(){
	aluno al[N];
	leraluno(al);
	aprovados(al);
}
