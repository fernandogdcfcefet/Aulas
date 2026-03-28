#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
# define N 3

int norma(int mat[N][N]){
	
	int i,j,aux;
	int soma[N]={0};
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(mat[i][j]>=0){
				soma[i]=soma[i]+mat[i][j];
			}
			else if(mat[i][j]<0){
				soma[i]=soma[i]+mat[i][j]*(-1);
			}
		}
	}
	aux=soma[0];
	
	for(i=0;i<N;i++){
		if(soma[i]>aux){
			aux=soma[i];
		}
		
	}
	
	return aux;
	
}

int main(){
	int i,j,mat[N][N];
	int b;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("\n digite a matriz [%d][%d]",i,j);
			scanf("%d",&mat[i][j]);
		}
	}
	
	b=norma(mat);
	printf("\n a norma da matriz e :%d",b);
	getch();
	return 0;
}
