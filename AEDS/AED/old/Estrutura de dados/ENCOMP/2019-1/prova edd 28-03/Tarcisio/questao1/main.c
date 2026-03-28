#include <stdio.h>
#include <stdlib.h>
#define N 2

typedef struct data{
    int dia, mes, ano;
}data;
int pesquisa(char x[], data consulta[])
{
    data procura;
    int dias[N], auxdias;
    int i;
    for(i=0;i<N;i++)
    {
        dias[i]=consulta[i].dia+(consulta[i].mes*30)+(consulta[i].ano*360);
    }
    printf(" Digite a data do compromisso:\n");
    scanf("%d %d %d", &procura.dia, &procura.mes, &procura.ano);
    auxdias=procura.dia+(procura.mes*30)+(procura.ano*360);
    for(i=0;i<N;i++)
    {
        if(dias[i]==auxdias)
            return 1;
        else if(dias[i]>auxdias)
            return 0;
        else if(dias[i]<auxdias)
            return auxdias-dias[i];
    }

}
void ler(char compromisso[], data consulta[])
{
    int i;
    for(i=0;i<N;i++)
    {
        printf(" Digite o nome do compromisso:\n");
        scanf("%s", &compromisso[i]);
        printf(" Digite a data do compromisso:\n");
        scanf("%d %d %d", &consulta[i].dia, &consulta[i].mes, &consulta[i].ano);
    }
}

int main()
{
    char compromisso[N][60];
    data consulta[N];
    int proximo;
    ler(compromisso, consulta);
    proximo=pesquisa(compromisso,consulta);
    if(proximo==1)
    {
        printf(" O proximo a ser consultado\n;");
    }
    else if(proximo==0)
    {
        printf(" A consulta ja passou\n;");
    }
    else  printf("%d para a consulta\n", proximo);
    return 0;
}
