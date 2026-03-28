#include <stdio.h>
#include <stdlib.h>
#define compromissos 2
typedef struct{
    int dia, mes, ano;
}Data;

typedef struct {
    char vetCompromissos [30];
    char descricaoComp [60];
    Data datacomp;

}Agenda;

void lerCompromissos (Agenda a1){
    int percorreCompromisso;
    for(percorreCompromisso=0; percorreCompromisso<compromissos; percorreCompromisso++){

            printf("compromisso %d: \n", percorreCompromisso+1);
            gets(a1.vetCompromissos);
            fflush(stdin);
            printf("Descricao compromisso %d: \n ",percorreCompromisso+1 );
            gets(a1.descricaoComp);
            fflush(stdin);
            printf("Dia compromisso %d: \n", percorreCompromisso+1);
            scanf("%d", &a1.datacomp.dia);
            fflush(stdin);
            printf("Mes compromisso %d: \n", percorreCompromisso+1);
            fflush(stdin);
            scanf("%d", &a1.datacomp.mes);
            fflush(stdin);
            printf("Ano compromisso %d: \n", percorreCompromisso+1);
            scanf("%d", &a1.datacomp.ano);
            fflush(stdin);


    }

}

char ChecarCompromisso (Agenda a2.vetCompromissos, int dia, int mes, int ano){
    int percorreCompromisso;
    for(percorreCompromisso=0; percorreCompromisso<compromissos; percorreCompromisso++){
        if ((a2.datacomp.dia==dia)&&(a2.datacomp.mes=mes)&&(a2.datacomp.ano==ano)){
                return a2.vetCompromissos[percorreCompromisso+1];
           }

        else return "Erro";
    }

}
int main()
{
    Agenda a;
    lerCompromissos(a);
    int dia=10, mes=10, ano=10;
    puts(ChecarCompromisso(a.vetCompromissos,dia,mes,ano));
    return 0;
}
