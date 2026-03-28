#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define X 1 // nota
#define N 2 // aluno

typedef struct escola
{
    int matricula;
    float nota1, nota2, media;
    char nome[30];

};

void leitura(escola prog[N])
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("Digite seu nome:\n");
        gets(prog[i].nome);
        printf("Digite seu numero de matricula:\n");
        scanf("%d", &prog[i].matricula);
        printf("Digite sua primeira nota:\n");
        scanf("%f", &prog[i].nota1);
        printf("Digite sua segunda nota:\n");
        scanf("%f", &prog[i].nota2);
        prog[i].media=((prog[i].nota1)+(prog[i].nota2))/2;
        system("pause");
        system("cls");
    }
}

void mostra(escola prog[N])
{
    int i;
    for(i=0;i<N;i++)
    {
        if(prog[i].media>=60)
        {
            printf("ALUNO APROVADO!\n");
            printf("Nome: %s\n", prog[i].nome);
            printf("Nota: %f", prog[i].media);
        }
        else
        {
            printf("ALUNO REPROVADO!\n");
            printf("Nome: %s\n", prog[i].nome);
            printf("Nota: %f", prog[i].media);
        }

    }
}
int main()
{
    escola prog[N];
    leitura(escola prog[N]);
    mostra(escola prog[N]);
    return 0;

}


