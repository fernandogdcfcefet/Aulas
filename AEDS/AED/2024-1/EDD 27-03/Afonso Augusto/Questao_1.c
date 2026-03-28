#include <stdio.h>
#include <stdlib.h>

int norma (int mat[n][n]){

    int i=0, j=0;
    
    for(i=0; i<2; i++){
        for(j=0;j<3;j++){
            n+=mat[i][j];

        }
        printf("%d",n);
    }
    return n;
}



int main(){

    int m[2][3], i, j;

    for(i=0; i<2; i++){
        for(j=0; j<3; j++){
            printf("Digite elemento da linha %d, colunha %d ", i+1, j+1);
            scanf("%d",&m[i][j]);
        }

    }

   printf("%d",norma(m[2][3]));




    return 0;
}