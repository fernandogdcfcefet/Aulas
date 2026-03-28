#include <stdio.h>
#include <stdlib.h>
#define N 4

typedef struct
{
    int dia[N], mes[N], ano[N];
}   Data;

void preenche_compromisso(char vetor[N][60],Data compromisso)
{
    int i;
    for(i = 0; i < N; i ++)
    {
        printf("COMPROMISSO %d: ", i+1);
        fflush(stdin);
        gets(vetor[i]);
        fflush(stdin);
        printf("DIA DO COMPROMISSO: ");
        scanf("%d", &compromisso.dia[i]);
        printf("MES DO COMPROMISSO: ");
        scanf("%d", &compromisso.mes[i]);
        printf("ANO DO COMPROMISSO: ");
        scanf("%d", &compromisso.ano[i]);
    }
}

int main()
{
    char vetor[N][60];
    Data compromisso;
    preenche_compromisso(vetor[N][60], compromisso);
    return 0;
}
