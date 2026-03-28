#include <stdio.h>
#include <stdlib.h>
#define N 2
#define X 2

typedef struct{
    int matricula;
    char nome[50];
    int notas[X];
} aluno;

void calculaMedias(aluno alunos[N]){
    int soma;
    float media;
    printf("Calculando medias...\n");

    for(int i = 0; i < N; i++){
        soma = 0;
        for(int j  = 0; j < X; j++){
            soma = alunos[i].notas[j] + soma;
        }

        media = soma/X;
        if(media >= 60){
            printf("Aluno %d aprovado:\n", i+1);
            printf("Nome: %s\n", alunos[i].nome);
        }
        else{
            printf("Aluno %d reprovado:\n", i+1);
            printf("Nome: %s\n", alunos[i].nome);
        }
    }
}

int main()
{
    aluno alunos[N];

    printf("Cadastramento:\n");
    for(int i = 0; i < N; i++){
        printf("Aluno %d:\n", i+1);
        printf("Digite a matricula do aluno: ");
        scanf("%d", &alunos[i].matricula);

        printf("Digite o nome do aluno: ");
        scanf("%s", alunos[i].nome);

        printf("Digite as notas do aluno:\n");
        for(int j = 0; j < X; j++){
            printf("Nota %d: ", j+1);
            scanf("%d", &alunos[i].notas[j]);
        }
    }

    printf("Cadastramento concluido.\n\n");
    calculaMedias(alunos);
    return 0;
}
