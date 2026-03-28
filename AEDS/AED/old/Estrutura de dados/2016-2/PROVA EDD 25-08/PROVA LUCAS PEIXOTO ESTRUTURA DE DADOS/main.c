#include <stdio.h>
#include <stdlib.h>

int norma (int mat[2][2], int n){
int i,j;
int soma = 0;
  for (i=0; i<n; i++){
       soma = soma + mat[i][j];
  }
  for (j=0; i<n;i++)



  return soma;


}

int main(){


  int mat [2][2] = {1,2,3,4};
  printf("%d\n",norma(mat[2][2],2));


}
