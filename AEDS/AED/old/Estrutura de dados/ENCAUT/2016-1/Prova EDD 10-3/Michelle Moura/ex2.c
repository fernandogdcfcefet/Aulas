#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define N 3
#define X 3

typedef struct{
    int matricula;
    char nome[100];
    float nota[X];

}aluno;

void leitura(aluno a[N]){
    int i, j;
    float soma[N] = {0}, media[N];

    for(i=0;i<N;i++){
        printf("Aluno %d\n\n", i+1);
        printf("Informe seu nome: ");
        fflush(stdin);
        gets(a[i].nome);
        printf("Informe sua matricula: ");
        scanf("%d", &a[i].matricula);
        for(j=0;j<X;j++){
            printf("Informe a %d nota: ", j+1);
            scanf("%f", &a[i].nota[j]);
           // soma[i] = soma[i] + a[i].nota[j];
        }
        //media[i] = soma[i]/X;
        system("cls");
    }
}

void calculaMedia(aluno a[N]){
    int i, j;
    float soma[N] = {0}, media[N];

    for(i=0;i<N;i++){
        for(j=0;j<X;j++){
            soma[i] = soma[i] + a[i].nota[j];
        }
        media[i] = soma[i]/X;
        if(media[i]>=60)
        {
                printf("O aluno %s foi aprovado com media %.2f\n", a[i].nome, media[i]);
        }

    }
}


int main(){
    aluno a[N];

    leitura(a);
    calculaMedia(a);

    getch();
    return 0;
}
