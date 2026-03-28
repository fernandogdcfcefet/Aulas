#include <stdio.h>
#include <stdlib.h>

int norma(int matriz[][3], int n){
    int i = 0, j = 0, m = 0, k = 0, l = 0, aux, soma[n];
    for(l=0;l<n;l++){
        soma[l] = 0;
        printf("%d\n", soma[l]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(matriz[j][i] < 1)
                matriz[j][i] = (-1)*matriz[j][i];
            soma[i] += matriz[j][i];
    }
    }
    for(k=0;k<n;k++){
        for(m=0;m<n;m++){
            if(soma[m]<soma[m+1]){
                aux=soma[m];
                soma[m] = soma[m+1];
                soma[m+1] =aux;
            }
        }
    }
    return soma[0];
}

int main()
{
    int matriz[3][3] = {{20,3,8},{1,-4,-6}}, maiorvalor = 0, n = 3;
    maiorvalor = norma(matriz, n);
    printf("%d", maiorvalor);
    return 0;
}
