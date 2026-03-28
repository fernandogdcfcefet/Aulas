#include <stdio.h>
#include <stdlib.h>
#define N 3
#define X 3

typedef struct{
    char matricula[50];
    char nome[50];
    float notas[X];
}Aluno;

float media(float vet[X]){
    int i = 0;
    float soma = 0.0;
    for (i = 0; i < X; i++)
        soma+=vet[i];
    return soma/X;
}

void aprovados(Aluno al){
    int i;
    for(i = 0; i < N; i++)
        if (media(al[i].notas)>=60)
            puts(al[i].nome);
}
char maiormedia(Aluno a){
    float mmedia = 0.0;
    int i = 0;
    char[50] mnome;
    for(i=0;i<N;i++){
        if(media(a[i].notas)>mmedia){
            mmedia = media(a[i].notas);
            mnome = a[i].nome;
        }
    }
    return mnome;
}


int main()
{
    Aluno a[N];
    int i = 0,j = 0;
    for(i = 0; i<N; i++){
        printf("Informe o matricula do %o aluno ", i+1);
        gets(a[i].matricula);
        fflush(stdin);
        printf("Informe o nome do %o aluno ", i+1);
        gets(a[i].nome);
        printf("Informe o nome do %do aluno", i+1);
        gets(a[i].nome);
        fflush(stdin);
        system("cls");
        for(j = 0; j < X; j++){
        printf("Informe a nota % do aluno", j+1);
        scanf("%f", &a[i].notas[j]);
        }
    }
    puts(maiormedia(a));


    return 0;
}
