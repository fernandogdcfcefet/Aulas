#include<stdio.h>
#include<stdlib.h>
#define tam 3
#define num 3
typedef strut
{
 int matricula[10];
 char nome[100];
 float notas[num];
 	
	
}aluno;
void LeiaAluno(char vetnome[tam],int vetmatricula[tam],float vetnotas[num])
{ 

 strut aluno;
 int i=0;
    for(i=0;i<=tam;i++)
     {
  	puts("aluno");
  	gets("%c",aluno.nome[i]);
  	fflush(stdin);
  	puts("matricula");
  	gets("%d",aluno.matricula[i]);
  	//fflus(stdin);
  
  		
    }	
 	for(i=0;i<=num;i++)
	 {
 	   	puts("notas");
    	gets("%f",aluno.notas[i]);	
    //	fflush(stdin);
	 }
	
}
float  MediaDasNotas(float vetmedia[num])
{
	float media;
	int j;
	

	
	  for(j=0,j<num,j++)
	{ 
	  	media=(vetnotas[num]);
	     	if(media>=60)
		   {
	   		 printf("aluno foi aprovado");
	   		 scanf("%f",&aluno.notas[j]);
	   		
		   }
		   else
		   {
		   	   printf("aluno foi reprovado");
		   	   scanf("%f",&aluno.notas[j]);
		   }

   
		
	}
  return media;	
}

int main()
{  	strurt aluno ;
   char vetnome[tam];
   int vetmatricula[tam];
   float vetnotas[num];
   float vetmedia[num];
   LeiaAluno(vetnome,vetmatricula,vetnotas);
   MediaDasNotas(vetmedia);
  	
	
return 0;	
}
