#include <stdio.h>
#include <string.h>
#define N 3
#define X 3

typedef struct{
    int matricula;
    char nome[40];
    float notas[X];
}aluno;

void aprovados(aluno alunos[]){
    float soma=0.0;
    for(int i=0;i<N;i++){
        for(int j=0;j<X;j++)
            soma = soma + alunos[i].notas[j];
        if(soma/X >= 60)
            printf("\nO aluno %s foi aprovado.", alunos[i].nome);
        soma=0;
    }
}

aluno maiorMedia(aluno alunos[]){
    float soma=0.0, maiorNota=0;
    aluno maior;
    for(int i=0;i<N;i++){
        for(int j=0;j<X;j++)
            soma = soma + alunos[i].notas[j];
        if(soma/X >= maiorNota){
            maior = alunos[i];
            maiorNota = soma/X;
        }
        soma=0;
    }
    return maior;
}

int main(){
    aluno alunos[N];
    for(int i=0;i<N;i++){
        printf("\n - Digite o nome do aluno %d: ", i+1);
        fflush(stdin);
        gets(alunos[i].nome);

        printf("\n - Digite a matricula do aluno %d: ", i+1);
        scanf("%d", &alunos[i].matricula);
        printf("\n");
        for(int j=0;j<X;j++){
            printf(" - Digite a nota %d do aluno %d: ", j+1,i+1);
            scanf("%f", &alunos[i].notas[j]);
        }
        printf("\n ----------------------------------");
    }
    aprovados(alunos);
    printf("\n\n - A maior media foi do aluno %s\n", maiorMedia(alunos).nome);
    return 0;
}
