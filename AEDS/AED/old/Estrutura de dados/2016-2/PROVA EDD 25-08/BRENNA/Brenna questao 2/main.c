#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 2
#define x 2

typedef struct {
  int matricula;
  char nome[40];
  int notas[4];



}aluno;

void ler( aluno eu[N]){
    int media;
    int i,j;

       for(i=0;i<N;i++){
        fflush(stdin);
        printf("digite seu nome: \n");
        gets(eu[i].nome);
        fflush(stdin);
        printf("insira sua matricula");
        scanf("%d",&eu[i].matricula);
        fflush(stdin);
        for(j=0;j<x;j++){
           printf("digite suas notas");
           scanf("%d",&eu[i].notas[j]);
           fflush(stdin);

           }

        }

}

void imprime(aluno eu[N]){
       int i;
       int cont;
       int j;
      for(i=0;i<N;i++){
        printf("O  nome: %s  possui a matricula : %d \n ",eu[i].nome,eu[i].matricula);

        for(j=0;j<x;j++){
                printf("suas notas foram %d \t  \n",eu[i].notas[j]);

        }


      }

}

int main()
{
    int i;
    aluno eu[N];
    ler(eu);
    imprime(eu);
    return 0;

}
