#include <stdio.h>
#include <stdlib.h>
#define N 3
#define X 3

typedef struct{
   char rua[100];
   char cidade[20];
}Endereco;

typedef struct{
  char matricula[40];
  char nome[100];
  Endereco end;
  float notas[X];
}Aluno;

Aluno dados(Aluno al[N]){
  int i,j;

  for(i=0;i<N;i++){
    printf("Digite o nome do aluno: \n");
    gets(al[i].nome);
    printf("Digite a matricula do aluno: \n");
    gets(al[i].matricula);
    printf("Digite a rua do aluno: \n");
    gets(al[i].end.rua);
    printf("Digite a cidade do aluno: \n");
    gets(al[i].end.cidade);
       for (j=0;j<X;j++){
        printf("Digite a nota do aluno: \n");
        scanf("%d",&al[i].notas[j]);
       }

  }
  return al[N];
}

Aluno maiormedia(Aluno est[N]){
  int i, j;
  float n=0,media[N];

  for(i=0;i<N;i++){
    for(j=0;j<X;j++){
        n=n+est[i].notas[j];
    }
    media[i]=(n/X);
  }
  maior=media[0];
  for(i=0;i<N;i++){
    if (media[i]>maior){
        maior=media[i];
    }
  }
}



int main()
{
   Aluno dadosalunos[N];
   dados(dadosalunos);
   maiormedia

}
