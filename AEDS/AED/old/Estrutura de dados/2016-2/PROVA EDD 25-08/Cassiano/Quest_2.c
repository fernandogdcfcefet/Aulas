#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define N 2
#define X 3

typedef struct{
    char matricula[12];
    char nome[10];
    float nota[X];

}Aluno;

void leitura(Aluno a[N]){
    int i, j;

   for(i=0; i<N; i++){
       system("cls");
        printf("Informe os dados do aluno %d:\n\n", i+1);
        printf("Nome: ");
        scanf("%s", &a[i].nome);
        fflush(stdin);
        printf("Matricula: ");
        scanf("%s", &a[i].matricula);
        fflush(stdin);
        printf("\nInforme as notas do aluno %d\n", i+1);
        for(j=0; j<X; j++){
            fflush(stdin);
            printf("\tNota %d: ", j+1);
            scanf("%f", &a[i].nota[j]);
        }

   }

}

void calMedia(Aluno a[N]){
    system("cls");
    int i,j;
    float media[N]={0};

    printf("Alunos aprovados:\n\n");
    for(i=0; i<N; i++){
        for(j=0; j<X; j++){
            media[i]+=a[i].nota[j];

            if(media[i]>=60){
            printf("\t%s APROVADO\n", a[i].nome);

            }
        }
    }
}

int main(){
    Aluno a[N];
    leitura(a);
    calMedia(a);


system("pause");
return 0;
}
