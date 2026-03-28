#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int divisao(int dividendo, int divisor, int *r){
   *r=dividendo%divisor;
   return dividendo/divisor;

}


int main(){
int r, d;
d=divisao(5,2,&r);
printf("Resultado: %d  Resto: %d\n\n", d, r);

system("pause");
return 0;
}
