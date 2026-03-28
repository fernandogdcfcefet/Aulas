#include <stdio.h>
#include <stdlib.h>
int divisao(int dividendo,int divisor,int *resto){

  if(dividendo  / divisor ){

      if((*resto != 1) && ( *resto >= divisor) ){
          return divisao(dividendo,divisor,*resto);
      }
  }



}






int main()
{
    int r,d;
    d=divisao(5,2,&r);
    printf("RESULTADO :%d Resto: %d",d,r);
    return 0;
}
