#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>

int norma(int mat[n][n], int n){
	int soma[];
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			soma[i]=mat[i][j]+mat[i][j++];
			
		}
	}
}

int main(){
	
	int n;
	int i, j;
	printf("%d", norma(mat[2][2],2));
	getch();
	return 0;
}
