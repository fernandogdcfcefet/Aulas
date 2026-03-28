#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define N 3

int norma(int mat[N][N]){
    int i, j, somaLinha, resultado, maiorValor;
    for(i=0; i<N; i++){
        somaLinha=0;
        for(j=0; j<N; j++){
        somaLinha+= mat[i][j];
        }
        resultado= abs(somaLinha);
        if(i==0){
        maiorValor= resultado;

        }
        else{
        if(resultado>maiorValor){
        maiorValor= resultado;

        }

        }
    }
    return maiorValor;
}


int main(){
    int matriz[N][N], i, j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
        printf("\n\t\tInforme um inteiro para a linha %d e coluna %d da matriz:\t", i,j);
        scanf("%d", &matriz[i][j]);
        }

    }
//        System("cls");
        printf("\n\t\tNORMA INFINITO DA MATRIZ: %d", norma(matriz));
//        System("pause");

}
