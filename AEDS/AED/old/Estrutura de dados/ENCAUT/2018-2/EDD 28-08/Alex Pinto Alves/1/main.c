#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 2

typedef struct{
    int dia;
    int mes;
    int ano;
}data;

typedef struct{
    data dt;
    char desc[60];
}comp;

comp proxComp(data dt, comp compromissos[]){
    int i;
    for(i=0;i<TAM;i++){
        if(compromissos[i].dt.ano>=dt.ano){
            if(compromissos[i].dt.mes>=dt.mes){
                if(compromissos[i].dt.dia>dt.dia){
                    return compromissos[i];
                }
            }
        }
    }
}

void leComp(comp compromissos[]){
    int i;
    printf("\nCadastrando compromisso: \n");

    for(i=0;i<TAM;i++){
        printf("Descricao compromisso %d: ",i+1);
        gets(compromissos[i].desc);
        printf("Lendo dia compromisso %d: ",i+1);
        scanf("%d",&compromissos[i].dt.dia);
        printf("Lendo mes compromisso %d: ",i+1);
        scanf("%d",&compromissos[i].dt.mes);
        printf("Lendo ano compromisso %d: ",i+1);
        scanf("%d",&compromissos[i].dt.ano);
        getchar();
        printf("\n\n");

    }
}

void imprimirComps(comp compromissos[]){
    int i;
    for(i=0;i<TAM;i++){
        printf("\n\nDia: %d/%d/%d\n",compromissos[i].dt.dia,compromissos[i].dt.mes,compromissos[i].dt.ano);
        printf("Descricao: \n");
        puts(compromissos[i].desc);
    }
}

void imprimirComp(comp compromissos){
    printf("\n\nDia: %d/%d/%d\n",compromissos.dt.dia,compromissos.dt.mes,compromissos.dt.ano);
    printf("Descricao: ");
    puts(compromissos.desc);
}

int main()
{
    comp compromissos[TAM];

    data dt;
    dt.dia=01;
    dt.mes=02;
    dt.ano=2018;

    //leComp(compromissos);
    strcpy(compromissos[0].desc,"dentista");
    compromissos[0].dt.dia=2;
    compromissos[0].dt.mes=02;
    compromissos[0].dt.ano=2018;

    strcpy(compromissos[1].desc,"jantar");
    compromissos[1].dt.dia=3;
    compromissos[1].dt.mes=02;
    compromissos[1].dt.ano=2018;
    //imprimirComps(compromissos);


    imprimirComp(proxComp(dt,compromissos));
    return 0;
}
