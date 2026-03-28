#include <stdio.h>
#include <stdlib.h>


int divisao(int dividendo, int divisor, int *resto)
{
    int res=dividendo/divisor;
    *resto=dividendo-(res*divisor);
    return res;
}

int main()
{
    int *r;
    int d;

    d=divisao(5,2, &r);
    printf("Resultado: %d  -  Resto: %d", d, r);


    printf("\n\n");
    system("pause");
    return 0;
}
