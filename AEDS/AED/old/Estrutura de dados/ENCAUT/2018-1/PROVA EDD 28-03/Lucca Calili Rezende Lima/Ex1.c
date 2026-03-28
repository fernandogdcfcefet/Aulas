#include <stdio.h>
#include <stdlib.h>


int menor_Elemento_diagonal_secundaria(int A[6][6]){

if(A[0][5]<=A && A[0][5]<=A[1][4] && A[0][5]<=A[2][3] && A[0][5]<=A[3][2] && A[0][5]<=A[4][1] && A[0][5]<=A[5][0]){
    printf("%d",A[0][5]);
}

if(A[1][4]<=A && A[1][4]<=A[0][5] && A[1][4]<=A[2][3] && A[1][4]<=A[3][2] && A[1][4]<=A[4][1] && A[1][4]<=A[5][0]){
    printf("%d",A[1][4]);
}


if(A[2][3]<=A && A[2][3]<=A[1][4] && A[2][3]<=A[05][3] && A[2][3]<=A[3][2] && A[2][3]<=A[4][1] && A[2][3]<=A[5][0]){
    printf("%d",A[2][3]);
}


if(A[3][2]<=A && A[3][2]<=A[1][4] && A[3][2]<=A[2][3] && A[3][2]<=A[0][5] && A[3][2]<=A[4][1] && A[3][2]<=A[5][0]){
    printf("%d",A[3][2]);
}


if(A[4][1]<=A && A[4][1]<=A[1][4] && A[4][1]<=A[2][3] && A[4][1]<=A[3][2] && A[4][1]<=A[0][5] && A[4][1]<=A[5][0]){
    printf("%d",A[4][1]);
}


if(A[5][0]<=A && A[5][0]<=A[1][4] && A[5][0]<=A[2][3] && A[5][0]<=A[3][2] && A[5][0]<=A[4][1] && A[5][0]<=A[0][5]){
    printf("%d",A[5][0]);
}

}



int main()
{
    int matrizA[6][6]={{0},{0}};

    for(int i=0;  i<6;i++){
          for(int j=0;  j<6;j++){

            printf("\nInforme valo da linha[%d]coluna[%d]: ", i+1,j+1);
            scanf("%d", & matrizA[i][j]);

          }

    }


  menor_Elemento_diagonal_secundaria(matrizA);


    return 0;
}
