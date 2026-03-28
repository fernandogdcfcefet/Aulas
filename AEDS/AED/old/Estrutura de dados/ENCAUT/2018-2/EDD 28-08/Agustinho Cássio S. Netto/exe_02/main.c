#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define LINHA 3
#define COLUNA 3

void ler_matriz(int mat[LINHA][COLUNA])
{
    printf("\n");
    for(int i=0;i<LINHA;i++)
    {
        for(int j=0;j<COLUNA;j++)
        {
            printf("posição %d%d <- ",i,j);
            fflush(stdin);
            scanf("%d", &mat[i][j]);
        }
    }
}

void imprime_matriz(int mat[LINHA][COLUNA])
{
    printf("\n");
    for(int i=0;i<LINHA;i++)
    {
        for(int j=0;j<COLUNA;j++) printf("%d\t",mat[i][j]);
    printf("\n");
    }
}

void minimax_matriz(int mat[LINHA][COLUNA], int *minimax, int posicao[])
{
    int linha, maior=mat[0][0];
    for(int i=0;i<LINHA;i++)
    {
        for(int j=0;j<COLUNA;j++)
        {
            if(maior<mat[i][j])
            {
                linha=i;
            }
        }
    }
    int menor=mat[linha][0];
    for(int i=0;i<COLUNA;i++)
    {
        if(menor>mat[linha][i])
        {
            menor=mat[linha][i];
            posicao[0]=linha;
            posicao[1]=i;
        }
    }
    *minimax=menor;
}



int main()
{
    setlocale(LC_ALL,"");
    int m[LINHA][COLUNA], posicao[2], minimax;
    ler_matriz(m);
    minimax_matriz(m, &minimax, posicao);
    printf("\n minimax = %d", minimax);
    printf("\n posição = %d%d", posicao[0], posicao[1]);
    imprime_matriz(m);
    printf("\n\n");
    return 0;
}
