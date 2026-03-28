#include <stdio.h>
#include <stdlib.h>
#define linha 2
#define coluna 2

void lerMat (){
    int mat[linha][coluna], i, j;
    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            scanf("%d", &mat[i][j]);

        }

    }
    printf("\nMatriz: \n");
    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            printf("%d\n", mat[i][j]);

        }
    }

}

void acheMin (int *min, int *posx, int *posy){
    int mat[linha][coluna];
    int i, j, k, n, maiorElementoMat=0, menorElementoLinha ;
    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            if((i==0)&&(j==0)){
                maiorElementoMat=mat[i][j];
                menorElementoLinha=mat[i][j];
                *min=menorElementoLinha;
                *posx=i;
                *posy=j;
            }
            if(mat[i][j]>maiorElementoMat){
                maiorElementoMat=mat[i][j];
                *posx=i;
                *posy=j;
                n=j;

            }

        }
    }
    for(k=0; k<linha; k++){
        if(k==0){
            menorElementoLinha=mat[k][n];
            *posy=n;
            if(mat[k][n]<menorElementoLinha){
                menorElementoLinha=mat[k][n];
                *min=menorElementoLinha;
                *posy=n;
                *posx=k;
            }
        }
    }

}
int main()
{
    int *minimax, *posicaox=0, *posicaoy=0;
    lerMat();
    acheMin(&minimax, &posicaox, &posicaoy);
    printf("Minimax: %d\nLinha: %d\nColuna: %d", minimax, posicaox, posicaoy);
    return 0;
}
