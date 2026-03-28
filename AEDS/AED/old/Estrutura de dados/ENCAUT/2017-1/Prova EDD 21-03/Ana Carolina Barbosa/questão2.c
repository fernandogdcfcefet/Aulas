#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define N 2
#define X 2
 typedef struct{
     char matricula[10],nome[20];
     int notas[X];
 }aluno;

 void cadastro(aluno a[N]){
     int i,j;
     for (i=0;i<N;i++){
        printf("Informe o nome do aluno: ");
        scanf("%s",&a[i].nome);
        printf("informe a matricula de %s: ", a[i].nome);
        scanf("%s", &a[i].matricula);
        for(j=0;j<X;j++){
            printf("informe a nota %d: ",j+1);
            scanf("%d",&a[i].notas[j]);
        }
       system("cls");
     }

 }
 void aprovados(aluno a[N]){
    float media[N];
    int i,j,soma[N]={0};
        for(i=0;i<N;i++){
            for(j=0;j<X;j++){
                soma[i]=soma[i]+a[i].notas[j];
            }
        media[i]=soma[i]/X;
        }
        for (i=0;i<N;i++){
            if(media[i]>=60){
                printf("o aluno %s foi aprovado. \n", a[i].nome);
            }
        }
 }
 char mmedia(aluno a[N]){
  char aluno [20],auxn[20], auxm[20];
  float media[N],aux ;
  int i,j,soma[N]={0};
        for(i=0;i<N;i++){
            for(j=0;j<X;j++){
                soma[i]=soma[i]+a[i].notas[j];
            }
        media[i]=soma[i]/X;
        }
        for(i=0;i<N;i++){
            for(j=0;j<N-1;j++){
                if (media[j]<media[j+1]){
                    aux= media[j];
                    media[j]=media[j+1];
                    media[j+1]=aux;

                    strcpy( auxn, a[j].nome);
                    strcpy(a[j].nome, a[j+1].nome);
                    strcpy(a[j+1].nome,auxn);

                    strcpy( auxm, a[j].matricula);
                    strcpy(a[j].matricula, a[j+1].matricula);
                    strcpy(a[j+1].matricula,auxn);

                }

            }
        }

strcpy(aluno,a[0].nome);
return aluno;
 }

int main(){
  aluno a[N];
  cadastro(a);
  aprovados(a);

  printf("\n %s e o aluno com a maior media. \n",mmedia(a));

return 0;
}
