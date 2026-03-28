#include <stdio.h>
#include <stdlib.h>
int potencia (int k, int n){
    if (n>1){

        return k*potencia(k,n-1);
    }
}
int main()
{
    //int k=5,n=2;
    printf("%d",potencia (3,2));
    return 0;
}
