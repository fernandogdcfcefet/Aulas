#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#define X 2
#define N 2

typedef struct{
    char rua[20];
    char cidade[20];
}endereco;

typedef struct{
    int matricula;
    char nome[20];
    endereco end;
    float notas[X];
}alunos;

void cadastrar(alunos aluno[]){
int i;
    for( i=0;i<N;i++){
            system("cls");
        printf("Matricula: \n");
        scanf("%d",& aluno[i].matricula);

        printf("Nome: \n");
        fflush(stdin);
        gets(aluno[i].nome);
        fflush(stdin);

        printf("Rua: \n");
        fflush(stdin);
        gets(aluno[i].end.rua);
        fflush(stdin);

        printf("Cidade: \n");
        fflush(stdin);
        gets(aluno[i].end.cidade);
        fflush(stdin);

        for(int j=0;j<X;j++){
            printf("Nota %d: ",j+1);
            scanf("%f",&aluno[i].notas[j]);
        }
    }

}

float media(int notas[]){
    int soma =0;
    for(int i=0;i<X;i++){
        soma += notas[i];
    }
    float media = soma/X;
    return media;
}
void aprovados(alunos aluno[]){
    float med=0;
    for(int i=0;i<N;i++){
            med = media(aluno[i].notas);
            if(med>=6)
                printf("%s Aprovado \n",aluno[i].nome);
            else
                printf("%s Reprovado; \n", aluno[i].nome);



}

void alunoMaiormedia(alunos aluno[]){
    char A [20];
    float m[N]={0};
    float maiorM =0;

    for(int i=0;i<N;i++){
        m[i]=media(aluno[i].notas);
    }

    for(int i =0;i<N;i++){
        if(m[i]>maiorM){
            maiorM = m[i];
            strcpy(A,aluno[i].nome);
        }
    }
    printf("%s e o aluno com maior nota; \n",A);
}


int main(){
    alunos aluno[N];
    cadastrar(aluno);
    aprovados(aluno);
    alunoMaiormedia(aluno);

return 0;
}
