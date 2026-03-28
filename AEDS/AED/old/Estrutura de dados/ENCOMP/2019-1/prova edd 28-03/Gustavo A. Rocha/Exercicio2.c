#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#define LINHA 2
#define COLUNA 2

void ler_matriz(int mat[LINHA][COLUNA])
{
    int i, j;

    for(i=0;i<LINHA;i++)
    {
        for(j=0;j<COLUNA;j++)
        {
            printf("Digite o elemento %d %d da matriz: ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }
}

void imp_matriz(int mat[LINHA][COLUNA], int minimax)
{
    int i, j, x, y;

    for(i=0;i<LINHA;i++)
    {
        for(j=0;j<COLUNA;j++)
            printf("%d", mat[i][j]);
        printf("\n");
    }

    x = minimax/LINHA;
    y = minimax-x*LINHA;
    printf("O elemento minimax é %d na posição %dx%d.", mat[x][y], x+1, y+1);
}

int busca_minimax(int mat[LINHA][COLUNA])
{
    int i, j, row=0, col=0, menor;

    for(i=0;i<LINHA;i++)
        for(j=0;j<COLUNA;j++)
            if(mat[i][j]>mat[row][col])
                row = i;

    for(j=0;j<COLUNA;j++)
        if(mat[row][j]<mat[row][col])
            col = j;

    return row*LINHA+col;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int matriz[LINHA][COLUNA], minimax;

    ler_matriz(matriz);
    minimax = busca_minimax(matriz);
    imp_matriz(matriz, minimax);

    return 0;
}


