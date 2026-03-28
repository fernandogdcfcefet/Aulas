#include <stdio.h>
#include <stdlib.h>
#include "Questao2.h"

int main(){

    aluno turma[N];
    int i,j, soma=0;;


    for(i=0; i<N;i++){
        printf("Nome: ");
        scanf("%s", &turma[i].nome);
        printf("Matricula: ");
        scanf("%d", &turma[i].matricula);
        for(j=0; j<X; j++){
        printf("Digite a nota %d: ", j+1);
        scanf("%d", &turma[j].notas);
        soma = soma + turma[j].notas;
        }
        if(soma/X >=60){
            printf("Aluno aprovado %s\n", turma[i].nome);
        }
    } 
    

    return 0;
}