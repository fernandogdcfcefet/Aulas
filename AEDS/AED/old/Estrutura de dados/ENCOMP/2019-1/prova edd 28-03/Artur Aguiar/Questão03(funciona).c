#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Recursiva(unsigned k, unsigned n){

    n--;
    k *= k;

    if (n)
        Recursiva(k, n);
    else
        return sqrt(k);
}

int main()
{
    unsigned k, n;
    scanf("%u %u", &k, &n);
    printf("%u\n", Recursiva(k, n));
    return 0;
}
