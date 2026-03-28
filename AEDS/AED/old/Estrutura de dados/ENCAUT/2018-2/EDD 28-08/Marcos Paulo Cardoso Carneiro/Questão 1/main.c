#include <stdio.h>
#include <stdlib.h>
#define N 1
typedef struct{
 int dia, mes,ano;
}data;
typedef struct{
    char descricao[60];
    data date;
}compromissos;

void proximocompromisso( compromissos comp[], compromissos d ){
    int i;
    for (i = 0; i < N ; i++){
        if ( d.date.dia == comp[i].date.dia){
            if (d.date.mes == comp[i].date.mes){
                if (d.date.ano == comp[i].date.ano){
                    printf("voce tem o(s) seguinte(s) compromisso(s): %s \n", comp[i].descricao);
                }
                else{
                    printf("nao ha nenhum compromisso");
                }
            }
        }
    }
}

compromissos ledata(compromissos d){
    printf("\n### informacoes sobre a data desejada: ###");
    printf("\n informe o dia");
    scanf("%d", &d.date.dia);
    printf("\n informe o mes");
    scanf("%d", &d.date.mes);
    printf("\n informe o ano");
    scanf("%d", &d.date.ano);
    return (d);

}

compromissos levetor(compromissos comp[]){
    int i;
    for (i = 0; i < N ; i++){
        printf("compromisso %d :", i + 1);
        printf("\ninforme a descricao do compromisso");
        fflush(stdin);
        gets(comp[i].descricao);
        printf("\ninforme o dia do compromisso");
        scanf("%d", &comp[i].date.dia);
        printf("\ninforme o mes do compromisso");
        scanf("%d", &comp[i].date.mes);
        printf("\ninforme o ano do compromisso");
        scanf("%d", &comp[i].date.ano);
    }

}


int main()
{
    compromissos comp[N],d;
    comp[N] = levetor(comp);
    d = ledata(d);
    proximocompromisso(comp,d);

    getch();
    return 0;
}
