#include<stdio.h>
#include<stdlib.h>

int divisao(int a, int b, int *r){
    int c, d;
    d = (a%b);
    if((a%b) != 0){
      r -> (a)%(b);
    }
    if((a/b) != 0){
        c = (a/b);
    }
    return c;
}


int main(){
    int r, b;
    b = divisao(5,2,&r);
    printf("Resultado: %d Resto: %d", b, r);
}
