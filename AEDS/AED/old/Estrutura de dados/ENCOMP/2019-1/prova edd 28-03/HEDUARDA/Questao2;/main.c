#include <stdio.h>
#include <stdlib.h>
#define LINHA 3
#define COLUNA 3

int minimax(int M[LINHA][COLUNA]){

    int maior=M[0][0];
    int i,j;

    for(i=0; i<LINHA; i++){
        for(j=0; j<COLUNA; j++){
            if(M[i][j]>maior)
                maior=M[i][j];
        }
   }
}

int posicao(int M[LINHA][COLUNA]){

    int maior=M[0][0];
    int posicao=0,i,j;

    for(i=0; i<LINHA; i++){
        for(j=0; j<COLUNA; j++){
            if(M[i][j]>maior)
                posicao=i;
        }
   }
}

int imprime(int M[LINHA][COLUNA]){

    int i,j;

    for(i=0; i<LINHA; i++){
        for(j=0; j<COLUNA; j++){
            printf("%d", M[i][j]);
        }
        printf("\n");
   }
}

int main(){
   int i,j;
   int M[LINHA][COLUNA];

   printf("Preencha a matriz:\n");
   for(i=0; i<LINHA; i++){
        for(j=0; j<COLUNA; j++){
            scanf("%d", &M[i][j]);
        }
   }

   printf("%d", imprime(M));
   printf("ELEMENTO MINIMAX: %d\n",minimax(M));
   printf("POSICAO: %d\n", posicao(M));

   return 0;
}
