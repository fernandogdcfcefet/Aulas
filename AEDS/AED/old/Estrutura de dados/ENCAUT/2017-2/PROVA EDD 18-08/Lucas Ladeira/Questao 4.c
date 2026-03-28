#include <stdio.h>
#include <stdlib.h>

#define p 3.14



void calc_esfera(float r, float *a, float *v){
	*a=4*3.14*r*r;
	*v=(4/3)*3.14*p*r*r*r;
	printf("Area: %.2f",*a);
	printf("Volume: %.2f",*v);
	
}


int main(){
	float *area; 
	float *volume;
	float r=10;
	*area=10;
	*volume=10;
	calc_esfera(r, &area, &volume);
	
	
	return 0;
}
