#include <stdio.h>
#include <stdlib.h>

int menorvalor(int m[6][6]){
  int i, j, vet[6],men;

  for(i=0;i<6;i++){
    for(j=0;j<6;j++){
        if((i+j)==5){
            vet[i]=m[i][j];
        }
    }
  }
  men=vet[0];
  for(i=0;i<5;i++){
    if(vet[i]<men){
        men=vet[i];
    }

  }
  return men;
}


int main()
{
  int mat[6][6],i,j,result;
  for(i=0;i<6;i++){
    for(j=0;j<6;j++){

        printf("Digite um numero: \n");
        scanf("%d",&mat[i][j]);
    }
  }

  result=menorvalor(mat);
  printf("O menor valor da diagonal secundaria e: %d ",result);
  system("pause");
  return 0;

}
