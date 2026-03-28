#include <stdio.h>
#include <stdlib.h>


int potencia(int k,int n){
    return pow(k,n);
}

int main()
{
    int k,n;
    scanf("%d%d",&k,&n);
    printf("%d\n",potencia(k,n));
    return 0;
}
