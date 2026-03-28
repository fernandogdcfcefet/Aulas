#include <stdio.h>
#include <stdlib.h>

int divisao (int dividendo, int divisor, int *resto)
{
    *resto= 5 %2;
    return dividendo/divisor;
}

int main()
{
    int r=0,d=0;

    d= divisao(5,2, &r);

    printf(" Divisao: %d  Resto:  %d\n", d,r);

    return 0;
}
