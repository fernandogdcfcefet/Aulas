#include <stdio.h>
#include <stdlib.h>
#define LINHA 3
#define COLUNA 3

void LeMat(int mat1[LINHA][COLUNA]){
    int i,j;
    for(i=0;i<LINHA;i++){
        for(j=0;j<COLUNA;j++){
            printf("Digite o elemento [%d][%d] da matriz: ", i,j);
            scanf("%d", &mat1[i][j]);
        }
    }
}

void Minimax(int *a, int *b, int mat2[LINHA][COLUNA]){
    int i,j, max=mat2[0][0],min,c=0;
    for(i=0;i<LINHA;i++){
        for(j=0;j<COLUNA;j++){
            if(mat2[i][j]>max){
                max=mat2[i][j];
                c = i;
            }
        }
    }
    *a=c;
    for(i=0;i<LINHA;i++){
        if(i==c){
            for(j=0;j<COLUNA;j++){
                if(j==0){
                    min = mat2[i][j];
                }

                if(mat2[i][j]<min){
                    min = mat2[i][j];
                    *b = j;
                }
            }
        }
    }
}

void imprimeMat(int mat3[LINHA][COLUNA],int e,int f){
    int i,j;
    for(i=0;i<LINHA;i++){
        for(j=0;j<COLUNA;j++){
            printf("%d ", mat3[i][j]);
        }
        printf("\n");
    }

    printf("Elemento minimax: %d\n", mat3[e][f]);
    printf("Posicao [%d][%d]",e,f);
}

int main()
{
    int mat[LINHA][COLUNA], i, j;
    LeMat(mat);
    Minimax(&i,&j,mat);
    imprimeMat(mat,i,j);
    return 0;
}
