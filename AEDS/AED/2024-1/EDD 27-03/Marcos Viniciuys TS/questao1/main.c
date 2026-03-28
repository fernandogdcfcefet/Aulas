#include <stdio.h>
#include <stdlib.h>
//#define n 2


int norma(int n, int mat[n][n]){
   pritnf("Informe a matriz desejada: \n");
   for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
    scanf("%d", mat[i][j]);
    i = n;
    j = n;
    }
}

void int somar(int mat[n][n], int n, soma=0){
    for (int j=0;j<2;j++){
        for(int i=0;i<2;i++){
            soma += mat[i];
        }
    }

}
void int maior(int mat[n][n], int n,){
    mat[0][0];
    for(int i=0;i<2;i++){
        for(int j=0;j<2);j++){
        if(mat[n][n] == mat[0][0])
        }
    }
}

int main()
{

    int normaf;
    int somat;
    int maiorlinha;

    normaf = norma(n, mat[2][2]);
    somat = soma(mat[n][n], n, soma);
    maiorlinha2 = maior(mat[n][n], n);

    printf("Matriz: %d", mat[n][n]);
    printf("Soma da matriz %d", soma);
    printf("Maior soma das linhas:  %d", maiorlinha);

return 0;
}
