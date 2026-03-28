#include <stdio.h>
#include <stdlib.h>

int recursivo(int k, int n){
    int i, result = k;
    for(i=0;i<n-1;i++){
        result = result*k;
    }
    return result;
}

int main()
{
    int a,b;
    printf("Digite o valor do numero: ");
    scanf("%d", &a);
    printf("Digite o valor da potencia: ");
    scanf("%d", &b);
    printf("Resultado: %d", recursivo(a,b) );

    return 0;
}
