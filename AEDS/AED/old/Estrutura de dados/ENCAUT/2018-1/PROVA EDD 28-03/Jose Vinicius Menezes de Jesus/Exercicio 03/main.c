#include <stdio.h>
#include <stdlib.h>
int divisao(int dividendo, int divisor, int *resto){
    int div = dividendo/divisor;
    *resto = dividendo%divisor;
    return div;
}
int main()
{
    int r, d;
    d = divisao(5, 2, &r);
    printf("Resultado: %d Resto: %d", d, r);
    return 0;
}
