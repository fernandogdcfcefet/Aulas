#include<stdio.h>
#include<conio.h>
#include<iostream>



int divisao(int dividendo, int divisor, int *resto)
{
	int a=0;
	
	a=(dividendo/divisor);
	*resto=(dividendo%divisor);
	
	return a;
}

int main()
{
	int r, d=0;
	
	d= divisao(5, 2, &r);
	
	printf("Resultado:%d Resto:%d", d, r);
	
	return 0;
}
