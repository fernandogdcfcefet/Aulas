#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5
#define X 3


typedef struct
{
    char rua[50];
    char cidade[50];
} endereco;

typedef struct
{
    char matricula[20];
    char nome[50];
    endereco en;
    float notas[X];
} aluno;

void leitura (aluno a[N])
{
    for (int i=0; i<N; i++)
    {
        printf("\naluno %d - nome:\t", i);
        fflush(stdin);
        gets(a[i].nome);
        system("cls");

        printf("\naluno %d - matricula:\t", i);
        fflush(stdin);
        gets(a[i].matricula);
        system("cls");

        printf("\naluno %d - endereco:\t", i);
        printf("\naluno %d - rua:\t", i);
        fflush(stdin);
        gets(a[i].en.rua);
        printf("aluno %d - cidade:\t", i);
        fflush(stdin);
        gets(a[i].en.cidade);
        system("cls");

        for(int j=0; j<X; j++)
        {
            printf("\naluno %d - nota %d:\t", i,j);
            fflush(stdin);
            scanf("%f", &a[i].notas[j]);
            system("cls");
        }
    }
}

char maior_media (aluno a[N])
{
    float media[N], soma, maior;
    char nome[50];
    int contador;

    for (int i=0; i<N; i++)
    {
        soma=0.0;
        for (int j=0; j<X; j++)
        {
            soma=soma+a[i].notas[j];
        }
        media[i]=soma/N;
    }

    maior=media[0];
    for(int i=0 ; i<N;i++)
    {
        if(media[i]<maior)
        {
            maior=media[i];
            contador=i;
        }
    }
    strcpy(nome,a[contador].nome);

    return nome;
}

void status (aluno a[N])
{
    float soma, media[N];
    for (int i=0; i<N; i++)
    {
        soma=0.0;
        for (int j=0; j<X; j++)
        {
            soma=soma+a[i].notas[j];
        }
        media[i]=soma/N;
        if(media[i]>=6.0) printf("\n\tAprovado! :D");
        else printf("\n\tReprovado! :(");
    }
}


int main()
{
    aluno a[N];

    leitura(a);
    printf("\nO aluno de maior media eh: ");
    puts(maior_media(a));
    status(a);




    printf("\n\n");
    system("pause");
    return 0;
}
