#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int Minimax();

int Minimax(){
    int mat[TAM][TAM], i, j, menor;

    printf("Digite os valores da matriz [LINHA][COLUNA]\n");
    for(i=0; i<TAM; i++){
        for(j=0; j<TAM; j++){
            printf("[%d][%d]",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
    }
    menor = mat[0][TAM-1];
    i = 0;
    j = TAM-1;

    while(i<=(TAM-1)|| j>=0){
        if(mat[i][j] < menor)
            menor = mat[i][j];
    }
    return menor();

}

int main()
{
    printf("Menor valor: %d", Minimax());
}

