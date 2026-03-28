#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define LINHA 2
#define COLUNA 2

void lerMat(int mat[LINHA][COLUNA])
{
    int i,j;
    for(i=0;i<LINHA;i++)
    {
        for(j=0;j<COLUNA;j++)
        {
            printf("Insira um valor inteiro: ");
            scanf("%d",&mat[i][j]);
            system("cls");
        }
    }
}

int encontrarMinimax(int mat[LINHA][COLUNA], int *posI, int *posJ)
{
    int i,j,maior = 0,minimax;
    for(i=0;i<LINHA;i++)
    {
        for(j=0;j<COLUNA;j++)
        {
            if(mat[i][j] > maior)
            {
                maior = mat[i][j];
                *posI = i;
            }
        }
    }
    for(j=0;j<COLUNA;j++)
    {
        if(mat[*posI][j] < minimax)
        {
            minimax = mat[*posI][j];
            *posJ = j;
        }
    }
    return minimax;
}

void imprime(int mat[LINHA][COLUNA])
{
    int i,j,posI,posJ,minimax;
    for(i=0;i<LINHA;i++)
    {
        for(j=0;j<COLUNA;j++)
        {
            if(j == COLUNA-1 )printf("%d\n", mat[i][j]);
            else printf("%d ", mat[i][j]);
        }
    }
    minimax = encontrarMinimax(mat,&posI,&posJ);
    printf("Elemento minimax é %d, e sua posição está na linha %d e coluna %d",minimax,posI,posJ);
}

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int mat[LINHA][COLUNA];
    lerMat(mat);
    imprime(mat);
    return 0;
}
