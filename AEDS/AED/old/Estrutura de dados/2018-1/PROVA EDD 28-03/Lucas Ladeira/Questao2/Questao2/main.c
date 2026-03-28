#include <stdio.h>
#include <stdlib.h>


typedef struct{
    char rua[50];
    char cidade[50];



}endereco;
typedef struct{
    endereco end;
    int matricula, nota;
    char nome[50];



}Aluno;

void Leitura(Aluno A){
    int i, n;

    for(i=0; i<3; i++){
        printf("\nMatricula: ");
        scanf("%d",&A[i].matricula);
        printf("\nNota: ");
        scanf("%d",&A[i].nota);
        printf("\nNome: ");
        gets(A[i].nome);
        printf("\nRua: ");
        gets(A[i].end.rua);
        printf("\nCidade: ");
        gets(A[i].end.cidade);


    }

}
float MaiorMedia (Aluno ){
    Aluno A;
    int i;
    float compara;
    char NomeMaior[50];
    for(i=0; i<n; i++){
        if(i==0){
            compara=A[i].nota;
            strcpy(NomeMaior, A[i].nome);
        }
        if(compara>A[i].nota){
           strcpy(NomeMaior, A[i].nome);
        }
    }
    return NomeMaior;
}

void Aprovacao(Aluno ){
    Aluno A;
    int i;
    for(i=0; i<n; i++){
        if(A[i].nota>=6){
            printf("Aprovado!\n");

        }
        else{
            printf("Reprovado!\n");
        }
    }

}


int main()
{
    Aluno A
    Leitura(Aluno A);
    return 0;
}
