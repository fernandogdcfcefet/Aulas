#include <stdio.h>
#include <stdlib.h>


   int divisao(int dividendo, int divisor, int *resto){
        //scanf("%d", &divisor);
        //scanf("%d", &dividendo);
        int result;
        result = dividendo/divisor;
        //*re

        printf("divisao: %d", result);
    }

int main()
{
 int r,d;
 d = divisao(5,2,&r);
 printf("Resultado:%d", d, r);
    return 0;
}
