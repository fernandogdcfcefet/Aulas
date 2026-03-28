#include <stdio.h>
#include <stdlib.h>
#define l 2
#define c 2
void leMatriz(int mat[l][c]){
    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            scanf("%d", &mat[i][j]);
        }
    }
}
void imprimeMatriz(int mat[l][c]){
    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
int localizaMiniMax (int mat[l][c],int *linha,int *coluna){
    int minimax,i,j,k,m;
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){

            for(k=0;k<l;k++){
                for(m=0;m<c;m++){

                    if (mat[i][j]>mat[k][m]){

                        *linha=i;


                    }
                }
            }

        }
    }
    for (int n=0;n<c;n++){
            for (int o=0;o<c;o++)
        if (mat[*linha][n]<mat[*linha][o]){
             *coluna=j;
             minimax=mat[*linha][n];
        }
    }


    return minimax;
}
int main()
{
    int mat[l][c],lin=-1,col=-1,minimax;
    leMatriz(mat);
    imprimeMatriz(mat);
    minimax=localizaMiniMax(mat,&lin,&col);
    printf("%d \nlinha: %d \ncoluna: %d",minimax,lin,col);

    return 0;
}
