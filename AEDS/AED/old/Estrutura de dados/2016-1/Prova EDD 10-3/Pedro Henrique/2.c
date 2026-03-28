#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define N 3
#define X 2


typedef struct aluno{
       int matricula;
       char nome[100];
       float nota[X];

}aluno;

int main()
{
    aluno al[N];
    float total[N], media[N];
    int i, j;
    for(i=0;i<N;i++){

        printf("informe a matricula do aluno %d: ", i);
        scanf("%d", &al[i].matricula);
        printf("informe o nome: ");
        fflush(stdin);

        gets(al[i].nome);


        for(j=0;j<X;j++){
            printf("informe a nota da prova %d: ", j);
            scanf("%f", &al[i].nota[j]);
            total[i] = total[i] + al[i].nota[j];
        }

        media[i] = total[i]/X;

        if(media>=60){
            printf("O aluno %s foi aprovado\n", al[i].nome);
        }


    }


}
