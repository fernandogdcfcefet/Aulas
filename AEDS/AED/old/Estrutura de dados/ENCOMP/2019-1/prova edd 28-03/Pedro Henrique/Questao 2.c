#include <stdio.h>
#include <stdlib.h>
#define LINHA  2
#define COLUNA  2


void minimax(int mat[LINHA][COLUNA],int *linha, int *coluna,int *mimax){

    int i,j,maior = mat[0][0];

     for (i = 0; i < LINHA; i++){
         for (j = 0; j < LINHA; j++){
            if(mat[i][j] > maior){
                maior = mat[i][j];
                *linha = i;
                *coluna = j;
            }
         }
     }

      for (j = 0; j < COLUNA; j++){
        if(*mimax > mat[*linha][j]){
            *mimax = mat[*linha][j];
        }
      }

}

void imprimeMatriz(int mat[LINHA][COLUNA]){

    int i,j;

     for (i = 0; i < LINHA; i++){
         for (j = 0; j < LINHA; j++){

           printf("%d ",mat[i][j]);

        }
        printf("\n");
    }


}

void lerMatriz(int mat[LINHA][COLUNA]){

    int i,j;

     for (i = 0; i < LINHA; i++){
         for (j = 0; j < LINHA; j++){

           scanf("%d",&mat[i][j]);

        }
        printf("\n");
    }


}

int main()
{
    int i,j,linha,coluna,mimax = 0;
    int mat[LINHA][COLUNA];


    lerMatriz(mat);
    minimax(mat,&linha,&coluna,&mimax);
    imprimeMatriz(mat);
    printf("ELEMNTO MINIMAX: %d\n",mimax);
    printf("POSICAO: LINHA -> %d  COLUNA -> %d \n",linha,coluna);

    return 0;
}
