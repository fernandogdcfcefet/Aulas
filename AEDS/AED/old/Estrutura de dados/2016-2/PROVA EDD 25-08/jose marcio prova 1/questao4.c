#include<stdio.h>
#include<stdlib.h>

int divisao(int dividendo, int divisor, int *resto){

int d = (dividendo/divisor);

*resto = (dividendo%divisor);

return d;
}

int main(){

int d;
int resto;

d = divisao(5,2,&resto);

printf("Resultado: %d \n\n" , d);
printf("Resto: %d \n\n" , resto);

return 0;
}
