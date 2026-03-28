#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 2
#include "ex2.h"

int main(){
    aluno a[N];
    for(int i =0; i<N; i++){
        printf("digite a matricula do %d aluno \n",i+1);
        scanf("%d",&a[i].matricula);
        printf("digite o primeiro nome do %d aluno \n",i+1);
        scanf("%s",a[i].nome);
        getchar();
        for(int j =0; j<X; j++){
             printf("digite a %d nota do aluno %d \n",j+1,i+1);
             scanf("%d",&a[i].notas[j]);
        }
    }
    int soma ;
    for(int i =0; i<N; i++){
        soma =0;
         for(int j =0; j<X; j++){
            soma = soma + a[i].notas[j];
         }
         if((soma/X)>=60){
            printf("o aluno : %s foi aprovado \n",a[i].nome);
         }
         else
             printf("o aluno : %s foi reprovado \n",a[i].nome);
    }

}