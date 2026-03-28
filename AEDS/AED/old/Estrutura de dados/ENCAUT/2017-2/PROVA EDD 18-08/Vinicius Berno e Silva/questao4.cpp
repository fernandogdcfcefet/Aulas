#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define p 3.14


void calc_esfera(float R , float &area , float &volume)
{
&volume=(4/3)*p*(R*R*R);	
&area=4*p*(R*R);
return(&area,&volume);
  
}


int main()
{
	
float R , *area , *volume;

printf("Digite o raio da esfera ");
scanf("%d", &R);
	
calc_esfera(R , *area , *volume);
printf("Area da esfera : %f\n", &area);
printf("Volume da esfera : %f", &volume);

}
