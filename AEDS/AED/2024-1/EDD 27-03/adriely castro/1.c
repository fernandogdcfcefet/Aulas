#include <stdio.h>

int norma(int n, int mat[n][n]){
    int soma;
    int aux = soma;
    for(int i = 0; i < n; i++){
        soma = 0;
        for(int j = 0; j < n; j++){
            soma = soma + mat[i][j];
        }
        if(soma > aux){
            aux = soma;
        }
    }
    return aux;
}

int main(){
    int n;
    scanf("%d",&n);
    int matriz[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&matriz[i][j]);
        }
    }
    int resultado = norma(n, matriz);
    printf("maior soma eh: %d\n",resultado);



    return 0;
}