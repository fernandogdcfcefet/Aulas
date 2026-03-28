#include <stdio.h>
#include <stdlib.h>
#define LINHA 2
#define COLUNA 2

void  preencherMat(int mat[][COLUNA]){
    int i,j,valor=0;

        for(i=0;i<LINHA;i++){
            for(j=0;j<COLUNA;j++){
                    mat[i][j]=valor;
                    valor++;
            }
        }
        for(i=0;i<LINHA;i++){
            for(j=0;j<COLUNA;j++){
                    printf("%d ",mat[i][j]);
            }
        printf("\n");}
}
/*void elementoMinmax(int mat[][COLUNA]){
    int i,j,menorValor=10,posicao=0;

            for(i=0;i<LINHA;i++){
                for(j=0;j<COLUNA;j++){
                    menorValor=mat[i][j];
                       if(menorV<mat[i][j]){
                         menorValor=mat[i][j];
                            posicao=i;
                       }

                }
            }
            printf("MenorV: %d  posicao %d",menorValor,posicao);


}*/

int main()
{
    int mat[LINHA][COLUNA];
    preencherMat(mat);
    elementoMinmax(mat);

    return 0;
}
