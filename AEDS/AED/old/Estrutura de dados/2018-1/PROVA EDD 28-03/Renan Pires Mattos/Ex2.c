#include <stdio.h>
#include <stdlib.h>
#define N 2
#define X 3

typedef struct{
	
	char matricula[10];
	char nome[10];
	char endereco;
	float nota[X];
    char rua[10];
	char cidade[10];
	
}aluno;



int main(){
	aluno a[N];
	int i,j,m;
	float media[N]={0},maior=0;
	for(i=0;i<N;i++){
		printf("Insira o nome do %d aluno:", i+1);
		fflush(stdin);
		gets(a[i].nome);
		fflush(stdin);
		printf("Insira o numero da matricula do %d aluno:", i+1);
		fflush(stdin);
		gets(a[i].matricula);
		fflush(stdin);
		for(j=0;j<X;j++){
			printf("Insira a %d nota do %d aluno:",j+1, i+1);
			scanf("%f",&a[i].nota[j]);
			if(a[i].nota[j]<0 || a[i].nota[j]>10){
				printf("Nota invalida\n");
				j=j-1;
			}
		}
		printf("Insira a rua do %d aluno:", i+1);
		fflush(stdin);
		gets(a[i].rua);
		fflush(stdin);
		printf("Insira a cidade do %d aluno:", i+1);
		fflush(stdin);
		gets(a[i].cidade);
		fflush(stdin);
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<X;j++){
		media[i]=media[i]+a[i].nota[j];
		}		
	}
	for(i=0;i<N;i++){
	    if(media[i]>maior){
	    	maior=media[i];
	    	m=i;
		}
	}
    system("O aluno com maior media foi o aluno");
    fflush(stdin);
	gets(a[m].nome);
	fflush(stdin);
    
    
    
}
	
	

