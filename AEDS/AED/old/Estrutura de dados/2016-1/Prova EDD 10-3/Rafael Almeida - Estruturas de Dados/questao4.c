#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int divisao(int a, int b, int *c)
{
    int j;
    *c=a%b;
     j=a/b;

     return (j);
}
int main()
{
    int r, d;
    d=divisao(5,2,&r);
    printf("Resultado: %d Resto: %d\n", d, r);
    system("pause");
}
