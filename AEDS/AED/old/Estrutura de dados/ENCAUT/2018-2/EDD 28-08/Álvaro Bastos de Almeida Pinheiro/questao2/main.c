#include <stdio.h>
#include <stdlib.h>
#define LINHA 2
#define COLUNA 2

void ler(int a,int b,int m[a][b]){
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            printf("Insira os elementos \n");
            scanf("%d",&m[i][j]);
        }
    }
}

void imprime(int a,int b,int m[a][b]){
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            printf("%d",m[i][j]);

        }
    }
}

int minimax(int a,int b,int m[a][b],int *g,int *k,int *l){
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(m[i][j]>*g){
                *g=m[i][j];
                *k=i;
                *l=j;
            }
        }
    }
    return *g;
}

int main()
{
    int matriz[LINHA][COLUNA],max=0,y=0,z=0;
    ler(LINHA,COLUNA,matriz);
    printf("\n%d\n",minimax(LINHA,COLUNA,matriz,&max,&y,&z));
    imprime(LINHA,COLUNA,matriz);
    printf("\n%d %d",y,z);
}
