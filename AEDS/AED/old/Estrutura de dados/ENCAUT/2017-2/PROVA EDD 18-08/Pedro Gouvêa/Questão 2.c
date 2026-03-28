#include <stdlib.h>
#include <stdio.h>
#define N 2
#define X 2

typedef struct {
  int matricula;
  char nome[50];
  float notas[X];
}Aluno;

void aprovados(Aluno a) {
  int i;
  for(i = 0; i < 2; i++) {
    if(a[i].)
  }

}

int main() {
  Aluno a[N];
  int i, j;
  float media[N], soma[N];

  for(i = 0; i < N; i++) {
    printf("Informe o nome do aluno %d: ", i + 1);
    fflush(stdin);
    gets(a[i].nome);
    fflush(stdin);

    printf("Informe a matricula do aluno %d: ", i + 1);
    scanf("%d", &a[i].matricula);

    for(j = 0; j < X; j++) {
      printf("Informe a nota da prova %d: ", j + 1);
      scanf("%f", &a[i].notas[j]);
    }
  }

  for(i = 0; i < N; i++)
    for(j = 0; j < X; j++)
      soma[i] += a[i].notas[j];

  for(i = 0; i < N; i++)
    for(j = 0; j < X; j++)
      media[i] = soma[i]/X;

  return 0;
}
