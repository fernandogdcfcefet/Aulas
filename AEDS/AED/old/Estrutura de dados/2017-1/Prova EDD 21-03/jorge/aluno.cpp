# include<conio.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>

# define N 2

# define X 3

typedef struct{
	int matricula;
	char nome[50];
	float notas[X];
}aluno;

void Leitura(aluno a[N]){
	int i,j;
	
	for(i=0;i<N;i++){
		puts("\n nome:");
		scanf("%s",&a[i].nome);
		fflush(stdin);
		puts("\n matricula:");
		scanf("%d",&a[i].matricula);
		fflush(stdin);
		
		for(j=0;j<X;j++){
			printf("\n digite a nota: %d",j+1);
			scanf("%f",&a[i].notas[j]);
			fflush(stdin);
			
		}
	}
}

void media(aluno a[N]){
	int i,j;
	float soma;
	
	for(i=0;i<N;i++){
		soma=0.0;
		for(j=0;j<N;j++){
			soma=(soma+a[i].notas[j]);
		}
		if((soma/X)>=60.0){
		
			printf("\n aprovado:%s",a[i].nome);
	}
	else{
			printf("\n reprovado:%s",a[i].nome);
	
	}
		
	
	
	}
	
	
	
}


int main(){
	aluno a[N];
	Leitura(a);
	media(a);
	getch();
	return 0;
}
