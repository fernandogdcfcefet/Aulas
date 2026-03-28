#include<iostream>
#include<stdio.h>
#include<math.h>

int calculo(int k, int n){
	if(n==1)
		return k;
	else
		return k*calculo(k,n-1);
}
int main(){
	
	int a, b;
	
	printf("Digite um numero base positivo: ");
	scanf("%d", &a);
	printf("\nDigite o expoente positivo: ");
	scanf("%d", &b);
	if(a>0 && b>=0)
		printf("\n%d",calculo(a, b));
	
	return 0;
}
