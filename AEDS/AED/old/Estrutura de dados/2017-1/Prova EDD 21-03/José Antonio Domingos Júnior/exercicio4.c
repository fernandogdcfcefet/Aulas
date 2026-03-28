#include<conio.h>
#include<stdio.h>
int divisao(int dividendo, int divisor, int *resto){

    int resultado= (dividendo/divisor);
    *resto= dividendo%divisor;
return resultado;
}

int main(){
    int r, d;
    d= divisao(5, 2, &r);
    printf("\nResultado: %d Resto: %d" , d, r);




return 0;
}
