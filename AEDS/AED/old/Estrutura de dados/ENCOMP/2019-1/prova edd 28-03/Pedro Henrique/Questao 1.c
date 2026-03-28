#include <stdio.h>
#include <stdlib.h>
#define COMPROMISSOS 2

typedef struct{

    int dia;
    int mes;
    int ano;

}Data;

typedef struct{

    char descricao[100];
    Data data;

}Compromisso;


int converterDias(Data data){

    int i, dias;

    dias = ((data.ano * 360) + (data.mes * 30) + data.dia);

    return dias;

}

void ordenarDias(int dias[]){

    int i,j,aux;

    for(i = 0; i <= COMPROMISSOS; i++){
        for(j = 0; j <= COMPROMISSOS; j++){

            if(dias[i] < dias[j]){
                aux = dias[i];
                dias[i] = dias [j];
                dias[j] = aux;

            }
        }
    }
}


void addCompromissos(Compromisso agenda[]){

    int i;

    for(i = 0; i < COMPROMISSOS; i++){
        gets(agenda[i].descricao);
        fflush(stdin);
        scanf("%d%d%d",&agenda[i].data.dia,&agenda[i].data.mes,&agenda[i].data.ano);
        fflush(stdin);
    }
}

Compromisso proxCompromisso(Data data, Compromisso agenda[]){

    int i,j,dias[COMPROMISSOS+1];
    Compromisso proximo;

    for(i = 0; i < COMPROMISSOS; i++){

        dias[i] = converterDias(agenda[i].data);

    }

    dias[COMPROMISSOS] = converterDias(data);

    ordenarDias(dias);

    for(i = 0; i <= COMPROMISSOS; i++){

        if(converterDias(data) == dias[i]){
           for(j = 0; j < COMPROMISSOS; j++){
                if(converterDias(agenda[i].data) == dias[i+1]){
                    proximo = agenda[i];
                }
            }
        }
    }

    return proximo;

}


int main()
{
    Compromisso agenda[COMPROMISSOS];
    Data prox;

    prox.dia = 10;
    prox.mes = 10;
    prox.ano = 2010;

    addCompromissos(agenda);

     int i;

    for(i = 0; i < COMPROMISSOS; i++){

    printf("%s\n",agenda[i].descricao);
    printf("%d/%d/%d\n\n",agenda[i].data.dia,agenda[i].data.mes,agenda[i].data.ano);

    }

    printf("PROXIMO COMPROMISSO: ");
    puts(proxCompromisso(prox,agenda).descricao);
    printf("%d/%d/%d\n\n",proxCompromisso(prox,agenda).data.dia,proxCompromisso(prox,agenda).data.mes,proxCompromisso(prox,agenda).data.ano);

    return 0;
}
