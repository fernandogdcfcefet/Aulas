#include<stdio.h>
#include<stdlib.h>

int calc(int k, int n)
{
    if(n==2)
        return k*k;
    else
        return k*calc(k, n-1);
}

int main()
{
    int k, n;

    printf("Digite valores para K e N: ");
    scanf("%d %d", &k, &n);

    printf("%d", calc(k, n));

    return 0;
}


