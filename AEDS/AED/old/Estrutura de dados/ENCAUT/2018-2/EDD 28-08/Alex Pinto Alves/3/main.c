#include <stdio.h>
#include <stdlib.h>

int calculaRecursiva(int k, int n){
    if(n>0){
        return k*calculaRecursiva(k,n-1);
    }
    else {
        return 1;
    }
}

int main()
{
    int res=calculaRecursiva(2,2);
    printf("resultado: %d",res);
    return 0;
}
