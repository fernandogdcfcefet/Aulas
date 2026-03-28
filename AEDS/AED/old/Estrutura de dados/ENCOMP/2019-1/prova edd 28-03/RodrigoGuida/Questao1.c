#include <stdio.h>
#include <stdlib.h>
#define TAM 120

char agenda(char compromisso[TAM]){
    char descricao[60];
    gets(descricao);
    gets(compromisso);
    return descricao;
}

typedef struct{
    int dia,mes,ano;
}Data;


int main()
{
    Data dataEvento;
    char evento[TAM],detalhes[60];
    printf("Informe a data\n");
    scanf("%d%d%d",&dataEvento.dia,&dataEvento.mes,&dataEvento.ano);
    printf("Descreva o evento\n");
    agenda(evento);

    printf("%d/%d/%d\n",dataEvento.dia,dataEvento.mes,dataEvento.ano);
    puts(evento);

    return 0;
}

