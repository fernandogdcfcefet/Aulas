#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
# define N 2
# define X 2

typedef struct{
	int matricula;
	char nome[20];
	float nota[X];
	
}aluno;


int main(){
	
	int i;
	aluno al[N];
	float media[N];
	for(i=0;i<N;i++){
	
		printf(" \n informe o nome do aluno");
		fflush(stdin);
		gets(al[i].nome);
		printf("\n informe a matricula do aluno");
		fflush(stdin);
		scanf("%d",&al[i].matricula);
		printf("\n infome a primeira nota do aluno");
		fflush(stdin);
		scanf("%d",&al[i].nota);
		//media[i]=(al.nota[i]);
	        //if(media[i]>=60){
		//printf("%d",al[i].nome);
					//	}
}
	
	

	        
						
	
	
	
	getch();
	return 0;
}
