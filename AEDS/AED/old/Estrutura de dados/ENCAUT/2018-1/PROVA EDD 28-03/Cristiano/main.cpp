// Cristhiano Augusto Magno
// Primeira avaliação da disciplina de Estrutura de dados
// Professor Samuel

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 4
#define X 2

int Q1(int A[7][7])
{
    int i, j, aux;

    printf("\tDigite os elementos da matriz\n");
    for(i=1;i<7;i++)
    {
        printf("Linha %d\n", i);
        for(j=1;j<7;j++)
        {
            printf("Coluna %d\n", j);
            scanf("%d", &A[i][j]);
            if(i == 1, j == 1)
            {
                aux= A[1][1];
            }
            if(i+j == 7)
            {
                if(A[i][j]<aux)
                {
                    aux= A[i][j];
                }
            }
        }
    }
    return(aux);
}

typedef struct
{
    char nome[20];
    char ender[30];
    int matr;
    float notas[X];

} Aluno;

void preencher_dados()
{
    int i;

    printf("\tInsira os dados dos %d alunos\n", N);
    for(i=1;i==N;i++)
    {
        printf("Nome do aluno\n");
        gets("%s", &a1.nome);
    }
}

int main()
{
    int A[7][7];
    Aluno;
    return 0;
}
