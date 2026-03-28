#include <stdio.h>
#include <stdlib.h>
#define N 2
#define desc 60
typedef struct Data{
    int dia, mes,ano;
}Data;
typedef struct compromisso{
    char descricao[60];
    Data data;
}compromisso;
void leVetor (compromisso comp[]){
    for (int i=0; i<N; i++){
        printf("Informe a descricao: ");
        fflush(stdin);
        gets(comp[i].descricao);
        //fflush(stdin);
        printf("Informe o dia: ");
        scanf("%d", &comp[i].data.dia);
        printf("Informe o mes: ");
        scanf("%d", &comp[i].data.mes);
        printf("Informe o ano: ");
        scanf("%d", &comp[i].data.ano);

    }
}

compromisso proximoCompromisso (Data data, compromisso comp[]){
    int qt_dia1, qt_dia2[N]; //na ordem dos parametros da função
    compromisso vazio;
    qt_dia1=(data.ano*360)+(data.mes*30)+data.dia;
    for (int i=0; i<N; i++){
        qt_dia2[i]=(comp[i].data.ano*360)+(comp[i].data.mes*30)+comp[i].data.dia;
    }

    for (int i=0; i<N; i++){
        if (qt_dia1<=qt_dia2[i]){
            return comp[i];
        }


    }

}
int main()
{
    compromisso comp[N];
    compromisso compro;
    Data dt;
    leVetor(comp);


    printf("\n\nInforme o dia: ");
    scanf("%d", &dt.dia);
    printf("Informe o mes: ");
    scanf("%d", &dt.mes);
    printf("Informe o ano: ");
    scanf("%d", &dt.ano);

    compro=proximoCompromisso(dt,comp);


    puts(compro.descricao);
    printf("\n%d/%d/%d\n",compro.data.dia,compro.data.mes,compro.data.ano);


    return 0;
}
