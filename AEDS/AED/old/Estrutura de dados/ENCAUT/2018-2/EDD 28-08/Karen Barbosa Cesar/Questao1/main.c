#include <stdio.h>
#include <stdlib.h>
#define N 2

typedef struct{
    int dia;
    int mes;
    int ano;
} data;

typedef struct{
    char descricao[60];
    data d1;
} compromisso;

void LeComp(compromisso C[N]){
    int i;
    for(i=0;i<N;i++){
        printf("Digite com a descricao do compromisso: ");
        gets(C[i].descricao);
        printf("Digite o dia do compromisso: ");
        scanf("%d", &C[i].d1.dia);
        printf("Digite o mes do compromisso: ");
        scanf("%d", &C[i].d1.mes);
        printf("Digite o ano do compromisso: ");
        scanf("%d", &C[i].d1.ano);
        printf("\n");
    }
}

/*char ProxComp(data D, compromisso V[N]){
    int i;
    compromisso V1;
    for(i=0;i<N;i++){
        if(V->d1 > D){
            V1.descricao = V.descricao;
        }
    }
    return V1.descricao
}*/

int main()
{
    compromisso Comp[N];
    LeComp(Comp);
    return 0;
}
