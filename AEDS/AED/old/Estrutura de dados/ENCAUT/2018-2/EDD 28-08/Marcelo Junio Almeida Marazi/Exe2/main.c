#include <stdio.h>
#include <stdlib.h>
#define LINHA 3
#define COLUNA 3


void minimax(int m[LINHA][COLUNA]){
    int i,j;
    int maiortermo[LINHA][COLUNA] = {0}, menortermo[LINHA][COLUNA] = {0};
    for(i=0;i<LINHA;i++){
        for(j=0;j<COLUNA;j++){
            if(i==0 && j==0){
                maiortermo[i][j] = m[i][j];
            }else{
                if(matriz[i][j] > maiortermo[i][j]){
                    maiortermo[i][j]
                }
            }

        }
    }
    imprime(m,menortermo);
}




void imprime(int m1[LINHA][COLUNA], int menortermo1){
    printf("Matriz:\n");
    int i,j;
    for(i=0;i<LINHA;i++){
        for(j=0;j<COLUNA;j++){
            printf("%d\t", m1[i][j]);
        }
        printf("\n");
    }
    printf("\nElemento minimax: ");
    printf("%d", menortermo1);
    //printf("[%d][%d]", posicaoi,posicaoj);
}



int main()
{
    int matriz[LINHA][COLUNA], i,j;
    for(i=0;i<LINHA;i++){
        for(j=0;j<COLUNA;j++){
            printf("Digite um valor inteiro para a posicao [%d][%d] da matriz: ", i+1,j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    minimax(matriz);

    return 0;
}
