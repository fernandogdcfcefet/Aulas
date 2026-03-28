#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define  TAM 3
#define  NOT 1

typedef struct{
	char nome[20];
	int mat;
	float nota;
} aluno;


int main(){
	
	aluno aluno1[3];
	float media;
	float soma;
	int i,j;
	for(i=0;i<3;i++){
		puts("\n informe o nome do aluno");
		scanf("%s",aluno1[i].nome);
		fflush(stdin);
		printf("\n informe o numero de matricula");
		scanf("%d",&aluno1[i].mat);
		printf(" \n informe a nota do aluno");
		scanf("%f",&aluno1[i].nota);
		soma=soma+aluno1[i].nota;
		media=soma;
		if(media>=60){
			printf(" \n aprovado");
		}
		else{
			printf(" \n reprovado");
		}
	}
	puts(aluno1[0].nome);
	printf("%d",aluno1[0].mat);
	printf("%f",media);
	puts(aluno1[1].nome);
	printf("%d",aluno1[1].mat);
	printf("%f",media);
	puts(aluno1[2].nome);
	printf("%d",aluno1[2].mat);
	printf("%f",media);
	
	getch();
	return 0;
}
