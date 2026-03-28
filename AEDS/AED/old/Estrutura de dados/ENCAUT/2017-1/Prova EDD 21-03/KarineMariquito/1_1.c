#include <stdio.h>
#include<stdlib.h>
#include <conio.h>

#define N 3

int norma(int mat[N][N], int *a){
    int i, j;
    int soma[N]={0};
    int maior=0;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(mat[i][j]>0){
                soma[i]+= mat[i][j];
            }
            if(mat[i][j]<0){
                soma[i]+= (mat[i][j])*(-1);
            }
        }
    }
    for(i=0; i<N; i++){
        if(maior<soma[i]){
            maior=soma[i];
            *a= i;
        }
    }
 return maior;

}

int main(){
    int m[N][N];
    int i,j, aux2, a;

    printf("Preencha a matriz: ");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("\nMatriz [%d][%d]", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    a=norma(m, &aux2);

    printf("\n\nA maior soma e: %d, Linha %d\n\n", a, aux2);
    system("PAUSE");
    return 0;
}
