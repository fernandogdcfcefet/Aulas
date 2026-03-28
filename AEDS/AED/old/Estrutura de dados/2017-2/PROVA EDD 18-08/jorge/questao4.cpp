#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>


void calc_esfera(float R, float *area,float *volume){
		float pi=3.14;
	
				*area=4*pi*R*R;
				*volume=4/3*(pi*R*R*R);
}


int main(){
	
	float R=1;
	float  A;
	float V;
	
	calc_esfera(1,&A,&V);
	getch();
	return 0;
}
