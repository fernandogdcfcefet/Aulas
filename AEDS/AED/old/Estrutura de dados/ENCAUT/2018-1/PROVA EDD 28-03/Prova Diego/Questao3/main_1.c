#include <stdio.h>
#include <stdlib.h>

int Divisao(int Dividendo, int Divisor, int *resto){

    int Resultado;

    Resultado = Dividendo/Divisor;
    *resto = Dividendo%Divisor;

    return Resultado;

}

int main()
{
    int r,d;

    d = Divisao(5,2,&r);

    printf("Resultado: %d Resto: %d",d,r);

    return 0;
}
