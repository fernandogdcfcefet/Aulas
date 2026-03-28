#include <stdio.h>
#include <stdlib.h>
#define X 2 //linha
#define Y 2 //coluna

void matriz(){
  int i, j, m[X][Y], menorx[0][0], maiorm[0][0];



  for(i=0; i<X; i++){
    for(j=0; j<Y; j++){
       printf("Insira volores para uma matriz: ");
       scanf("%d", &m[i][j]);
    }
  }

  menorx[0][0] = m[0][0];

  for(i=0; i<X; i++){
    for(j=0; j<Y; j++){
        printf("%d ", m[i][j]);
    }
      printf("\n");
  }

  for(i=0; i<X; i++){
    for(j=0; j<Y; j++){
       if(menorx[0][0]<m[i][j]){
         menorx[0][0] = m[i][j];
       }
    }
  }

  printf("\n\nMenor valor: %d", menorx[0][0]);

}

int main(){

  matriz();

  return 0;
}
