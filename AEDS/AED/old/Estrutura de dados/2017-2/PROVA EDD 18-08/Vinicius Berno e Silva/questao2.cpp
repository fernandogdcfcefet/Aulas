#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define n 2
#define x 3
int maior( float media[], char nome[])
{
	
	int z , maior;
	
	for (z=0 ; z<x ;z++)
	{
		if (media[z] > maior)
		{
			maior = media[z];
		}	
	}
	printf("ALUNO APROVADO");
	printf("%d", nome[z]);
	printf("%f", media[z]);
}
int main(){

	int matricula , z;
	float nota[x] , media[x];
	char nome[n];	
	
	for (z=0 ; z<n ;z++)
	{
	printf("Digite o nome do aluno");
	gets("%s",nome[z]);
	printf("Digite a matricula do aluno");
	scanf("%d", &matricula);		
	
		for (z=0 ; z<x ;z++)
		{
			printf("Digite a nota a ser salva");
			scanf("%f" , nota[z]);	
			media[x] = media[x] + nota[z];
		}
		media[x] = media/x;	
	}
	maior(media[x] , nome[x]   );	
}


