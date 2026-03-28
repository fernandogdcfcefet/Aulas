#include <stdio.h>
#include <stdlib.h>
#define n 6

void DiagonalSec (int mat[n][n])
{
    int i, j=0, vet[n];
    for(i=n-1;i>=0;i--)
      {
        vet[i]= mat[i][j];
        j++;
      }
      printf("\n\nDiagonal Secundaria: ");

      for(i=0;i<n;i++)
      {
        printf(" %d ", vet[i]);
      }
}


int main()
{
      int mat[n][n];
      int i, j;
      for(i=0;i<n;i++)
      {
          for(j=0;j<n;j++)
          {
              printf("Posicao %d x %d ; ", i, j );
              scanf("%d", &mat[i][j]);
          }
          printf("\n");
      }
      for(i=0;i<n;i++)
      {
          for(j=0;j<n;j++)
          {
              printf("%d    ", mat[i][j]);
          }
          printf("\n");
      }

      DiagonalSec(mat);
    return 0;
}
