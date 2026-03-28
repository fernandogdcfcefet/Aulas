#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define TAM_A 2
#define TAM_N 2

typedef struct{
    int matricula;
    char nome[30];
    float nota;
}aluno;

int verifica(aluno aal){
    int media=0, i, j;
    int j;

    for(j=0; j<TAM_N; j++){
        media = media + aal[j].nota;

    }

    for(i=0;i<TAM_A;i++){
        for(j=0;j<TAM_N;j++){
            media = media + aal[i].nota;

        }
    }

}


int main(){
    aluno a[TAM_A];
    int i, j;
    float media=0;

    for(i=0;i<TAM_A;i++){
        printf("Matricula: ");
        scanf("%d", &a[i].matricula);
        fflush(stdin);

        printf("Nome: ");
        scanf("%s", &a[i].nome);
        fflush(stdin);

        for(j=0; j<TAM_N; j++){
            printf("NOTA %i:", j+1);
            scanf("%f", &a[j].nota);
            fflush(stdin);
        }
        system("cls");
    }

    verifica(a[TAM_A]);

    /*for(i=0;i<TAM_A;i++){
        //for(j=0;j<TAM_N;j++){
            printf("\nMEDIA %s\n", a[i].nome);
            media = media + a[i].nota;
            printf("\t%f", media);

        //}
        printf("\t%f", media);
    }*/



    system("pause");
    return 0;
}

