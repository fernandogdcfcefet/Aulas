#include<stdio.h>
#include<string.h>
# define TAM 3

typedef struct { 
 
 char nome[120];
 char end[120]; // ESTRUTURA QUE FALTAVA 
 int telefone ;
   r d2;
 
}pessoa; 

typedef struct { 
                  // ESTRUTURA QUE FALTAVA 
 char rua[120];
 
}r;


int main (){
	
	pessoa d[TAM];
    r d2;   
	
	int i,j;
	
	for (i=0;i<TAM;i++){
		
		printf("Nome: \n");
		scanf("%s",d[i].nome);
		printf("Rua \n");
		scanf("%s",d[i].end.rua); /// end.rua;
		printf("Telefone: \n");
		scanf("%s",d[i].telefone);
	}
	
	for(i=0;i<TAM;i++)
	{
	printf(" Pessoas que moram na mesma rua de %s \n",d[i].nome);
     	for(j=0;j<TAM;j++) {
		    if((strcmp(d[i].end.rua,d[j].end.rua) ==0) && (!(strcmp(d[i].nome,d[j].nome))==0)) { // NESSA LINHA ESSE IF IRA COMPARAR ATRAS DA FUNÇÃO STRCMP SE AS STRINGS SALVAS SAO IGUAIS
		                                                                                        // E COMO TEMOS DOIS FOR, QUANDO OS VALORES DE  I E J FOREM IGUAIS IRA IMPRIMIR O  END.RUA E O NOME DA MESMA PESSOA
			                                                                                // QUANDO I E J FOREM DIFERENTES IRA PROCURAR POSSIVEIS NOMES E RUAS IGUAIS, SE ENCONTRAR RETORNARA  O NOME DA PESSOA;
			printf("%s \n", d[j].nome;)
		   }
        	}
    }
return 0;	
}
