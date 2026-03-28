#include <stdio.h>
#include <stdlib.h>
#define N 3

int norma(int mat[N][N], int n){
    int i, j, maior;
    int matAux[N]={0};
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            matAux[i] += mat[i][j];
        }
    }
    for (j=0; j<n; j++){
        if (j==0){
            maior = matAux[j];
        }
        if (matAux[j]>maior){
            maior = matAux[j];
        }
    }
    return maior;
}
int main(){
    int mat[N][N]={{8,3,4},{2,1,3},{5,0,-1}};
    printf("Norma: %d", norma(mat, N));
    return 0;
}
