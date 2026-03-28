#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
# define N 3
typedef struct{
	
	char rua[50];
}endereco;

typedef struct{
	int telefone;
	char nome[50];
	endereco end;
}pessoa;

int main(){
	int i,j;
	pessoa p[N];
	
	for(i=0;i<N;i++){
		puts("\n nome:");      // A linha  23  utiliza o comando strcmp que serve para comparar  se o valor digitado e igual ao valor armazenado
		scanf("%s",&p[i].nome);
		fflush(stdin);
		puts("\n telefone:");
		scanf("%s",&p[i].telefone);
		fflush(stdin);
		puts("\n endereco:");
		scanf("%s",&p[i].end.rua);
		fflush(stdin);
	}
	
	for(i=0;i<N;i++){
		printf("\n as pessoas que moram na mesma rua sao:%s",p[i].nome);
		
		for(j=0;j<N;j++){
			if((strcmp(p[i].end.rua,p[j].end.rua)==0)&&((!strcmp(p[i].nome,p[j].nome)==0))){
				printf("\n %s",p[j].nome);
			}
		}
	}
	getch();
	return 0;
}
