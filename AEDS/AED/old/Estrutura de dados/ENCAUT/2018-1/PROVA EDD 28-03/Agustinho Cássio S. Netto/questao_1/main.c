#include <stdio.h>
#include <stdlib.h>

#define TAM 6


float funcao (float A[TAM][TAM])
{
    float diagonal[TAM], menor;
    for(int i=TAM; i>=0;i--)
    {
        diagonal[i]=A[TAM-i][i];
        printf("\n%f", diagonal[i]);
    }
    menor=diagonal[0];
    for(int i=0;i<TAM;i++)
    {
        if(diagonal[i]<menor) menor=diagonal[i];
    }
    return menor;
}

int main()
{
    float A[TAM][TAM]={{1.0,2.0,3.0,7.0,6.0,8.0},
                    {6.0,5.0,4.0,9.0,10.0,11.0},
                    {8.0,9.0,7.0,-1.0,-4.0,1.0},
                    {1.0,6.0,5.0,8.0,-7.0,-4.0},
                    {6.0,5.0,4.0,9.0,10.0,11.0},
                    {-9.0,9.0,0.0,-1.0,-4.0,0.0}};

    printf("\n\nO menor valor da diagonal secundaria eh: %f", funcao(A));

    printf("\n\n");
    system("pause");
    return 0;
}
