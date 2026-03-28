#include "stdlib.h"
#include "stdio.h"
#define N 2
#define X 2

typedef struct dados_alunos{
    int matricula;
    char nome[50];
    int notas[N];
}alunos;

void cadastro_aluno(){
    alunos aluno[N];
    for(int i=0;i<N;i++){
    printf("informe o numero de matricula do aluno[%d]: ",i+1);
    scanf("%d",&aluno[i].matricula);
    printf("informe o nome do aluno[%d]: ",i+1);
    scanf("%s",aluno[i].nome);
        for(int j=0;j<X;j++){
            printf("informe a nota [%d] do aluno[%d]: ",j+1,i+1);
            scanf("%d",&aluno[i].notas[j]);
        }
    }
    int soma;
    int media;
    for(int k=0;k<N;k++){
        soma=0;
        media=0;
        for(int l=0;l<N;l++){
            soma = soma + (aluno[k].notas[l]);
        }
        media = soma/X;
        if(media>=60){
            printf("%s - Aprovado!\n",aluno[k].nome);
        }
        if(media<60){
            printf("%s - Reprovado!\n",aluno[k].nome);
        printf("\n");
    }
}
}
int main(){
    cadastro_aluno();
}
