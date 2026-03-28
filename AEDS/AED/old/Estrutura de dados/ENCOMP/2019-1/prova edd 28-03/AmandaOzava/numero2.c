#include<stdio.h>
#define TAM 3

int elementoMinMax(int matriz[][TAM], int *linha, int *coluna)
{
    int maior=0, colunamaior, menor;
    for(int i=0;i<TAM;i++)
        for(int j=0;j<TAM;j++)
        {
            if(matriz[i][j]>maior)
            {
                maior=matriz[i][j];
                *linha=i;
                colunamaior=j;
            }
        }
        menor=maior;
    for(int a=*linha;a<=*linha;a++)
        for(int b=0;b<TAM;b++)
        {
            if(menor>matriz[a][b])
            {
                menor=matriz[a][b];
                *coluna=b;
            }

        }
    return menor;
}
void leituraMatriz(int matriz[][TAM])
{
    for(int i=0;i<TAM;i++)
    {
        for(int j=0;j<TAM;j++)
        {
            printf("Numero da linha [%d] coluna [%d]: ", i,j);
            scanf("%d",&matriz[i][j]);
        }
    }
}
void listarMatriz(int matriz[][TAM])
{
    printf("MATRIZ:\n");
    for(int i=0;i<TAM;i++)
    {
        for(int j=0;j<TAM;j++)
        {
            printf("%d\t",matriz[i][j]);
        }
        printf("\n");
    }

}
int main()
{
    int matriz[TAM][TAM], linha=0, coluna=0, num;
    leituraMatriz(matriz);
    listarMatriz(matriz);
    num=elementoMinMax(matriz, &linha, &coluna);
    printf("O elemento Minimax eh: %d, que se encontra na linha: %d e a coluna: %d", num, linha, coluna);

}
