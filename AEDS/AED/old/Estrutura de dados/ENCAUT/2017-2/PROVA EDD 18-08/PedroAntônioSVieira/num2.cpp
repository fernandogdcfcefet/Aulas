#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define N 2
#define X 2


typedef struct{
	int matricula;
	char nome[30];
	float nota[X];
}info;




void apro(info al[], float media[]){
	int i,j;
	
	for(i=0;i<N;i++){
		if(media[i]>=60){
			
			printf("O aluno %s foi aprovado!\n",al[i].nome);
		
			
		}
	}
	
}


void maior(float media[], info alunos[]){
	int i,im;
	float maiorm;
	
	
	for(i=0;i<N;){
		if(i==0){
			maiorm=media[i];
			im=i;
			
		}
		if(media[i]>maiorm){
			maiorm=media[i];
			im=i;
		}
		
	}
	
	printf("O aluno %s teve a maior media", alunos[im].nome);
	
	

}


//Função principal


int main(){
	info alunos[N];
	int i,j,k;
	float medias[N]={0};
	
	for(i=0;i<N;i++){
		printf("Informe o nome do aluno: ");
		fflush(stdin);
		gets(alunos[i].nome);
		fflush(stdin);
		
		
		printf("Informe o numero de matricula do aluno: ");
		scanf("%d", &alunos[i].matricula);
		
		for(j=0;j<X;j++){
			printf("Informe a %d nota do aluno %s: ", j+1, alunos[i].nome);
			scanf("%f", &alunos[i].nota[j]);
			
			medias[i]=(medias[i]+alunos[i].nota[j])/(j+1);
			
		}
	}
	
	apro(alunos,medias);
	maior(medias,alunos);
	printf("\no aluno %s teve a maior media!", alunos[k].nome);
	
	
	
	
}
