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
    total=total*k*calcule(k,n-1);
    printf("%d\n", total);
    return total;
}


int main()
{
    int k, n, total;
    printf("digite os valores\n");
    scanf("%d %d", &k,&n);
    total=calcule(k,n);
    printf("%d\n", total);
    return 0;
}
