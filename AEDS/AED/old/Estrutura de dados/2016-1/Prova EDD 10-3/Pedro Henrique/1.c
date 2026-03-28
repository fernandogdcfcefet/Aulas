#include<stdio.h>
#include<stdlib.h>
#define TAM 2

int norma(int mat[TAM][TAM], int n){
         int soma[TAM] = {0,0};
         int i, j, msoma=0;

         for(i=0;i<TAM;i++){
            for(j=0;j<TAM;j++){
                printf("\ninforme o termo da matriz na posicao %d %d: ", i, j);
                scanf("%d", &mat[i][j]);
                soma[i] = soma[i] + mat[i][j];

            }

            if(soma[i]>msoma){
                msoma=soma[i];
            }

         }
         return msoma;
}

int main()
{   int mat[TAM][TAM];
    printf("a norma da matriz e: %d", norma(mat[TAM][TAM], TAM));

    return 0;
}
