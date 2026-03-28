#include <stdio.h>
#include <stdlib.h>
#define DIM 6
float menorMat(float mat[][DIM]){
    float menor = mat[0][5];
    for(int i = 0; i < DIM; i++){
        if(menor > mat[i][(DIM-1)-1]){
            menor = mat[i][(DIM-1)-1];
        }
    }
    return menor;
}
int main()
{
    float matriz[DIM][DIM] = {{1, 2, 3, 4, 5, 6}, {7, 8, 1, 32, 45, 5}, {0, 2, 65, 31, 445, 45}, {34, 32, 454, 3, 1, 1}, {23, 1, 12, 1, 1, 9}, {99,  9, 9,  9, 9, 9}};
    printf("%.2f" , menorMat(matriz));
    return 0;
}
