#include <stdio.h>
#include <stdlib.h>
#define N 2
#define X 2

//Faltou Letra a).
typedef struct {
    int matricula;
    char nome[90];
    char endereco[20];
    float notas[X];
} Alunos;

float maiorMedia(Alunos a[]){
   int i, j;
   float max, sum[X] = {0}, med[N] = {0};

  for(i = 0; i < N; i++){
    for(j = 0; j < X; j++){
        sum[i] += a[i].notas[j];
    }
    med[i] = sum[i]/X;
  }
  max = med[0];
  for(i = 0; i < N; i++){
    if(max < med[i]){
        max = med[i];
    }
  }
   return max;
}

void resultado(Alunos a[]){
    float sum[X] = {0};
  for(int i = 0; i < N; i++){
        for(int j = 0; j < X; j++){
            sum[i] += a[i].notas[j];
        }
    if((sum[i]/X) > 6){
        printf("O aluno a%d foi aprovado media", i, sum[i]/X);
    }
  }
}
int main()
{
    Alunos a[N];
    return 0;
}
