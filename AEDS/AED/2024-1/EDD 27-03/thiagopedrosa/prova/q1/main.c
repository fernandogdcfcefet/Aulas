#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 2

int norma(int n, int mat[n][n]){
    int soma[n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            soma[i] = mat[i][j] + soma[i];
        }
    }

    return abs(soma);
}

int main()
{
    int mat[N][N];
    int soma[N];

    for(int i = 0; i < N; i++){
        printf("Linha %d:\n", i+1);
        for(int j = 0; j < N; j++){
            printf("Coluna %d: ", j+1);
            scanf("%d", &mat[i][j]);
        }
    }

    soma[N] = norma(N, mat);

    for(int h = 0; h < N; h++){
        printf("\nSoma da linha %d: %d\n", h+1, soma[h]);
    }
    return 0;
}
