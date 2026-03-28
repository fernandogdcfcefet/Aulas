#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define N 3

int norma (int mat[N][N], int n){
	int soma[n], aux=0; 
	for (int i; i<n; i++){
		for (int j=0; j<n; j++){
			soma[i] = soma[i]+mat[i][j];
		}
	}
	
	for (int k=0; k<n;k++){
		if (soma[k]>aux){
			aux=soma[k];
		}
	}
	
	return aux; 
}

int main() {

}
