#include <stdio.h>
#include <stdlib.h>
#define N 1
#define X 2

typedef struct{
    int matricula;
    char nome[30];
    int notas[X];
}aluno;

void medianota(aluno alunos[]){
    int i, j, soma[N], media=0,aux =0, y = X, tudo = 0;
    for(aux=0;aux<N;aux++)
        soma[aux]=0;
    for(j=0;j<N;j++){
        for(i=0;i<X;i++){
            soma[i] = alunos[j].notas[i];
        }
        for(aux=0;aux<X;aux++){
        tudo += soma[aux];
        }
        media = (tudo/X);
        if(media>60){
            printf("\nPassou o aluno ");
            puts(alunos[j].nome);
        }
    }
}
int main(){

    aluno alunos[N];
    int i = 0, x = 0, j=0;
    for(i=0;i<N;i++){
        printf("\nMATRICULA\n");
        scanf("%d", &alunos[i].matricula);
        printf("\nNOME\n");
        fflush(stdin);
        gets(alunos[i].nome);
        for(j=0;j<X;j++){
            printf("\nNOTA\n");
            scanf("%d", &alunos[i].notas[j]);
        }
    }
    medianota(alunos);


}
