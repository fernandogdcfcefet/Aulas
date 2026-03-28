#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int divisao(int dividendo,int divisor,int *resto)
{    
    int divisaointeira;
    divisaointeira=divisor/divisor;
	
	return divisaointeira;
}
int main()
{ 
   int r,d;
   d=divisao(5,2,&r);
   printf("Resultado: %d Resto: %d",d,r);
    
	return 0;
	
}
