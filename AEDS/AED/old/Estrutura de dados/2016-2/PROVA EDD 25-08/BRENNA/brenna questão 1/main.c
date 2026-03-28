#include <stdio.h>
#include <stdlib.h>
#define n 2

void ler(int mat[n][n]){
   int i,j;
   for(i=0;i<n;i++){
     for(j=0;j<n;j++){
        printf("elemento [%d]  [%d]:",i ,j);
        scanf("%d",&mat[i][j]);
       }
   }

}
void imprime(int mat[n][n]){
  int i,j;
   for(i=0;i<n;i++){
     for(j=0;j<n;j++){
        printf("elemento : %d \n",mat[i][j]);

       }
   }



}
int norma(int mat[n][n],int [n],int [n]){
   int soma=0;
   int i,j;
   for(i=0;i<n;i++){
     for(j=0;j<n;j++){




}


int main()
{
    int mat[n][n];

    ler(mat);
    imprime(mat);
    return 0;

}
