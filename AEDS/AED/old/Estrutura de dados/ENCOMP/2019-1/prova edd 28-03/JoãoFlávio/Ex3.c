#include<stdio.h>
#define LINHA 4
#define COLUNA 4
int pow(int k, int n)
{
	if(n==1)
	return k;
	else
	return k*pow(k,n-1);
}
int main()
{
	int base,expoente;
	scanf("%d",&base);
	scanf("%d",&expoente);
	printf("\nBase: %d \nExpoente: %d",base,expoente);
	printf("\nResultado: %d",pow(base,expoente));
	return 0;
}
