#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define n 3

int norma (int mat[n][n], int nun ){
int norma,i,j, soma[n]={0},aux;
     for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            soma[i]=soma[i]+mat[i][j];
        }
     }
     for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(soma[j]<soma[j+1]){
                aux=soma[j];
                soma[j]=soma[j+1];
                soma[j+1]=aux;
            }
        }
     }
     norma=soma[0];
return norma;
}

int main(){
    int mat[n][n],i,j,nm;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("informe o valor da posicao [%d][%d] da matriz: ", i,j);
            scanf("%d",&mat[i][j]);
        }
    }
    nm=norma(mat,n);

    system("cls");
    printf("Norma: %d \n\n", nm);


return 0;
}
