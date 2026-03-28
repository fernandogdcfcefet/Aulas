#include <stdio.h>
#include <stdlib.h>
#define N 2
#define X 2

typedef struct
{
    char rua[50];
    char cidade[50];
}Endereco;

typedef struct
{
    int val;

}Nota;

typedef struct
{
    char matricula[50];
    char nome[50];
    Endereco End;
    Nota notas[X];
}Aluno;

void CadastrarAluno (Aluno a[])
{
    int i,j;
    for (i=0;i<N;i++)
    {

        printf("\nDigite a matricula do aluno %d: ", i+1);
        scanf("%s", a[i].matricula );

        printf("\nDigite o nome do aluno %d: ", i+1);
        scanf("%s", a[i].nome );

        printf("\nDigite a rua do aluno %d: ", i+1);
        scanf("%s", a[i].End.rua );

        printf("\nDigite a cidade do aluno %d: ", i+1);
        scanf("%s", a[i].End.cidade );

        for (j=0;j<X;j++)
        {
            printf("\nDigite a nota do aluno %d: ", i+1);
            scanf("%d", &a[i].notas[j].val );
        }
    }
}

int Media (Aluno a)
{
    int i, med=0;
    for(i=0;i<X; i++)
    {
        med+= a.notas[i].val;
    }
    return (med/X);
}

Aluno MaiorMedia (Aluno a[])
{
    int i,medi=0;
    Aluno maior= a[0];
    for (i=0;i<N;i++)
    {
        if (Media(maior) < Media(a[i]))
        {
            maior= a[i];
        }
    }
    return maior;
}

void AprovReprov (Aluno a[])
{
    int i;
    for (i=0;i<N;i++)
    {
        if( Media(a[i])>= 6)
        {
            printf("\nO Aluno %s foi Aprovado.", a[i].nome);
        }else
        {
            printf("\nO Aluno %s foi Reprovado", a[i].nome);
        }
    }
}

int main()
{
    Aluno a[N], b;

    CadastrarAluno(a);

    b=MaiorMedia(a);

    printf("Maior Media: %s", b.nome);

    AprovReprov(a);

    return 0;
}
