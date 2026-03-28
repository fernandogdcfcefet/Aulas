#include<stdio.h>
#include<conio.h>
int norma(int mat[n][n], int n){
	int i,j;
	int n;
	int soma=0;
	for(i=1;i<n;i++){
	for(j=1;j<n;j++){
	printf("\n informe os valores da matriz");
	scanf("%d",&mat[i][j]);
	soma=soma+mat[i][j];
	return soma;
		}
	}
}
int main(){
	int i;
	int j;
	int n;
	int soma;
	soma=norma( mat[2][2],2);
	for(i=1;i<n;i++){
	for(j=1;j<n;j++){
	printf("%d", mat[i][j]);
		}
	}
	getch();
	return 0;
}
