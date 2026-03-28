#include <stdio.h>
#include <stdlib.h>
#define  N 4

typedef struct{
    int dia, mes, ano;
}data;

void leituraVetor(){
    char vet[N][60];
    data dt[N];

    for(int i = 0; i< N; i++){
        printf("Descreva seu compromisso: ");
        gets(vet[i]);

        printf("Digite o dia: ");
        gets(dt[i].dia);
        printf("Digite o mes: ");
        gets(dt[i].mes);
        printf("Digite o ano: ");
        gets(dt[i].ano);
    }
}

char retornoCompromisso(char vet[N][60], data dt[N]){
    char compromisso[1][60];
    for(int i = 0; i< N; i++){
      if((dt[i].dia == 7)&&(dt[i].mes==9)&&(dt[i].ano == 2018))
        return vet[i];
    }
    return compromisso;
}

int main()
{
    char vet[N][60];
    data dt[N];

    leituraVetor();
    printf("O compromisso no dia indicado eh: %s", retornoCompromisso(vet[N][60], dt[N]));
    return 0;
}
