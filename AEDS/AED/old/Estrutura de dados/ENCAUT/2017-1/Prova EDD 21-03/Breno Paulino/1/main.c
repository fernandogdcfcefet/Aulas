#include <stdio.h>
#include <stdlib.h>
#define n 4
int norma(int mat[n][n], int x)
{
  int i, j, aux=0;
  for(i=0; i<x; i++)
  {
    for(j=0; j<x; j++)
    {
      aux+=mat[i][j];
    }
  }
  return aux;
}
int main()
{
    int mat[n][n];
    int i, j;
    for(i=0; i<n; i++)
    {
      for(j=0; j<n; j++)
      {
        mat[i][j]=i+j;
      }
    }
    for(i=0; i<n; i++)
    {
      for(j=0; j<n; j++)
      {
        printf("%d \t", mat[i][j]);
      }
      printf("\n");
    }

    printf("\n\n%d", norma(mat, n));
    return 0;
}

