#include<stdio.h>
#include<stdlib.h>
#define N 3

typedef struct{

    int dia;
    int mes;
    int ano;

}data;

typedef struct{

    char descricao[60];
    data d;

}compromissos;

void ler (compromissos *p){

    int i;
    for(i=0;i<N;i++){
        printf("Informe a descricao do compromisso: ");
        fflush(stdin);
        gets(p[i].descricao);
        fflush(stdin);
        printf("Informe o dia do compromisso: ");
        scanf("%d",&p[i].d.dia);
        printf("Informe o mes do compromisso: ");
        scanf("%d",&p[i].d.mes);
        printf("Informe o ano do compromisso: ");
        scanf("%d",&p[i].d.ano);
    }
}

compromissos proxcomp(data d, compromissos v[N]){

    int i, j;
    compromissos pcomp;
    pcomp = v[0];

    for(i=0;i<N;i++){
        if((v[i].d.dia>=d.dia)&&(v[i].d.mes>=d.mes)&&(v[i].d.ano>=d.ano)){              //Verificando se a data do proximo compromisso é apos a data indicada.
            if((v[i].d.dia<=pcomp.d.dia)&&(v[i].d.mes<=pcomp.d.mes)&&(v[i].d.ano<=pcomp.d.ano)){    //Apos a verificação acima, verifico qual data é a próxima

                pcomp = v[i];
            }
            return pcomp;
        }
    }

}

void main(){

    data da;
    da.dia = 10;
    da.mes = 05;
    da.ano = 18;
    compromissos comp[N], proximo;
    ler(comp);
    proximo = proxcomp(da, comp);

    printf("O proximo compromisso e: %s no dia: %d/%d/%d", proximo.descricao, proximo.d.dia, proximo.d.mes, proximo.d.ano);
}
