#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define N 10
int desvio(int vet[N]){
	int i;
	int soma=0;
	float desvio;
	float media;
	
	
	for(i=0;i<N;i++){
		printf("digite um numero:");
		scanf("%d",&vet[i]);
		
			soma=soma+vet[i];
		
	}
			media= media+(soma/N);
	
	for(i=0;i<N;i++){
		desvio=desvio+(sqrt(1/N-1 *((vet[i]- media)*(vet[i]- media))));
	}
	
			return desvio;
}

int main(){
	getch();
	return 0;
}
