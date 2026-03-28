#include <stdio.h>
#include <stdlib.h>

int divisao(int dividendo, int divisor, int *resto){
  int result;
  result=(dividendo/divisor);
  *resto=dividendo-(divisor*result);
  return (result);

}

int main()
{
   int r,d;
   d=divisao(5,2,&r);
   printf("Resultado: %d , Resto: %d ", d, r);
   system("pause");
   return 0;
}
