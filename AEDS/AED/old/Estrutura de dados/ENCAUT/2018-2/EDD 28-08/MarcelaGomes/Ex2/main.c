#include <stdio.h>
#include <stdlib.h>
#define LINHA 4
#define COLUNA 4

void minimax(int mat[LINHA][COLUNA],int *linha, int *coluna){
    int maior = 0, menor = 0;
    for (int i=0; i<LINHA; i++)
        for(int j=0; j< COLUNA; j++){
            scanf("%d", &mat[i][j]);
        }

    for(int i=0; i<LINHA; i++)
        for(int j=0; j<COLUNA; j++){
            if(mat[i][j] > maior){
                maior = mat[i][j];
                linha = &i;
                coluna= &j;
            }
        }
}
int main()
{
    int mat[LINHA][COLUNA], *coluna, *linha;
    minimax(mat[LINHA][COLUNA], &linha, &coluna);
    printf("%d %d", *linha, *coluna);
    return 0;
}
