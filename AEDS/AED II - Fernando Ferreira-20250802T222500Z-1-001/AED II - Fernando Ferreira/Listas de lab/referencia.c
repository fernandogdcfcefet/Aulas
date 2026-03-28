/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

/**
 * Procedimento que recebe dois parâmetros: 
 * "a" é passado por referência
 * "b" é passado por valor
*/
void modificaVariavel (int* a, int b)
{
    (*a) = 20;
    b = 10;
}

void soma (int a, int b, int* resultado)
{
    (*resultado) = a + b;
}

int main()
{
    printf("Hello World");

    int a = 10;
    int b = 20;
    
    int resultado = 0;
    modificaVariavel(&a, b);
    // a = 20 b = 20
    soma(a, b, &resultado);

    return 0;
}
