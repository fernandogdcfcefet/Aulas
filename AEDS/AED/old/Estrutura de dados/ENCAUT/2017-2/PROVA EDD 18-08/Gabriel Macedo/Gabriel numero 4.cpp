#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>

#define pi 3,14
#define N 2


void calc_esfera (float R, float *area, float *volume){
	
	
	*area=(4*pi*(R*R));
	*volume=((4/3)*pi*(R*R*R));
	printf("A area da esfera e - %.2f cm quadrados", *area);
	printf("O volume da esfera e - %.2f cm cubicos", *volume);
	
	
}
int main(){
	float R;
	float area, volume;
	printf("Informe o raio da esfera em cm - ");
	scanf("%f", &R);
	
	calc_esfera(R, &area, &volume);
	
	return 0;
}
	
	
	
	
	

