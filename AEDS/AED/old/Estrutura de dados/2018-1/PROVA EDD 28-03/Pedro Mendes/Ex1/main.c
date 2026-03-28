#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int mat[6][6];
}Matriz;

int MenorElemento(Matriz A){
    int i;
    int j;
    int k;
    for(i=5,i>=0,i--){
        for(j=5,j<=0,j--){
            while(A[i][j]>A[i+k][j+k]){
                return A[i][j];
                }
        }
    }

}

int main()
{
    int i;
    int j;
}
