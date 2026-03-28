#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int exponenc(int k, int n)
{
	int i, result = 0;

	if (n == 0)	{ return 1; }
	if (n == 1)	{ return k; }

	for (i = 0; i < k ; i++)
	{
		result = k * exponenc( k , (n-1) );
	}

	return result;
}

int main()
{
	int a, b;
	puts("Introduza o valor de k:\t"); scanf("%d", &a);
	puts("Introduza o valor de n:\t"); scanf("%d", &b);
	printf("%d", exponenc(a, b));
	return 0;
}

