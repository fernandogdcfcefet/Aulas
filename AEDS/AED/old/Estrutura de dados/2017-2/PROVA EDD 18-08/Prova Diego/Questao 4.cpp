#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void calc_esfera(float R, float *area, float *volume){
	
	float pi = 3.14;
	float A,V;
	
	*area = (4*pi)*(R*R);
	*volume = (4/3)*pi*(R*R*R); 
	
	
}


int main(){
	
	float R;
	float area;
	float volume;
	
	R = 2;
	
	calc_esfera(R,&area,&volume);
	
	printf("A area da superficie da esfera eh: %f",area);
	printf("\nO volume da esfera eh: %f",volume);
	
	
	
	
	return 0;
}
