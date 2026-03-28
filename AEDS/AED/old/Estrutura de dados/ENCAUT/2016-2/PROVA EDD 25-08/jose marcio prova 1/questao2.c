#include<stdio.h>
#include<stdlib.h>
#define n 2
#define x 2

typedef struct{

int matricula;
char nome[50];
float notas[x];

}aluno;

void leraluno(aluno vetaluno[n]){

int i,j;
for(i=0;i<n;i++){

    printf("Digite a matricula do aluno %d: \n" , i+1);
    fflush(stdin);
    scanf("%d" , &vetaluno[i].matricula);

    printf("Digite o nome do aluno %d: \n" , i+1);
    fflush(stdin);
    scanf("%s" , &vetaluno[i].nome);

    for(j=0;j<x;j++){

        printf("Digite a nota %d do aluno %d: \n" , j+1 , i+1);
        scanf("%f" , &vetaluno[i].notas[j]);

    }

}
}

void imprimealuno(aluno vetaluno[n]){

int i,j;

for(i=0;i<n;i++){

    printf("A matricula do aluno %d eh: %d \n\n" , i+1 , vetaluno[i].matricula);
    printf("O nome do aluno %d eh: %s \n\n" , i+1 , vetaluno[i].nome);

    for(j=0;j<x;j++){

        printf("A nota %d do aluno %d eh: %f \n\n" , j+1 , i+1 , vetaluno[i].notas[j]);
    }

}
}

void aprovado(aluno vetaluno[n]){

int i,j,notafinal;

for(i=0;i<n;i++){
        for(j=0;j<x;j++){

            scanf("%f" , vetaluno[i].notas[j]);
            notafinal = vetaluno[i].notas[j];
        }

notafinal = notafinal/x;
}

if(notafinal > 60){

    printf("APROVADO...");

}
else {
    printf("NAO APROVADO...");
}

}

int main(){

aluno vetaluno[n];

leraluno(vetaluno);

printf("-------------\n\n");

imprimealuno(vetaluno);

printf("-------------\n\n");

aprovado(vetaluno);

return 0;
}
