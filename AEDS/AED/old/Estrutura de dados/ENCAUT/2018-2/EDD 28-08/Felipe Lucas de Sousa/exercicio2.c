#include <stdio.h>
#include <stdlib.h>

#define LINHA 3
#define COLUNA 3

void ler (int *mat[LINHA][COLUNA]){
	int i,j;
	for(i=0; i<LINHA; i++){
		for(j=0; j<COLUNA; j++){
			scanf("%d", &(mat[i][j]));
		}
	}	
}

int minimax(int *mat[LINHA][COLUNA], int *a, int *b){
	int max, linha, coluna, mini;
	int i,j;
	
	max = mat[0][0];
	linha = 0;
	for(i=0; i<LINHA; i++){
		for(j=0; j<COLUNA; j++){
			if(max < mat[i][j]){
				linha = i;
			}
		}
	}
	
	mini = mat[linha][0];
	coluna = 0;
	for(j=0; j<COLUNA; j++){
		if(mini > mat[linha][j]){
			mini = mat[linha][j];
			coluna = j;
		}
	}
	*a = (linha+1);
	*b = (coluna+1);
	
	return mini;	
}

void imprime (int *mat[LINHA][COLUNA]){
	int i,j;
	for(i=0; i<LINHA; i++){
		for(j=0; j<COLUNA; j++){
			printf("%d	",mat[i][j]);
		}
		printf("\n");
	}	
}


void main(){
	int matriz[LINHA][COLUNA];
	int l=0,c=0,m=0;
	
	ler(matriz);
	
	printf("\n----------------------------------------------\n");
	imprime(matriz);
	printf("\n----------------------------------------------\n");
	
	m = minimax(matriz,&l,&c);
	
	printf("O elemento minimax é: %d com linha %d e coluna %d", m, l, c);
	
}
