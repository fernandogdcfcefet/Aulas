#include<iostream>
#include<stdio.h>
#include<math.h>
#define N 2
#define M 2

void imprime(int mat[N][M]){
	for(int i=0; i<N; i++){
		printf("\n");
		for(int j=0; j<M; j++){
			printf("%d\t", mat[i][j]);
		}
	}
}

int minimax(int mat[N][M], int *a, int *b){
	int maior, x, menor;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(i==0 && j==0){
				maior=mat[i][j];
				x=i;
			}
			if(mat[i][j]>maior){
				maior=mat[i][j];
				x=i;
			}
		}
	}
	
	for(int i=x; i<x+1; i++){
		for(int j=0; j<M; j++){
			if(j==0){
				menor=mat[i][j];
				*a=i;
				*b=j;
			}
			if(mat[i][j]<menor){
				menor=mat[i][j];
				*a=i;
				*b=j;
			}
		}
	}
	return menor;
}

int main(){
	int matriz[N][M], x=0, y=0;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			printf("\nDigite um elemento da matriz: ");
			scanf("%d", &matriz[i][j]);
		}
	}
	
	imprime(matriz);
	printf("\nO elemento minimax que esta na linha %d e coluna %d vale %d", x, y, minimax(matriz, &x, &y));
}
