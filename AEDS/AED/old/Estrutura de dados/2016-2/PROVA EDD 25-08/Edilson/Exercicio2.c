#include <stdio.h>
#include <stdlib.h>
#define N 3 //numero de notas
#define X 3 //numero de alunos

typedef struct {
    int matricula;
    char nome[100];
    float notas[N];
}estudante;

int main(){
    estudante alunos[X];
    int i, j;
    float media;
    for (i=0; i<X; i++){
        printf("Matricula do %do Aluno: ", i+1);
        scanf("%d", &alunos[i].matricula);
        fflush(stdin);
        printf("Nome do Aluno: ");
        gets(alunos[i].nome);
        fflush(stdin);
        for (j=0; j<N; j++){
            printf("%da Nota: ", j+1);
            fflush(stdin);
            scanf("%f", &alunos[i].notas[j]);
        }
        printf("Aluno: %s\n", alunos[i].nome);
        printf("Matricula: %d\n\n", alunos[i].matricula);
    }
    printf("Alunos Aprovados: \n");
    for (i=0; i<X; i++){
        media = 0;
        for (j=0; j<N; j++){
            media += alunos[i].notas[j];
        }
        media = media/N;
        if (media>=60){
            fflush(stdin);
            printf("%s \n", alunos[i].nome);
        }
    }
    return 0;
}
