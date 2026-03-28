#include <stdio.h>
#include <stdlib.h>
#define L 2
#define C 2

int lematriz(int mat[L][C]){

    int i,j;
    printf("\n### Leitura da Matriz : ###\n");
    for(i = 0 ; i < L; i++){
        for(j = 0 ; i < C; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    return (mat[L][C]);
}

int main()
{
    int mat[L][C];

    mat[L][C] = lematriz(mat);

    getch();
    return 0;
}
