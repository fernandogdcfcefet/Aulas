#include <stdio.h>
#include <stdlib.h>

int MenorValorDiagSecundaria(int B[][6]){
    int i,j,a=0,b=5, DiagSec[6], menorvalor;

    for(i=0;i<6;i++){
    for(j=5;j>=0;j--){
        if(i==a && j==b){
            DiagSec[i] = B[i][j];
        }
    }
        a++;
        b--;
    }

    for(i=0;i<6;i++){
        if(i==0){
            menorvalor = DiagSec[i];
        }
        if(DiagSec[i] < menorvalor){
            menorvalor = DiagSec[i];
        }
    }
}

int main()
{

    int A[6][6], menorvalor;
    int i,j;

    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            A[i][j] = i*j+1;
        }
    }


    menorvalor = MenorValorDiagSecundaria(A);

    printf("O menor valor da Diagonal Secundaria foi: %d",menorvalor);



    return 0;
}
