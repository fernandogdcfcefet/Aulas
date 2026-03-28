#include <stdio.h>
#include <stdlib.h>


int divisao( int dividendo, int divisor){
int *resto=0;
*resto=dividendo%divisor;
int result=0;
result=dividendo/divisor;

return result;
}
int main()
{int dd,ds,dint;
int *resto;
printf("digite o valor do dividendo e do divisor:");
scanf("%d",dd);
scanf("%d",ds);

dint=divisao(dd,ds,&resto);

    printf("o result. da divisao:%d\n o resto da divisao:%d",dint,*resto);
    return 0;
}
