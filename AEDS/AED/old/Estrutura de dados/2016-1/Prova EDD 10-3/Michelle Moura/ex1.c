#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define TAM 3

void leitura(int mat[TAM][TAM]){
    int i, j;

    for(i=0;i<TAM;i++){
            printf("LINHA %d\n\n", i+1);

        for(j=0;j<TAM;j++){
            printf("COLUNA %d: ", j+1);
            scanf("%d", &mat[i][j]);
        }
        system("cls");
    }
}

int norma(int mat[TAM][TAM]){
    int i, j, soma[TAM]={0}, max;

    for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
            if (mat[i][j]>0){
                soma[i] = soma[i] + mat[i][j];
            }
            else if (mat[i][j]<0){
                soma[i] = soma[i] + (mat[i][j]*-1);
            }

            if(i==0){
                max = soma[i];
            }
            if(soma[i]>max){
                max = soma[i];
            }
        }
        soma[i]=0;
    }
    return max;
}


int main(){

    int mat[TAM][TAM];

    leitura(mat);
    printf("A soma absoluta das linhas eh %d", norma(mat));

    getch();
    return 0;
}
