#include <stdio.h>
#define NUM 2

int norma(int mat[NUM][NUM], int n){
    int s[NUM]={0}, maior=0;
    for(int i=0;i<NUM;i++){
        for(int j=0;j<NUM;j++){
            if(mat[i][j] >= 0) s[i] = s[i] + mat[i][j];
            else s[i] = s[i] + mat[i][j]*(-1);
        }
    }
    maior = s[0];
    for(int i=0;i<NUM;i++){
        if(s[i]>maior) maior=s[i];
    }
    return maior;
}

int main(){
    int mat[NUM][NUM];
    for(int i=0;i<NUM;i++){
        for(int j=0;j<NUM;j++){
            printf(" - Digite o valor da matriz na posicao [%d][%d]: ",i,j);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n\tA norma da matriz e: %d\n", norma(mat,NUM));
    return 0;
}
