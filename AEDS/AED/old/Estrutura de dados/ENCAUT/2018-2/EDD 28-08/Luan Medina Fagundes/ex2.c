#include<stdio.h>
#include<stdlib.h>
#define L 3
#define C 3


void printar(int *m[L][C]){

int i,j;

    for(i=0;i<L;i++){
        for(j=0;j<C;j++){

            printf("%d ",m[i][j]);

        }
        printf("\n");
    }
}

int minimax(int *m[L][C], int *l, int *c){

int i, j;
int maior;
maior = m[0][0];
int menor = 0;

    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            if(m[i][j]>maior){

                *l = i; //Achando a linha do maior elemento;

            }
        }
    }

        for(j=0;j<C;j++){
            if(m[*l][j]>m[*l][j+1]){

                    menor = m[*l][j+1];
                    *c = j;
            }
        }

return menor;
}

void ler(int *m[L][C]){

int i,j;

    for(i=0;i<L;i++){
        for(j=0;j<C;j++){

            m[i][j] = i*j;

        }
    }
}


void main(){

int a ,b;
int mat[L][C];
ler(mat);
printar(mat);
int res = minimax(mat, &a, &b);
printf("O minimax e: %d na posicao: %d, %d", res, a, b);

}
