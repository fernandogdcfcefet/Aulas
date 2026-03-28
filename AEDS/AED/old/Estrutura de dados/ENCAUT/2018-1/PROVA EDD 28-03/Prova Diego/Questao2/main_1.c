#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define N 10 // Alunos
#define X 3 // Nota

typedef struct{
    char Rua[100];
    char Cidade[100];
}Endereco;

typedef struct{
    int Matricula;
    char Nome[100];
    Endereco end;
    float Notas[X];
}Aluno;

void Leitura(Aluno *a){
    int i, j;

    for(i=0;i<N;i++){
        printf("Digite a matricula do aluno: ");
        scanf("%d",&a[i].Matricula);
        printf("Digite o nome do aluno: ");
        fflush(stdin);
        gets(a[i].Nome);
        printf("Digite o nome da rua: ");
        fflush(stdin);
        gets(a[i].end.Rua);
        printf("Digite o nome da cidade: ");
        fflush(stdin);
        gets(a[i].end.Cidade);
        for(j=0;j<X;j++){
            printf("Digite a nota %d do aluno: ",j+1);
            scanf("%f",&a[i].Notas[j]);
        }

    }
}

void MaiorMediaGeral(Aluno a[], float media[]){
    float soma, maiormedia;
    char AlunoMaior[100];
    int i, j;

    for(i=0;i<N;i++){
        soma = 0;
        for(j=0;j<X;j++){
           soma = soma + a[i].Notas[j];
        }
        media[i] = soma/X;
        if(i==0){
            maiormedia = media[i];
        }
        if(media[i] > maiormedia){
            maiormedia = media[i];
            strcpy(AlunoMaior,a[i].Nome);
        }
    }
}

void Aprovacao(Aluno a[], float media[]){
    int i;

    for(i=0;i<N;i++){
        if(media[i] >= 6){
            printf("Aprovado!!");
        }
        else{
            printf("Reprovado!!");
        }
    }
}

void Imprimir(Aluno a[]){
    int i,j;

    for(j=0;j<N;j++){
        printf("Nome: ");
        puts(a[j].Nome);
        printf("Matricula: %d\n",a[j].Matricula);
        printf("Rua: ");
        puts(a[j].end.Rua);
        printf("Cidade: ");
        puts(a[j].end.Cidade);
        for(i=0;i<X;i++){
            printf("Nota: %f\n", a[j].Notas[i]);
        }
    }
}

int main()
{
    Aluno a1[N];
    float media[N];
    int i;


    Leitura(&a1);
    //Imprimir(a1);
    MaiorMediaGeral(&a1,&media);
    Aprovacao(&a1,&media);


    return 0;
}
