#include <stdio.h>
#include <stdlib.h>
#define n 2
#define x 4

typedef struct{
	int mat;
	char nome[100];
	float nota[x];
	float media;
}alunos;
int main(){
	
	
	int i;
	alunos a1[n];
	
	for(i=0;i<n;i++){
		fflush(stdin);
		printf("Digite seu nome: ");
		gets(a1[i].nome);
		fflush(stdin);
		
		printf("Digite sua matricula: ");
		scanf("%f",&a1[i].mat);
		
		printf("Digite a nota 1: ");
		scanf("%f",&a1[i].nota[0]);
		
		printf("Digite a nota 2: ");
		scanf("%f",&a1[i].nota[1]);
		
		printf("Digite a nota 3: ");
		scanf("%f",&a1[i].nota[2]);
		
		printf("Digite a nota 4: ");
		scanf("%f",&a1[i].nota[3]);
		
		a1[i].media = a1[i].nota[3]+a1[i].nota[2]+a1[i].nota[1]+a1[i].nota[0];
		a1[i].media = a1[i].media/x;
		
		system("cls");
		
	}
	
	for(i=0;i<n;i++){
		if(a1[i].media>=60){
			printf("MEDIA DE %s: %.2f\n",a1[i].nome,a1[i].media);
			printf("Aluno %s aprovado!",a1[i].nome);
			printf("\n---------------------------------------------\n");
		}		
	}
	
	return 0;
}
