#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 3

typedef struct
{
    int dia, mes, ano;
}Data;

typedef struct
{
    char descricao[61];
    Data data;
}Compromissos;

void ler_compromissos(Compromissos C[])
{
    printf("\n");
    for(int i=0; i<N; i++)
    {
        printf("Compromisso %d", i+1);
        printf("\nDigite a descrição: ");
        fflush(stdin);
        gets(C[i].descricao);
        printf("\nDigite a data:");
        printf("\ndia: ");
        scanf("%d", &C[i].data.dia);
        printf("\nmes: ");
        scanf("%d", &C[i].data.mes);
        printf("\nano: ");
        scanf("%d", &C[i].data.ano);
        printf("\n");
    }
}

Compromissos comp_data (Compromissos C[], Data D)
{
    int cont=-1;
    for(int i=0;i<N;i++)
    {
        if(C->data.ano>D.ano) cont=i;
        else if(C->data.ano==D.ano && C->data.mes>D.mes) cont=i;
        else if(C->data.ano==D.ano && C->data.mes==D.mes && C->data.dia>D.dia) cont=i;
    }
    return C[cont];
}

int main()
{
    setlocale(LC_ALL,"");
    printf("\n\n");
    return 0;
}
