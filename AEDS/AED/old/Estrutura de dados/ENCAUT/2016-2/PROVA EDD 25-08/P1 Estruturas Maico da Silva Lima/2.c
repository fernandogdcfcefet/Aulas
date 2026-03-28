#include<stdio.h>
#include<stdlib.h>
#define N 2
#define X 3
typedef struct{
    int matricula;
    char nome[50];
    float notas[X];
}aluno;

void Leitura(aluno a1[N]){ ///procedimento para fazer a leitura dos dados
    int i, j;
    for(i=0;i<N;i++){
        puts("digite matricula: ");
        scanf("%d",&a1[i].matricula);
        fflush(stdin);
        puts("digite nome: ");
        scanf("%s",&a1[i].nome);
        fflush(stdin);
        for(j=0;j<X;j++){
            printf("Digite nota %d : ",j+1);
            scanf("%f",&a1[i].notas[j]);
        }
   }
}
void media(aluno a1[N]){/// calcula a media dos alunos e imprime quais foram aprovados e quais foram reprovados
    int i, j;
    float  soma, media;
    for(i=0;i<N;i++){
        soma=0;
        for(j=0;j<X;j++){
            soma=soma+a1[i].notas[j];
        }
        if((soma/X)>=60)
            printf("\n%s Aprovado\n",a1[i].nome);
        else
            printf("\n%s Reprovado\n", a1[i].nome);


   }
}



int main(){
    aluno a1[N];
    Leitura(a1);
    media(a1);



return 0;
}
