#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>

typedef struct 
{
	int dia, mes, ano;
} data;


int main()
{
	int n, i, d, m, a;

	printf("Informe a quantidade de compromissos que deseja armazenar:\n");
	scanf("%d",&n);
	
	data dat[n];
	char compromisso[60][n];
	
	for(i=0; i<n; i++)
	{
		printf("\n\nInforme o seu compromisso:\n");
		fflush(stdin);
		gets(compromisso[i]);
		printf("Informe o dia de seu compromisso:\n");
		scanf("%d",&dat[i].dia);
		printf("Informe o mes do seu compromisso:\n");
		scanf("%d",&dat[i].mes);
		printf("Informe o ano do seu compromisso:\n");
		scanf("%d",&dat[i].ano);
	}
	
	printf("\n\nInforme o dia que deseja consultar:\n");
	scanf("%d",&d);
	printf("Informe o mes:\n");
	scanf("%d",&m);
	printf("Informe o ano:\n");
	scanf("%d",&a);
	
	for(i=0; i<n; i++)
	{
		if((d>=dat[i].dia)&&(m>=dat[i].mes)&&(a>=dat[i].ano))
		{
			printf("\n\nCompromisso: %s \nData: %d - %d - %d",compromisso[i], dat[i].dia, dat[i].mes, dat[i].ano);
		}
	}
}
