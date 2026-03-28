#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int divisao(int dividendo, int divisor, int *resto){
    int q;

    q = (dividendo/divisor);
    *resto = dividendo%divisor;
    return q;
}


int main(){
    int r, d;

    d = divisao(5, 2, &r);
    printf("Resultado:%d \nResto: %d\n\n", d, r);

}

//if(i%2==0)
