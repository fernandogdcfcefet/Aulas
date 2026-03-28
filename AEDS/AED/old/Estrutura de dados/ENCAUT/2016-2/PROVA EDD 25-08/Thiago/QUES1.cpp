#include<stdio.h>
#include<stdlib.h> 
#define TAM 2

int norma ( int mat[n][n], int n){
	int i,j; 
	int soma=0;
	
	for(i=0;i<n;i++) {
	    for(j=1;j<n;j++) {  
	     soma = soma + mat[i][j];
	  } 
   } 
        return soma;	
}


int main (){ 
    int i,j; 
	int matriz [TAM][TAM];
	
	for(i=0;i<TAM;i++) {
	    for(j=1;j<TAM;j++) {  
	      printf(" preencha a mtriz na linha %i - coluna %j : \n");
	      scanf("%i",&matriz[i][j]);
       } 
   }  
    
    printf(" A matriz sera: \n"); 
     for(i=0;i<TAM;i++) {
	    for(j=1;j<TAM;j++) {  
	     
	      printf("%i \n ",matriz[i][j]);
	    }
	   printf(" \n ") ;
   }
      
      norma(matriz);
   
    
	return 0;
}
