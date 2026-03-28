#include<stdio.h>
#include<stdlib.h>
#define x 3
#define n 3

typedef struct{

    char matricula[20];
    char nome[100];
    float notas[x];

}aluno;

void cadastraraluno(aluno vetaluno[n]){

int i;

for(i=0;i<n;i++){

    printf("Digite a matricula do aluno %d : " , i+1);
    gets(vetaluno[i].matricula);
    fflush(stdin);

    printf("Digite o nome do aluno %d : " , i+1);
    gets(vetaluno[i].nome);
    fflush(stdin);

    printf("Digite as notas do aluno %d : " , i+1);
    gets(vetaluno[i].notas);
    fflush(stdin);

}

}

void compararaluno(aluno vetaluno[n]){

    int media;




}

int main(){

    aluno vetaluno[n];
    cadastraraluno(vetaluno[n]);
    compararaluno(vetaluno[n]);


}
