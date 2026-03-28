#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#define N 3
#define X 3

typedef struct{
	int matricula;
	char nome[100];
	float nota[X];
}aluno;


void leitura(aluno a[N]){
	int i,j;
	
	for(i=0;i<N;i++){
		printf("aluno %d \n \n",i+1);
		printf("nome:");
		fflush(stdin);
		gets(a[i].nome);
		printf("matricula:");
		scanf("%d",&a[i].matricula);
		
			for(j=0;j<X;j++){
					printf("nota %d",j+1);
						scanf("%f",&a[i].nota[j]);
		}
	}
}

void media(aluno a[N]){
	int i,j;
	float media[N];
	float soma[N]={0};
	
	for(i=0;i<N;i++){
		for(j=0;j<X;j++){
				soma[i]=soma[i]+a[i].nota[j];
			}
					media[i]=soma[i]/X;
			if(media[i]>=60){
				printf("o aluno %s foi aprovado com media %.2f \n \n",a[i].nome,media[i]);
			}
		}
}


int main(){
	aluno a[N];
	leitura(a);
	media(a);
	getch();
	return 0;
}
