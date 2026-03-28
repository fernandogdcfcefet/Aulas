#include <stdio.h>
#include <stdlib.h>
int divisao(int dividendo, int divisor, int *resto){
    resto = dividendo%divisor ;
    return dividendo/divisor ;

}

int main()
{
    int d1,d2,r;
    scanf("%d %d", &d1,&d2);
    printf(divisao(d1,d2,&r));
    return 0;
}
