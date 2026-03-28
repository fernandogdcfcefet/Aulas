#include <stdio.h>
int divisao(int dividendo, int divisor, int *resto){
	int a;
	a = dividendo/divisor;
	
	*resto = dividendo%divisor;
	
	return a;
}

int main(){
	int r,d;
	
	d = divisao(5,2,&r);
	printf("Resultado: %d  Resto:%d  ",d,r);
	
	return 0;
}
