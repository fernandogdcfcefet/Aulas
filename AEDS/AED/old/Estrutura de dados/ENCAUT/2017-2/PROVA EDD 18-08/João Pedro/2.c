#include <stdio.h>
#include <stdlib.h>

#define QN 3
#define QA 2

typedef struct{
    int matricula;
    char nome[100];
    float notas[QN];
}Aluno;

void cadastraAlunos(Aluno aluno[]){
    int i, j;
    printf("\n\n\tCADASTRE OS ALUNOS\n\n");
    for(i=0; i<QA; i++){
        printf("Matricula aluno %: ", i+1);
        scanf("%d", &aluno[i].matricula);
         fflush(stdin);
        printf("Nome aluno %: ", i+1);
        gets(aluno[i].nome);
        for(j=0; j<QN; j++){
            printf("Nota %d: ", j+1);
            scanf("%f", &aluno[i].notas[j]);
        }
        printf("\n");
    }
}

void nomeAprovador(Aluno aluno[]){
    int i,j;
    float media;
    printf("\n\n\tALUNOS APROVADOS\n\n");
    for(i=0; i<QA; i++){
        for(j=0; j<QN; j++)
            media = media + aluno[i].notas[j];
        media = media / QN;
        if(media >= 60)
            puts(aluno[i].nome);
        printf("\n");
        media = 0;
    }
}

int maiorMedia(Aluno aluno[]){
    int i,j, retorno;
    float media[QA];
    for(i=0; i<QA; i++){
        for(j=0; j<QN; j++)
            media[i] = media[i] + aluno[i].notas[j];
        media[i] = media[i] / QN;
    }
    for(i=1; i<QA; i++){
            if(media[i]>media[i-1])
                retorno = i;
    }
    return retorno;
}

int main()
{
    int posicao;
    Aluno aluno[QA];
    cadastraAlunos(aluno);
    nomeAprovador(aluno);
    posicao = maiorMedia(aluno);
    printf("Aluno com maior media: ");
    puts(aluno[posicao].nome);
    printf("\n");
    return 0;
}
