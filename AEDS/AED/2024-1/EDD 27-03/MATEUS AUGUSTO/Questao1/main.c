#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void preencher(int n)
{
    int *mat[n][n];

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)

        {
            *mat[i][j]=i+j;


printf("%d", *mat[i][j]);

        }
printf("\n");
    }

}


/*int soma(int n, int *mat[n][n])
{
    int result[n];
    int maior=result[0];

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)

        {   result[i]=result[i]+(*mat[i][j]);

            if (maior<result[i])
            {
                maior=result[i];
            }

        }

    }


return maior;
}*/

int main()
{ int n=3;
    /*printf("Insira o valor de N:");
    scanf("%d",&x);*/
    preencher(n);

    return 0;
}
