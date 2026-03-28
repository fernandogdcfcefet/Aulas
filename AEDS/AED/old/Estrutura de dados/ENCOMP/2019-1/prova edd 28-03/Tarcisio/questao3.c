#include <stdio.h>
#include <stdlib.h>

int calcule(int k, int n)
{
    int total;
    if(n==0)
    {
        k=1;
        n=1;
    }
    else if(n>0)
    total=k*calcule(k,n-1);
    return total;
}


int main()
{
    int k, n;

    calcule(k,n);
    printf("%d\n", total);
    return 0;
}
