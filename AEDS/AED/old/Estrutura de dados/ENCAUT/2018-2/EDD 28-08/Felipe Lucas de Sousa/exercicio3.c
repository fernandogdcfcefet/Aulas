#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int potencia(int k, int n){
	if(n == 1){
		return k;
	}else{
		return pow(k,n);
	}
}


void main(){
	int a=3, b=3;
	
	printf("%d ^ %d = %d ", a, b, potencia(a,b));
	
	
	
}
