#include <stdio.h>
#include <stdlib.h>
#define N 2

int TesteGrafo(int matriz[N][]){ //Quando o grafo é orientado a matriz é espelhada
    int i = 0, aux = 0, j = 0, n =0;
    for(n=0;n<N;n++){
        for(j=0;j<N;j++){
            if(matriz[n][j] == matriz[j][n]){
                aux++;
            }
        }
    }
    i = (N*2)-2;
    if(aux == i){
        return 1;
    }
    else return 0;
}

int RetornaGrau(int matriz[N][]){//Retorna soma de grau de todos os vertices
    int n = 0, j = 0, aux = 0;
    if(TesteGrafo(matriz[N][]) == 0){
    for(n=0;n<N;n++){
        for(j=0;j<N;j++){
            if(matriz[n][j] != 0){
                    aux++;
            }
        }
    }
    }
    if(TesteGrafo(matriz[N][]) == 1){
    for(n=0;n<N;n++){
        for(j=0;j<N;j++){
            if(matriz[n][j] != 0){
                    aux++;
            }
        }
    }
    aux = aux/2;
    }
    return aux;
}
