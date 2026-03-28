#include<stdio.h>
#include<stdlib.h>

int divisao(int dividendo,int divisor, int *resto){
    int d = dividendo/divisor;
    *resto = dividendo % divisor;
    return d;

}

int main(){
    int r,d;
    d= divisao(5,2,&r);
        printf("Resultado: %d Resto: %d",d,r);

        return 0;
}
