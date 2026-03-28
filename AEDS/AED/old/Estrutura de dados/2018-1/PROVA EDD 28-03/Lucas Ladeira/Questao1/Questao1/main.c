#include <stdio.h>
#include <stdlib.h>

int MenorElemento (int A[6][6]){
    int i, j, compara;
    for(i=0; i<6; i++){
        for(j=0; j<6; j++){
            if ((i==0)||(j==5)){
                compara = A[i][j];

            }
            else if(A[i][j]==A[j][i]){
                if(A[i][j]<compara){

                    compara = A[i][j];

                }

            }

        }


    }
    return compara;

}
int main()
{
    int A[6][6], i, j;
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            scanf("%d", &A[i][j]);

        }

    }
    printf("%d\n", MenorElemento(A));
    return 0;
}
