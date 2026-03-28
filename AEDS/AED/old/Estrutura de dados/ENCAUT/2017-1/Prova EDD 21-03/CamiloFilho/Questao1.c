#include<stdio.h>

#define N 3

int norma(int mat[n][n], int n){
    int i, j, res;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++)
            res = res + mat[i][j];
    }
    return res;
}

int main(){
    int a[N][N], i, j;
    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++)
            a[i][j] = i+j;
    }
    printf("%d", norma(a,n));
    return 0;
}
