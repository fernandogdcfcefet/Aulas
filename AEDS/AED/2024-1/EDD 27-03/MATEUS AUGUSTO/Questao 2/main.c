#include <stdio.h>
#include <stdlib.h>
#define n 3
#define x 3

typedef struct
{

    int matricula;
    char nome[50];

    float notas[x];

} aluno;

void preenche(aluno *a)
{
    float media=0;
    printf("digite a matricula do aluno: \n");
    scanf("%d",&a->matricula);

    printf("digite o nome do aluno \n");
    scanf("%s",&a->nome);

    printf("digite as %d notas do aluno: \n", x);
    for (int i=0; i<x; i++)
    {
        scanf("%f",&a->notas[i]);

    }



}

float medias(aluno *a)
{
    float soma=0;
    float media=0;
    for (int i=0; i<n; i++)
    {
        soma=soma+(a->notas[i]);
        media=soma/n;
    }

    return media;
}

int main()
{
    float med[n];
    aluno al[n];
    for ( int i=0; i<n; i++)
    {
        printf("Preencha os dados do aluno %d \n", i+1);
        preenche(&al[i]);
    }


    for ( int i=0; i<n; i++)
    {
        med[i]=medias(&al[i]);

        if( med[i]>=60)
        {
            printf("o aluno %d esta aprovado com media de %f\n", i+1, med[i]);
        }
        else
        {
            printf(" o aluno %d esta reprovado com media de %f\n", i+1, med[i]);
        }
    }
    return 0;
}
