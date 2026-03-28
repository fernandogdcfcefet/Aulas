#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int exp (int k, int n)
{
    if(k>0 && n>1) return k*exp(k, n-1);
}


int main()
{
    setlocale(LC_ALL,"");
    int k=2, n=-3;
    printf("\n %d", exp(k,n));
    printf("\n\n");
    return 0;
}
