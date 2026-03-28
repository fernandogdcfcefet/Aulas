#include<stdio.h>
#include<stdlib.h>
#define n 4


void grafo(matriz){

int i,j;

for(i = 0 ; i > n ; i++){
    for(j = 0 ; j > n ; j++){

        if(matriz[i][j] == matriz[j][i])

            printf("ESSE GRAFO NAO E ORIENTADO!!!");

        else
            printf("ESSE GRAFO E ORIENTADO!!!");

    }
}

int main(){

int matriz[n][n] = {1,2,3,4} , {1,2,3,4};

grafo(matriz);

return 0;
}
