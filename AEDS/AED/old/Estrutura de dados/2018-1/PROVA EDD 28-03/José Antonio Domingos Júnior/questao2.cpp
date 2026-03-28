#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 3
#define X 3

typedef struct{
	char rua[100], cidade[100];
	
}Endereco;



typedef struct{
	
	char matricula[12];
	char nome[100];
	Endereco end;
	float notas[X];
	
}Aluno;

///////////////////////////////////////////////////////////////////
//(a)
void cadastraAluno(){
	
	Aluno al[N]; 
	
	for(int i=0; i<N; i++){
		
		printf("\n\n\n\t\t\t\tINFORMACOES DO ALUNO %d", i+1);
		printf("\n\nINFORME A MATRICULA: ");
		fflush(stdin);
		gets(al[i].matricula);
		printf("\n\nINFORME O NOME: ");
		fflush(stdin);
		gets(al[i].nome);
		printf("\n\nINFORME A CIDADE: ");
		fflush(stdin);
		gets(al[i].end.cidade);
		printf("\n\nINFORME A RUA: ");
		fflush(stdin);
		gets(al[i].end.rua);	
		
			for(int j=0; j<X; j++){
				
				printf("\n\nINFORME A NOTA %d: ", j+1);
				scanf("%d", &al[i].notas[j]);

			}
			
		getch();
		system("cls");	
	}
		
}
////////////////////////////////////////////////////////////////
//(b)
float maiorMedia(){
	
	Aluno al[N];
	float soma=0, media[N], maiorMedia;
	char nomeMaior[100];
	
		for(int i=0; i<N; i++){
			printf("\n\n\n\t\t\t\tNOME DO ALUNO %d", i+1);
			fflush(stdin);
			gets(al[i].nome);
			
			for(int j=0; j<X; j++){
				
				printf("\n\nINFORME A NOTA %d: ", j+1);
				scanf("%d", &al[i].notas[j]);
				soma+= al[i].notas[j];
			}
			
				media[i]= soma/X;
				
			if(i==0){
				
			}
		}
	
}


///////////////////////////////////////////////////////////////

int main(){
	
	//Aluno al[N];
	cadastraAluno();
	
return 0;	
}
