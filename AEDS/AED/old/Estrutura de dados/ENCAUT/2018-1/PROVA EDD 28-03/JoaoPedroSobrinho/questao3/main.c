#include <stdio.h>
#include <stdlib.h>

int Divisao(int a, int b, int *r);

int main(){
    int r,d;
    d = Divisao(5,2,&r);
    printf("Resultado: %d Resto: %d\n",d ,r);
    return 0;
}

int Divisao(int a, int b, int *r){
    *r = a%b;
    return a/b;
}
