#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<strings.h>
#define n 10

float desvio(int v[n]){
	int i;
	float m=0,resp=0;
	for(i=0;i<n;i++){
	m=(m+v[i])/(i+1);	
	
	}
	
	for(i=0;i<n;i++){
	resp=resp+sqrt((1/(n-1))*(v[i]-m)*(v[i]-m));
	}
	return resp;
}




//funçao principal
int main(){
	int vetor[n],i;
	for(i=0;i<n;i++){
		printf("\nInforme um valor para o vetor");
		scanf("%d",&vetor[i]);
	}
	
	printf("o desvio e %.3f",desvio(vetor));
	
	
}
