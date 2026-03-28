#include <stdio.h>
#include <stdlib.h>
#define L 2
#define C 2

void leMat(int MAT[L][C]){
    printf("Lendo a matriz: \n");
    int i,j;
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            scanf("%d",&MAT[i][j]);
        }
        printf("\n");
    }
}

void imprimeMat(int mat[L][C]){
    int i,j;
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void encontraMaior(int *l,int *c, int mat[L][C]){
    *l=0;
    *c=0;
    int i,j;
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            if(mat[i][j]>mat[*l][*c]){
                *l=i;
                *c=j;
            }
        }
    }
}

int encontraMenor(int mat[L][C]){
    int i;
    int posmenorL=0;
    for(i=0;i<C;i++){
        if(mat[i]<mat[posmenorL]){
            posmenorL=i;
        }
    }
    return posmenorL;
}

void minimax(int *l,int *c, int mat[L][C]){
    encontraMaior(l,c,mat);
    *c=encontraMenor(mat);
}

int main()
{
    int MAT[L][C];
    int l,c;
    leMat(MAT);
    printf("\n\n");
    imprimeMat(MAT);
    minimax(&l,&c,MAT);
    printf("O elemento minimax e o %d e se encontra na pos[%d][%d] da matriz\n",MAT[l][c],l,c);

    return 0;
}
