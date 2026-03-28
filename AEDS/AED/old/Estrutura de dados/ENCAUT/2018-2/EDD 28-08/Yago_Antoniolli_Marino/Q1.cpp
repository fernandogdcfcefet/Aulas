#include<iostream>
#include<stdio.h>
#include<math.h>
#define N 2

typedef struct{
	int dia, mes, ano;
}Data;

typedef struct{
	char descricao[60];
	Data data;
}Compromissos;

void lerCompromisso(Compromissos v[N]){
	for(int i=0; i<N; i++){
		printf("\nDigite a descricao do compromisso: ");
		fflush(stdin);
		gets(v[i].descricao);
		fflush(stdin);
		printf("\nDigite o dia do compromisso: ");
		scanf("%d", &v[i].data.dia);
		printf("\nDigite o mes do compromisso (de 1 a 12): ");
		scanf("%d", &v[i].data.mes);
		printf("\nDigite o ano do compromisso: ");
		scanf("%d", &v[i].data.ano);
	}
}

Compromissos proximo (Data d, Compromissos v[N]){
	Compromissos a;
	for(int i=0; i<N; i++){
		if(v[i].data.ano>=d.ano){
			if(v[i].data.mes==d.mes){
				if(v[i].data.dia>d.dia){
					//printf("\n %d/%d/%d:\t %s", v[i].data.dia, v[i].data.mes, v[i].data.ano, v[i].descricao);
					a=v[i];
				}
			}
			if(v[i].data.mes>d.mes){
				//printf("\n %d/%d/%d:\t %s", v[i].data.dia, v[i].data.mes, v[i].data.ano, v[i].descricao);
				a=v[i];
			}
		}
	}
	return a;
}

void lerData(Data d){
	printf("\nDigite uma data de referencia: ");
	printf("\nDia: ");
	scanf("%d", &d.dia);
	printf("\nMes (de 1 a 12): ");
	scanf("%d", &d.mes);
	printf("\nAno: ");
	scanf("%d", &d.ano);
}

int main(){
	Compromissos vetor[N], compromisso;
	Data data;

	lerCompromisso(vetor);
	system("cls");
	lerData(data);

	compromisso=proximo(data,vetor);
	printf("\n%s", compromisso.descricao);
}
