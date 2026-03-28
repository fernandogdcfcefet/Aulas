#include <stdio.h>
#include <stdlib.h>
#define N 3

typedef struct{
    int dia;
    int mes;
    int ano;
}datas;

typedef struct{
    char descricao[60];
    datas comp;
}compromissos;

void leitura(compromissos vet[]){

    int i;
    for(i=0; i<N; i++)
    {
        printf("Informe a descricao:\n");
        scanf("%s", &vet[i].descricao);
        printf("Infome a data:\n");
        scanf("%d %d %d",&vet[i].comp.dia, &vet[i].comp.mes, &vet[i].comp.ano);
    }
}

int proximo_comp(compromissos l, compromissos j, compromissos k, compromissos vet[N]){

    int i;
    compromissos proximo[20];

    for(i=0; i<N; i++){
        if(vet[i]==l && vet[i]==j && vet[i]==k){
                proximo[i]= k*360 + j*30+l;
        }
    }
}
int main()
{
    compromissos vet[N];
    compromissos data;

    leitura(vet);

    printf("Informe uma data:\n");
    scanf("%d %d %d", &data.comp.dia, &data.comp.mes, &data.comp.ano);

    int p= proximo_comp(data.comp.dia, data.comp.mes, data.comp.ano, vet);

    return 0;
}
