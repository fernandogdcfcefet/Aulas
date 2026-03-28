#include <stdio.h>
#include <stdlib.h>
int norma(int n,int mat[n][n]){
    int i,j,soma=0,aux;
    for (i=1;i<=n;i++){
        aux = soma;
        for (j=1;j<=n;j++){
            if(mat[i][j] < 0)
                mat[i][j] = mat[i][j]*(-1);
            soma = soma + mat[i][j];
        }
        if(aux > norma(n,mat[i+1][j]))
            break;
    }
    return soma;
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
