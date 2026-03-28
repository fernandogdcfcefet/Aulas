#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

int divisao(int dividendo, int divisor, int *resto){
	*resto=dividendo%divisor;
	return dividendo/divisor;
}

int main(){
	int r, d;
	d=divisao(5, 2, &r);
	printf("Resultado:%d Resto:%d\n", d, r); /*Resultado:2  Resto:1*/
	
	system("pause");
	return 0;
}
