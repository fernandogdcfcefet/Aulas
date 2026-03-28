#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define N 3
#define x 2
typedef struct
{
	int matricula;
	char nome[100];
	//float nota1[x];
	//float nota2[x];
	char notas[x];
//	float numnotas[x];
	
}aluno;
void leiaaluno(aluno a[N])
{ 
    int i;
     //float media=0;
    for(i=0;i<N;i++)
    {
	
     	printf("informe a matricula do aluno: \n");
     	//fflush(stdin);
	    scanf("%d",&a[i].matricula);
	    printf("informe o nome do aluno: \n");
	     fflush(stdin);
	     gets(a[i].nome);
	     printf("informe as notas: \n");
	     fflush(stdin);
	     gets(a[i].notas);
	     //printf("informe a nota2: \n");
	     //scanf("%f",&a[i].nota2);
	     

	       
			
		//printf("informe as notas: \n");
	     //fflush(stdin);
	   // scanf("%f",&a[i].notas);
	   // media=media +a[i].notas;
	   
	  system("cls");   
  }
}
void imprime(aluno a[N])
{
	 int i;
	for(i=0;i<N;i++)
	{   
	 //if(media>=60)
	  // {
	   
		printf("\t APROVADOS %d\n",i+1);
		printf("matricula: %d\n",a[i].matricula);
		printf("nome: %s\n",a[i].nome);
		printf("notas: %s\n",a[i].notas);
	 // }
		
	}
}
int main()
{ 
  aluno a[N];
  leiaaluno(a);
  imprime(a);
	return 0;
}
