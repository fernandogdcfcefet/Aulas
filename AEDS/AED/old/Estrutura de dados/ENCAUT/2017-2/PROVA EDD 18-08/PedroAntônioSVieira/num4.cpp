#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<strings.h>
#define p 3.145


void calc_esfera(float R, float *area, float *volume){
	*area=(4*p*(R*R));
	*volume=(4/3*p*(R*R*R));
	
}



int main(){
	float raio, area,volume;
	
	printf("Informe o raio da esfera: ");
	scanf("%f", &raio);
	
	calc_esfera(raio,&area,&volume);
	
	printf("\n%.3f = area\n%.3f = volume",area, volume);
	
}
