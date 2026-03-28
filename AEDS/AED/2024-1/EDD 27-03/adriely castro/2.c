#include <stdio.h>
#include <stdlib.h>
#include "2.h"

#define X 3
#define N 5

void lerAlunos(aluno a[N]){
    for(int i = 0; i < N; i++){
        printf("matricula: ");
        scanf("%d",&a[i].matricula);
        fflush(stdin);
        printf("Nome:");
        scanf("%s",a[i].nome);
        fflush(stdin);
        printf("Notas: ");
        for(int i = 0; i < X; i++){
            scanf("%d",&a[i].nota[i]);
        }
    }
}


int main(){
    aluno a[N];
    lerAlunos(a);
    int soma = 0;

    for(int j = 0; j < N; j++){
        for(int i = 0; i < X; i++){
            soma = a[i].nota[i] + soma;
            if(i == 2){
                if(a[j].nota[i] >= 60){
                    printf("%s passou!!",a[j].nome);
                    soma = 0;
                }
            }
        }
    }


    return 0;
}