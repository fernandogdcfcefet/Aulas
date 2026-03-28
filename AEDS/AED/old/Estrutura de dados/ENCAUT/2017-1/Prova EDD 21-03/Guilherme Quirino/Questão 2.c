#include<stdio.h>
#include<string.h>
#define X 3
#define N 3

typedef struct
{
    char nome[100], matricula[10];
    int nota[X];
}aluno;

void aprovados(aluno *aluno){
    int j, soma = 0, cont = 0 ;
    float media;
    for(j=0;j<X;j++){
        soma = soma + aluno->nota[j];
        cont = cont + 1;
    }
    media = soma/X;
    if(media>=60){
        printf("%s foi aprovado com %.1f\n",aluno->nome, media);
    }
}

int main(){
    aluno aluno[N];
    int i, j;
    for(i=0;i<N;i++){
        printf("Nome:\n");
        scanf("%s",&aluno[i].nome);
        printf("Matricula;\n");
        scanf("%s",&aluno[i].matricula);
        for(j=0;j<X;j++){
            printf("Nota da prova %d:\n",j+1);
            scanf("%i",&aluno[i].nota[j]);
            }
    }
    system("cls");
    for(i=0;i<N;i++){
    aprovados(&aluno[i]);
        printf("");
    }

return 0;
}
