#include<stdio.h>
#include<stdlib.h>


int divisao(int dividendo, int divisor, int *resto){

    int d;
    d = (dividendo/divisor);
    *resto = (dividendo%divisor);

return d;
}



int main(){

 int dividendo;
 int divisor;
 int d;
 int resto;

 printf("Digite o valor do dividendo : ");
 scanf("%d" , &dividendo);

 printf("Digite o valor do divisor : ");
 scanf("%d" , &divisor);

    divisao(dividendo, divisor , &resto);
    printf(" O Resultado e: %d e o Resto e: %d " , d , resto);

return 0;
}
