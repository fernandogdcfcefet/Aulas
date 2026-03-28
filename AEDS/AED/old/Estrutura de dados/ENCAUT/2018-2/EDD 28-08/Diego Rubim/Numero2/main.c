#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,minimax,matriz[2][5];
    for(i=0;i<2;i++)
    {
    for(j=0;j<5;j++)
    {
    printf("Informe um numero:\n");
    fflush(stdin);
    scanf("%d",&matriz[i][j]);
    if(matriz[i][j]<matriz[i+1][j] && matriz[i+1][j]>matriz[i][j])
    {
        minimax = matriz[i+1][j];
    }
    }
    }
    for(i=0;i<2;i++)
    {
    for(j=0;j<5;j++)
    {
    printf("%d\n",matriz[i][j]);
    }
    }
    printf("Elemento minimax: %d\n",minimax);
    return 0;
}
//menor elemento da linha onde esta o maior elemento da matriz
