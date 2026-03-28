#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 2

typedef struct
{
    int dia,mes,ano;
} data;

typedef struct
{
    char comp[60];
    data d;
} compromisso;

void lerVetor(compromisso vet[N])
{
    int i;
    for(i=0;i<N;i++)
    {
            printf("Insira um compromisso:");
            fflush(stdin);
            gets(vet[i].comp);
            printf("Insira a data deste compromisso(dia/mês/ano):");
            do
            {
                    scanf("%d/%d/%d",&vet[i].d.dia,&vet[i].d.mes,&vet[i].d.ano);
                    if((vet[i].d.dia <=0 || vet[i].d.dia >30) && (vet[i].d.mes <=0 || vet[i].d.mes >12) && (vet[i].d.ano < 0))
                    {
                        printf("Data inválida, por favor insira outra:");

                    }
            }while(vet[i].d.dia <=0 || vet[i].d.dia >30 && vet[i].d.mes <=0 || vet[i].d.mes >12 && vet[i].d.ano < 0);

    }

}

void lerData(data d)
{
    printf("Insira a data(dia/mês/ano): ");
    do
            {
                    scanf("%d/%d/%d",&d.dia,&d.mes,&d.ano);
                    if(d.dia <=0 || d.dia >30 && d.mes <=0 || d.mes >12 && d.ano < 0)
                    {
                        printf("Data inválida, por favor insira outra:");

                    }
            }while(d.dia <=0 || d.dia >30 && d.mes <=0 || d.mes >12 && d.ano < 0);
}

compromisso buscaComp(data d, compromisso vet[N])
{
    int i, j;
    compromisso prox;
    for(i=0;i<N;i++)
    {
        if(d.dia > vet[i].d.dia && d.mes >= vet[i].d.mes && d.ano >= vet[i].d.ano)
        {
            for(j=0;j<N;j++)
            {
                if(j > 0 && (vet[j].d.dia < vet[j-1].d.dia && vet[j].d.mes <= vet[j-1].d.mes && vet[j].d.ano <= vet[j-1].d.ano) )
                {
                    prox = vet[j];
                }
            }
        }
    }
    return prox;
}

int main()
{
    setlocale(LC_ALL,"Portuguese");

    compromisso vet[N];
    data d;

    lerVetor(vet);
    lerData(d);
    printf("Próximo compromisso: %s\n",buscaComp(d,vet));
    return 0;
}
