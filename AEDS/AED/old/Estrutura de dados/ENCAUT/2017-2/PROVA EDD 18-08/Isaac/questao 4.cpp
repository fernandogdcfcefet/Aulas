#include <stdio.h>
#include <stdlib.h>

#define P 3.14

void calc_esfera(float r, float *area, float *volume) {
	*area = 4*P*r*r;
	*volume = (4/3)*P*r*r*r;
}

int main() {
	float r, area, volume;
	
	
	printf("insira o raio da esfera: ");
	scanf("%f", &r);
	
	calc_esfera(r, &area, &volume);
	
	printf("Area: %.2f, Volume: %.2f", area, volume);
	return 0;
}
