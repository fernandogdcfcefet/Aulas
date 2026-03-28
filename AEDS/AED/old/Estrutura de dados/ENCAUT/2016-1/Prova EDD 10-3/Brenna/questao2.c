#include<stdio.h>
#include<conio.h>
#define TAM 2
#define CAM 2
typedef struct 
 {
  char nome[100];
  char  matricula[10];
  int nota[10]; 
  int mais[10];
  
  float media[20];
  }aluno;
 
 
 int main(){
	int i;
	
   aluno pessoa[TAM];
   for(i=0;i<TAM;i++)
	   {
		printf("NOME:");
    	gets(pessoa[i].nome);
    	fflush(stdin);
    	printf("matricula:");
    	gets(pessoa[i].matricula);
    	fflush(stdin);
    	printf("nota:");
    	scanf("%d",&pessoa[i].nota);
    	fflush(stdin);
    	printf("nota 2::");
    	scanf("%d",&pessoa[i].mais);
    	fflush(stdin);
    
    	 }
    for(i=0;i<TAM;i++)
    {
    printf("pessoas %s\n",pessoa[i].nome);
    printf("matricula %s\n",pessoa[i].matricula);
    printf("nota %d\n",pessoa[i].nota);
    printf("nota %d\n",pessoa[i].mais);
    
    
    
      
    }
















return 0;
}
