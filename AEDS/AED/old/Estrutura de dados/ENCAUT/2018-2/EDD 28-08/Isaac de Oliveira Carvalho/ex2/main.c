#include <stdio.h>
#include <stdlib.h>

#define LINHA 2
#define COLUNA 2

void lerMatriz(int mat[LINHA][COLUNA]) {
int i, j;
for(j=0; j<COLUNA; j++){
    for(i=0; i<LINHA; i++){
        scanf("%d", &mat[i][j]);
    }
}

}

void imprimeMatriz(int mat[LINHA][COLUNA]) {
    int i, j;
for(j=0; j<COLUNA; j++){
    for(i=0; i<LINHA; i++){
        printf("%d ", mat[i][j]);
    }
    printf("\n");
}
}

void achaMinmax(int mat[LINHA][COLUNA]) {
    int maior=mat[0][0], indice_maior;
    int i, j;
    //busca linha onde esta o maior
    for(j=0; j<COLUNA; j++){
        for(i=0; i<LINHA; i++){
            if(mat[i][j] > maior) { maior = mat[i][j]; indice_maior=i;}
        }
    }
    //busca o menor dessa linha
    int menor=mat[indice_maior][0], indice_menor=0;
    int k;

    for(k=0; k<COLUNA; k++) {
        if(mat[indice_maior][k] < menor) {
        menor=mat[indice_maior][k];
        indice_menor=k;

        }
    }
    printf("o elemento minmax e o %d, e esta na posicao[%d, %d]", menor, indice_maior, indice_menor);
}
int main()
{
    int mat[LINHA][COLUNA];

    lerMatriz(mat);
    imprimeMatriz(mat);
    achaMinmax(mat);

    return 0;
}
