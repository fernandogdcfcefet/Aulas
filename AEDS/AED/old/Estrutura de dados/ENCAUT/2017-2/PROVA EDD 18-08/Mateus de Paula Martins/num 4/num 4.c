#include <stdio.h>
#include <stdlib.h>

void calc_esfera (float *area, float R, float *volome)
{
	int a=0;
	
	a=4*p*(R*R);
	
}


int main(int argc, char *argv[]) {
	
	float a,p,  R, volume;
	
	printf("informe a area");
	scanf("%f",&a);
	
	printf("informe o raio");
	scanf("%f",&r);
	
	calc_esfera(&a,R, &volume);
	
	return 0;
}
