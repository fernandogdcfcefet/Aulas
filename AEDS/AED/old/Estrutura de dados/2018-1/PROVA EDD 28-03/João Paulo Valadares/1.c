#include <stdio.h>
#include <stdlib.h>

void menor(int matriz[6][6]) {
    int auxiliar,a,b;
    auxiliar = matriz[0][0];
    for (a=0;a<6;a++) {
        for (b=0;b<6;b++) {
            if (a + b == 5) {
                if (auxiliar < matriz[a][b]) {
                    auxiliar = matriz[a][b];
                }

                else {

                }
            }

            else {

            }
        }
    }
    printf("%d",&auxiliar);
    return 0;
}

int main() {
    int matriz[6][6],i,j,resultado;

    for (i=0;i<6;i++) {
        for (j=0;j<6;j++) {
            scanf("%d",&matriz[i][j]);
        }
    }

    menor(matriz[6][6]);
}
