#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define N 2
#define X 3
typedef struct{
 char matricula[50];
 char nome[100];
 float notas[X];

}Aluno;
void leitura(Aluno a[N]){
int i,j;
 for(i=0;i<N;i++)
 {
  printf("******ALUNO %d*******\n\n",i+1);
  puts("Matricula: \n");
  fflush(stdin);
  gets(a[i].matricula);
  puts("Nome:\n");
  fflush(stdin);
  gets(a[i].nome);
   for(j=0;j<X;j++)
   {
     printf("Notas:  \n");
     scanf("%f",&a[i].notas[j]);
   }
   system("cls");
 }
}
void aprovados(Aluno a[N]){
  int i,j;
  float soma[N]={0};
  float media[N];
  for(i=0;i<N;i++)
  {
    for(j=0;j<X;j++)
    {
      soma[i]+=a[i].notas[j];
      media[i]=soma[i]/X;
      if(media[i]>=60)
      {
        printf("OS ALUNOS APRONADOS\n");
        printf("Nome: %s\n",a[i].nome);
     }
   }

 }
}
char maiorMedia(Aluno a[N]){
 int i,j;
 float soma[N]={0};
 float media[N];
 float maior[N]={0};

  for(i=0;i<N;i++)
  {
    for(j=0;j<X;j++)
    {
      soma[i]+=a[i].notas[j];
      media[i]=soma[i]/X;
      if(maior[i]<media[i]){
         maior[i]=media[i];
         return a[i].nome;
      }
   }

 }

}
int main(){
Aluno a[N];
leitura(a);
aprovados(a);
printf("Nome de maior media:%s\n",maiorMedia(a));
return 0;
}
