#include <stdio.h>
#include <stdlib.h>

#define N 2
#define X 2

typedef struct{
    char nome[200];
    int matricula;
    float notas[X];
}Alunos;

float media(Alunos A){
    int i=0;
    float som=0;
    for(i=0;i<X;i++){
        som=som+A.notas[i];
    }
    return som/X;
}

int Aprov(Alunos A){

    if(media(A)>=60){
        return 1;
    }
    else return 0;
}

void Aprovados(Alunos A[]){
    int i,j=0;
    for(i=0;i<N;i++){
        if(Aprov(A[i])==1){
            if(j==0){
                printf("\n----APROVADOS----\n");
                j++;
            }
            puts(A[i].nome);
            printf("\n");
        }
    }
}

void LerDados(Alunos Al[]){
    int i,j;
    for(i=0;i<N;i++){
        printf("\n-------ALUNO %d-------\n", i+1);
        printf("Digite o nome do Aluno: ", i+1);
        gets(Al[i].nome);
        fflush(stdin);
        printf("Digite o numero da matricula: ", i+1);
        scanf("%d", &Al[i].matricula);
        for(j=0;j<X;j++){
            printf("Nota %d: ",j+1);
            scanf("%f",&Al[i].notas[j]);
            fflush(stdin);
        }
        printf("\n-----------------------\n\n");
    }
}

Alunos MaiorM(Alunos A[]){
    int i,M=0;
    for(i=0;i<N;i++){
        if(media(A[M])<media(A[i])){
            M=i;
        }
    }
    return A[M];
}

int main()
{
    Alunos A[N],AlunoMaiorMedia;
    LerDados(A);
    Aprovados(A);
    AlunoMaiorMedia=MaiorM(A);
    printf("\n\nAluno com maior media foi: %s\n",AlunoMaiorMedia.nome);
    printf("matricula: %d\n\n",AlunoMaiorMedia.matricula);

    return 0;
}
