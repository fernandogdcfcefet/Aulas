#include <stdio.h>
#include <stdlib.h>

int calcula(int k, int n)
{
    if(n == 1)
    {
        return k;
    }
    else
    {
        return calcula(k, n-1) * k;
    }
}

int main()
{
    int total;
    total = calcula(5,2);
    printf("%d", total);
    return 0;
}
