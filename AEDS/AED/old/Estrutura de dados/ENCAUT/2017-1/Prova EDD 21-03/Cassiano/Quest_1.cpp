#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#define N 3

void norma(int mat[N][N]){
	int i, j;
	int soma[N]={0}, valNorma=0;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("M[%d][%d]=", i+1, j+1);
			scanf("%d", &mat[i][j]);
		}
	}
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(mat[i][j]<0){
				mat[i][j]=(mat[i][j]*(-1));/*Tira numeros negativos como esta em modulo*/
			}
			soma[i]+=mat[i][j];
		}
		printf("\tSoma[%d]=%d\n", i+1, soma[i]);
	}
	
	for(i=0; i<N; i++){
		if(soma[i]>valNorma){
			valNorma=soma[i];
		}
	}
	printf("NORMA = %d\n", valNorma);
	
}

int main(){
	int mat[N][N], valNorma;
	
	norma(mat);

	system("pause");
	return 0;
}
