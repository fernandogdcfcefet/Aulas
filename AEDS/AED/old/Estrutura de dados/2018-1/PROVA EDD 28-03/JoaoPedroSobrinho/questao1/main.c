#include <stdio.h>
#include <stdlib.h>
#define TAM 6

int RecebeRetorna();

int main()
{
    printf("Menor valor: %d", RecebeRetorna());
    return 0;
}

int RecebeRetorna(){
    int mat[TAM][TAM], i, j, menor;
    printf("Digite os valores da matriz [linha][coluna]\n");
    for(i=0; i<TAM; i++){
        for(j=0; j<TAM; j++){
            printf("[%d][%d]: ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }
    menor = mat[0][TAM-1];

    i=0;
    j=TAM-1;

    while(i<=(TAM-1) || j>=0){
        if(mat[i][j]< menor)
            menor = mat[i][j];
        i++;
        j--;
    }

    return menor;
}
