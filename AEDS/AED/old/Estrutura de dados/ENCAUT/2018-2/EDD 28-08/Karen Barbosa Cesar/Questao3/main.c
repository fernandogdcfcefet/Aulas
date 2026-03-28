#include <stdio.h>
#include <stdlib.h>

int calcula(int a,int b){
    if(b==0)
        return 1;
    if(b==1)
        return a;
    else{
        return calcula(a,b-1)*calcula(a,1);
    }
}

void LeNum(int *c,int *d){
    printf("Digite o numero da base: ");
    scanf("%d", &(*c));
    printf("Digite o expoente: ");
    scanf("%d", &(*d));
}

int main()
{
    int k,n;
    LeNum(&k,&n);
    printf("O numero %d^%d = %d",k,n,calcula(k,n));
    return 0;
}
