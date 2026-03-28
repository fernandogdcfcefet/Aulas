#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>


int divisao(int dividendo, int divisor,int *resto){
	int d;
 d=dividendo/divisor;
	*resto=(dividendo%divisor);
	return d;
	return *resto;
}


int main(){
	
	int r, d;
	d=divisao(5,2,&r);
	
	printf("Resultado:%d Resto:%d",d,r);
	getch();
	return 0;
}

