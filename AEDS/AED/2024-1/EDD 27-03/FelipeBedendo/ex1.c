#include <stdio.h>
#include<stdlib.h>
#include<math.h>
void preencherMat(int n,int mat[n][n]){
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            printf("preenchendo a matriz \n digite um valor inteiro \n");
            scanf("%d", &mat[i][j]);
        }
    }
}
int NormaInf(int n,int mat[n][n]){
    int soma;
    int maior =0;
    for(int i =0; i<n; i++){
        soma = 0;
        for(int j =0; j<n; j++){
            soma = soma + abs(mat[i][j]);
        }
        if (soma>maior)
        {
            maior = soma;
        }
  }
  return maior;
}
int main(){
    int n;
    printf("digite a dimensao da matriz quadrada \n");
    scanf("%d", &n);
    int matriz[n][n];
    preencherMat(n,matriz);
    int x = NormaInf(n,matriz );
    printf("a norma infinito da matriz eh: %d\n",x);
    return 0;
}