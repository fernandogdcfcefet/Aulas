#include <stdio.h>
#include<stdlib.h>
#include <conio.h>

#define N 3
#define X 3
typedef struct{
    int matricula;
    char nome [100];
    int notas[X];
}Aluno;

void Media(Aluno a[]){
    int i, j, soma=0;
    float media;
    float Media[N];

    for(i=0; i<N; i++){
        for(j=0; j<X; j++){
            soma+=a[i].notas[j];
        }
        media=soma/X;
        Media[i]= media;
        if(media>=60){
            printf("\n%s APROVADO", a[i].nome);
        }
        soma=0; media=0;
    }
}

int MaiorMedia(Aluno a[]){
    int i, j, soma=0, aux=0;
    float media;
    float Media[N];
    float maior=Media[0];

    for(i=0; i<N; i++){
        for(j=0; j<X; j++){
            soma+=a[i].notas[j];
        }
        media=soma/X;
        Media[i]= media;
        media=0; soma=0;
    }

    for(i=0; i<N; i++){
        if(maior<Media[i]){
            maior=Media[i];
            aux=i;
        }
    }
    return aux;
}

int main(){
    Aluno alunos[N];
    int i, j, aux;

    for(i=0; i<N; i++){
       printf("\nAluno %d", i+1);

       printf("\nNome: ");
       fflush(stdin);
       gets(alunos[i].nome);
       fflush(stdin);

       printf("\nMatricula: ");
       scanf("%d", &alunos[i].matricula);

       for(j=0; j<X; j++){
        printf("\n Nota %d: ", j+1);
        scanf("%d", &alunos[i].notas[j]);
       }

       system("cls");

    }

    Media(alunos);
    aux=MaiorMedia(alunos);
    printf("\nO aluno com maior media foi: %s", alunos[aux].nome);


    system("PAUSE");
    return 0;
}
