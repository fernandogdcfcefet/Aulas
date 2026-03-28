#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#define N 2

typedef struct
{
    int dia, mes, ano;
}DATA;

typedef struct
{
    char descricao[60];
    DATA data;
}COMPROMISSO;

void ler_comp(COMPROMISSO *comp)
{
    int i;

    for(i=0;i<N;i++)
    {
        printf("Descrição do compromisso: ");
        gets(comp[i].descricao);

        printf("Data (use o formato DD/MM/AAAA): ");
        scanf("%d/%d/%d", &comp[i].data.dia, &comp[i].data.mes, &comp[i].data.ano);

        fflush(stdin);
    }
}

int ver_comp(COMPROMISSO comp[], int data)
{
    int i, d, menor_data=0, proximo;

    for(i=0;i<N;i++)
    {
        d = comp[i].data.dia * comp[i].data.mes * comp[i].data.ano;
        if(data <= d)
        {
            if(menor_data==0)
            {
                menor_data = d;
                proximo = i;
            }
            else if(menor_data > d)
            {
                menor_data = d;
                proximo = i;
            }
        }
        printf("%d", proximo);
    }
    printf("%d", proximo);
    return proximo;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int d, m, a, j;
    COMPROMISSO comp[N];

    ler_comp(comp);

    printf("Qual a data que deseja verificar (use o formato DD/MM/AAAA): ");
    scanf("%02d/%02d/%d", &d, &m, &a);

    j = ver_comp(comp, d*m*a);

    if(j!=-1){
        printf("\n\nDescrição: %s - Data: ", comp[j].descricao);
        printf("%02d/%02d/%d", comp[j].data.dia, comp[j].data.mes, comp[j].data.ano);
    }else{
        printf("\n\nNão existe próximo compromisso!");
    }

    return 0;
}


