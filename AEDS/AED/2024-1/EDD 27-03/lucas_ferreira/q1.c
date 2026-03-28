#include "stdlib.h"
#include "stdio.h"

int norma(int n,int mat[n][n]){
    int soma,soma1,soma2,soma3;;
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("Indice[%d][%d]: ",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        soma = 0;
        for (int j=0;j<n;j++)
        {
            soma = soma + abs(mat[i][j]);
        }
        if (i==0)
        {
            soma1=soma;
        }
        if (i==1)
        {
            soma2=soma;
        }
        if (i==2)
        {
            soma3=soma;
        }
    }
    printf("Soma linha1: %d\n",soma1);
    printf("Soma linha2: %d\n",soma2);
    printf("Soma linha3: %d\n",soma3);
    return 0;
}

int main(){
    int n=3;
    int mat[n][n];
    norma(n,mat);
}