#include<stdio.h>
#include<math.h>

int main(){
	int x, y, z, base, resultado;
	printf("Base: ");
	scanf("%d", &base);
	printf("X Y Z: ");
	scanf("%d %d %d", &x, &y, &z);
	resultado = x*pow(base,2) + y*pow(base,1) + z*pow(base, 0); 
	printf("\n%d%d%d - Base10 = %d", x,y,z, resultado);
}
