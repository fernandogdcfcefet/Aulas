#include <stdio.h>
#include <stdlib.h>
#define linha 2
#define coluna 2

int maior(int matriz[linha][coluna])
{
    int i, j, aux1, aux2, aux3, col, lin;

    for(i=0;i<linha;i++)
    {
        for(j=0;j<(linha-1);j++)
        {
            if(j==(j+1))
            {
                aux2=j;
                aux1=coluna[j];
            }
            else if(j>(j+1))
             {
                 aux2=j;
                aux1=coluna[j];
             }
            else if(j<(j+1))
             {
                 aux2=j+1;
                aux1=coluna[j];
             }
        }
        if(i==(aux2))
             aux3=i;
            aux1=lin[i];
            else if(i>(aux2))
             aux3=i;
            aux1=lin[i];
            else if(i<(aux2))
             aux3=i;
            aux1=aux2;
    }

    return 0;
}

int main()
{
    int matriz[linha][coluna];

    maior(matriz);
    printf("Hello world!\n");
    return 0;
}
