#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define n 5
#define x 10

typedef struct{

    int matricula;
    char nome[10];
    float nota[5];


}aluno;

void preenche(aluno a[n]){

    int i,j;

    for(i=0; i<n; i++){
        for(j=0; j<x; j++){
            printf("Matricula: ");
            scanf("%d", &a[i].matricula);

            printf("Nome: ");
            gets(a[i].nome);

            printf("Notas: ");
            scanf("%f", &a[i].nota[j]);

        }
    }

}

void aprovado(aluno a[n]){


    int i,j;
    float media=0;

    printf("Alunos aprovados: \n");

    for(i=0; i<n; i++){
        for(j=0; j<x; j++){

            media = media + a[i].nota[j];

            if(media >= 60){

                puts(a[i].nome);
            }
        }
    }
}

char maiorMedia (aluno a[n]){

     int i,j, flag=0;
     float maior=0, media=0;
     char m[10];

     for(i=0; i<n; i++){
        for(j=0; j<x; j++){

            media = media + a[i].nota[j];
            media = media / x;

            while(flag==0){

                maior = media;
                flag = 1;
            }

            if(media > maior){

                maior = media;
                strcpy(m,a[i].nome);

            }
        }
     }
    return m;

}



int main()
{
    aluno a[x];

    preenche(a);
    aprovado(a);
    maiorMedia(a);


    return 0;
}
