#include<stdio.h>
#include<stdlib.h>
#define N 3
                                             ///N passado como diretiva define
int norma(int mat[N][N]){
    int i,j, aux,soma[N]={0};
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(mat[i][j]>=0){
                soma[i]=soma[i]+mat[i][j];  ///soma de cada linhas sendo armazenado na posição i do vetor soma
            }
            else if (mat[i][j]<0){
                soma[i]=soma[i]+mat[i][j]*(-1); ///caso elemento seja negativo, multiplica por (-1)
            }
        }
    }

    aux = soma[0];
    for(i=0;i<N;i++){
        if(soma[i]>aux){
          aux=soma[i];
        }
    }
return aux;
}


int main(){
    int i,j, mat[N][N], b;  ///Leitura da matriz
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("Digite mat[%d][%d]: ",i, j);
            scanf("%d",&mat[i][j]);
        }
    }
    b=norma(mat);   ///chamada do procedimento norma da matriz
    printf("\nA norma da matriz e: %d",b);



return 0;
}
