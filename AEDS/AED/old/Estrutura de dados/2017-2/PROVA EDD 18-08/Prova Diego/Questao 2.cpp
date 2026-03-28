#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define N 3
#define X 3

char Maior_media(char nome[][100],float media[]){
	
	int i=0;
	char nomem[100];
	float maior;
	
	for(i=0;i<N;i++){
		if(i==0){
			maior = media[i];
		}
		if(media[i]>maior){
			maior = media[i];
			strcpy(nomem,nome[i]); 
		}
	}
	
	
	return nomem[100];
}

void Aprovados(char nome[][100],float media[]){
	
	int i=0,j=0;
	
	
	for(i=0;i<N;i++){
	
		if(media[i] >= 60){	
			printf("%s Aprovado\n",nome[i]);
		}
		
	}
	
	
	
}



int main(){
	
	int i=0,j=0;
	
	char nome[N][100],nomem[100];
	int matricula[N];
	float nota[N][X], soma, media[N];
	
	for(i=0;i<N;i++){
	
		printf("Digite o nome do aluno: ");
		gets(nome[i]);
		fflush(stdin);
		printf("Digite a matricula: ");
		scanf("%d",&matricula[i]);
		fflush(stdin);
		for(j=0;j<X;j++){
			
			printf("Nota %d: ",j+1);
			scanf("%f",&nota[i][j]);
			fflush(stdin);
			
		}
	
	}
	
	
	for(i=0;i<N;i++){
		soma = 0;
		for(j=0;j<X;j++){
			soma = soma + nota[i][j];
		}
		
		media[i] = soma/N;
	}
	
		Aprovados(nome,media);
		nomem[100] = Maior_media(nome,media);
		
		printf("Aluno com a maior media foi %s ",nomem);
	
	
	
	
	
	return 0;
}
