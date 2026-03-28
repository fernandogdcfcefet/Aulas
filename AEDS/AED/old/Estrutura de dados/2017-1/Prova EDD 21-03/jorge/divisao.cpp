#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>


int divisao(int dividendo, int divisor, int *resto){
	
	int d;
	d=(dividendo/divisor);
	
	*resto=(dividendo%divisor);
	return d;
}

int main(){
	int d,r;
	
	d=divisao(5,2,&r);
	
	printf("\n Resultado:%d  Resto:%d",d,r);
	getch();
	return 0;
}
