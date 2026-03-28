#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define tam 4

int retorna(int mat[tam[tam]){
     int i, jcont=0;

    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            if(mat[i][j]==mat[j][i]){
                cont=1;
            }
        }
    }

    return cont
}


int main(){
    int i, j, mat[tam][tam], cont;


    for(i=0;i<tam;i++){
            printf("linha %d\n", i+1);
        for(j=0;j<tam;j++){
            printf("coluna %d ", j+1);
            scanf("%d", &mat[i][j]);
        }
    }

    if(cont!=1){
        printf("Grafo Direcionado");
    }
    if(cont==1){
        printf("Grafo nao direcionado");
    }

    getch();
    return 0;



}
