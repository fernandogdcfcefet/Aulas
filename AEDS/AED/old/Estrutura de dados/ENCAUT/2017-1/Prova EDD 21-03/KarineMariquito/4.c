#include <stdio.h>
#include<stdlib.h>
#include <conio.h>

#define N 3

int divisao(int dividendo, int divisor, int *resto){
    *resto=dividendo%divisor;
    return dividendo/divisor;

}

int main(){
    int r, d;
    d=divisao(5, 2, &r);

    printf("\n\nResultado: %d Resto: %d\n\n\n", d, r);


    system("PAUSE");
    return 0;
}
