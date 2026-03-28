#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 2
#define X 2
typedef struct
{
  int matricula;
  char nome[50];
  float notas[X];
} aluno;
void ap(aluno a[N])
{
  int i, j;
  float aux=0;
  for(i=0; i< N; i++)
  {
    for(j=0; j<X; j++)
    {
      aux+=a[i].notas[j];
    }
    aux=aux/X;
    if(aux>=60)
    {
      printf("\tO aluno %s esta aprovado.\n", a[i].nome);
    }
    aux=0;
  }

}
char maiormedia(aluno a[N])
{
  int i, j;
  float aux[N];
  for(i=0; i< N; i++)
  {
    for(j=0; j<X; j++)
    {
      aux[i]+=a[i].notas[j];
    }
    aux[i]=aux[i]/X;
  }
  float aux1=aux[0];
  for(i=0; i<N; i++)
  {
    if(aux1<aux[i])
    {
      j=i;
    }
  }
  return a[j].nome;
}
int main()
{
        aluno a[N];
    char media;
    a[0].notas[0]=50;
    a[0].notas[1]=70;
    a[1].notas[0]=80;
    a[1].notas[1]=60;
    strcpy(a[0].nome, "Breno");
    strcpy(a[1].nome, "Renan");
    ap(a);
    return 0;
}
