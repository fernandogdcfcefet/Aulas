#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int divisao(int dividendo, int divisor, int *resto){
	
	int resultado;
	
		resultado= dividendo/divisor;
	
return resultado;
}

int main(){
	
	int r, d;
	
	d= divisao(5,2, &r);
	
	printf("resultado: %d resto: %d", d, r);
	
return 0;	
}
