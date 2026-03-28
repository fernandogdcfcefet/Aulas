#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define TAM 2

typedef struct {
   
   int matricula;
   float notas[TAM];
   char nome[120];	
	
	
} aluno ;

  void cadastro( aluno a1[TAM] ){
  	 int i; 
  	
  	    for(i=0;i<TAM;i++){
	   
  	      printf(" Informe a matricula na posicao %i : \n",i);  
  	      scanf("%i",&a1[i].matricula); 
  	      fflush(stdin);
	      printf(" Informe a nota na posicao %i: \n",i);
	      scanf("%f",a1[i].notas);	  
	      fflush(stdin);
	      printf(" Informe o nome na posicao %i: \n",i);
	      gets(a1[i].nome);
  	      fflush(stdin);
        }       
  }   
    
  
  int aprovado ( aluno a1[TAM] ) {
    int i; 
    int a=60;
  	  for(i=0;i<TAM;i++){
           if ( a1[i].notas[i] >= 60 ) {
         	    printf(" O aluno abaixo foi aprovado: \n"); 
            	puts(a1[i].nome);
	      } 
      }
  } 


int main (){
	int i;
	aluno a1[TAM];

	
	cadastro(a1); 
	aprovado(a1);
	
	
	return 0;
}
