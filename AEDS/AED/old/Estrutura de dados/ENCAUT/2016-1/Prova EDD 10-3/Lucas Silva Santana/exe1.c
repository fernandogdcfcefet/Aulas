#include <stdio.h>
#include <string.h>
#define n 2

int norma(int mat[n][n]){
	
	int i,j,soma=0,total=0;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(mat[i][j]<0){
				mat[i][j]=mat[i][j] * (-1);
				soma = soma + mat[i][j];				
			}else{
				soma = soma + mat[i][j];
			}		
		}
		
		if(soma>total){
			total=soma;
		}		
		
		soma=0;
	}
	
	return total;
}

int main(){
	int i,j,maiorsoma;
	int mat[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("Digite um numero [%d][%d]: ",i,j);
			scanf("%d", &mat[i][j]);
		}
	}
	
	maiorsoma = norma(mat);	
	
	printf("Maior Soma das Linhas: %d", maiorsoma);	
	
	
}
