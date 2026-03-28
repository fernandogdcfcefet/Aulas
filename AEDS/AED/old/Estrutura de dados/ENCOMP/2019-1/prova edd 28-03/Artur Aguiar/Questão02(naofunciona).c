#include <stdio.h>
#include <stdlib.h>
#define LINHA 50
#define COLUNA 50

void Encontrar_Minmax(int matriz[LINHA][COLUNA]){

    int M, ml, mc, m, l, c;
    //encontrar maior elemento da matriz
    for (c = 0; c < COLUNA; c++){
         for (l = 0; l < LINHA; l++){
               if(matriz[l][c] > M) {

                 M = matriz[l][c];
                    ml = l;
            }
         }
    }
    printf("chegou\n");
    //encontrar maior numero da linha
    for( c = 0; c < LINHA; c++)
        if(matriz[ml][c] > m){

            m = matriz[ml][c];
            mc = c;
        }
    printf("chegou\n");
    //imprimir matriz, minmax e posicao
    void Imprimir_Minmax(ml, mc, matriz);
}

void Imprimir_Minmax(int ml, int mc, int matriz[LINHA][COLUNA]){

    int l, c;
    for(c = 0; c < COLUNA; c++){
        for(l = 0; l < LINHA; l++){
            printf("%d ", matriz[l][c]);
        }
        printf("\n");
    }

    printf("Elemento Minmax: %d, posicao [%d][%d]\n", matriz[ml][mc], ml, mc);
}

int main()
{

    int i, l, c, matriz[LINHA][COLUNA];

    for(i = 0, c = 0; c < COLUNA; c++)
        for(l = 0; l < LINHA; l++, i++)
            matriz[l][c] = i;

    Encontrar_Minmax(matriz);
    return 0;
}
