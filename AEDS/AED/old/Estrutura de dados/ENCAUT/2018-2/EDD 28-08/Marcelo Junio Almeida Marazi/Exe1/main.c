#include <stdio.h>
#include <stdlib.h>
#define N 60

typedef struct{

    char descricao[N];
    data d[N];

} compromisso;

void data(){
    int dia;
    int mes;
    int ano;
}

char proximocompromisso(data d1[N], compromisso descricao[N]){
    data datual;
    int i;
    for(i=0;i<N;i++){
        printf("Digite o compromisso %d: ". i+1);
        scanf("%s", compromisso[i].descricao);
        printf("Digite a data do compromisso %d: ",i+1);
        printf("Dia: ");
        scanf("%d", &d1[i].dia);
        printf("Mes: ");
        scanf("%d", &d1[i].mes);
        printf("Ano: ");
        scanf("%d", &d1[i].ano);

    }
    printf("Digite a data atual");
    printf("Dia: ");
    scanf("%d", &datual.dia);
    printf("Mes: ");
    scanf("%d", &datual.mes);
    printf("Ano: ");
    scanf("%d", &datual.ano);

    for(int i=0;i<N;i++){
            if(datual.ano <= d1[i].ano){
                if(datual.mes <= d1[i].mes){
                    if(datual.dia < d1[i].dia){
                        printf("Proximo compromisso: %c", )
                    }
                }
            }
    }



}

int main()
{
    proximocompromisso()
    return 0;
}

