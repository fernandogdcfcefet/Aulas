#include <stdio.h>
#include <stdlib.h>
#define N 1
#define X 2
typedef struct {
    int mat,notas[X]; //mat representa matrícula
    char nome[];
} aluno;
int main()
{
    int i,j;
    float soma=0,media=0;
    aluno turma[N];
    printf("Digite as informações dos alunos\n");
    for(i=0; i<N; i++){
        gets(turma[i].nome);
        scanf("%d", &turma[i].mat);
        for(j=0;j<X;j++){
            scanf("%d", &turma[i].notas[j]);
            soma = soma + turma[i].notas[j];
        }
        media = soma/X;
        if (media >= 60){
            printf("%s\n", &turma[i].nome);
            printf("foi aprovado");
        }
    }

    return 0;
}


