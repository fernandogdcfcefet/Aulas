#include <stdio.h>
#include <stdlib.h>

float desvio(float n[3], float m){
		float valor;
		int i;
		for(i=0; i<3; i++){
			valor=sqrt((1-3)*(n[i]-m)*(n[i]-m));
			
		}
		return (valor);
}

int main(){
	float v[3], total=0, media, des;
	int i;
	
	for(i=0; i<3; i++){
		printf("Digite os numeros:\n");
		scanf("%f", &v[i]);
		total=v[i]+total;
	}
	media=total/3;
	des=desvio(v, media);
	printf("Desvio Padrao: %.2f \n",des );
	
	return 0;
}
