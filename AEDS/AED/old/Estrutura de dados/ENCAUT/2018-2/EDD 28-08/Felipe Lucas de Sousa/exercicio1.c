#include <stdio.h>
#include <stdlib.h>

#define N 2
typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct{
    char descricao[60];
    Data data;
}Compromisso;

void lercompromisso(Compromisso *c){
    int i;
    for(i=0; i<N; i++){
        printf("Informe a descrição do compromisso: \n", (i+1));
        fflush(stdin);
        gets(c[i].descricao);
        fflush(stdin);

        printf("Informe o dia: ");
        scanf("%d", & c[i].data.dia);

        printf("Informe o mês: ");
        scanf("%d", & c[i].data.mes);

        printf("Informe o ano: ");
        scanf("%d", & c[i].data.ano);

        printf("\n\n--------------------------------------\n");
    }
}

void proximoscompromissos(Compromisso *c, Data *d){
	int i,flagmes=0,flagdia=0;
	for(i=0; i<N; i++){
		if((d->ano) <= (c[i].data.ano)){
			flagmes++;
			if(((d->mes) <= (c[i].data.mes)) || flagmes ==1){
				flagdia++;
				if(((d->dia) <= (c[i].data.dia)) || flagdia ==1){ 
					printf("%d/%d/%d \n", c[i].data.dia, c[i].data.mes, c[i].data.ano);
					fflush(stdin);
					puts(c[i].descricao);
					fflush(stdin);
					
					printf("\n\n");
					flagmes=0;
					flagdia=0;
				}
			}
		}	
	}	
}

void main(){
    Compromisso compromissos[N];
    Data dataprox;

	dataprox.dia = 02;
	dataprox.mes = 02;
	dataprox.ano = 18;


    lercompromisso(compromissos);
    printf("Proximos compromissos: \n");
    proximoscompromissos(compromissos,&dataprox);

}
