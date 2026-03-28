#include <stdio.h>
#include <stdlib.h>
int potencia(int k, int n){

    if(n==0)
        return 1;
    else
        return k*potencia(k,n-1);
}

int main()
{
    int k,n;

    printf("Informe dois numeros inteiros:\n");
    scanf("%d %d", &k, &n);

    printf("\nK elevado ao expoente n e: %d\n", potencia(k,n));
    return 0;
}
