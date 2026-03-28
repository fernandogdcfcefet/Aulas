#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define T1 10
#define N1 3 // N
#define N2 2 //X


typedef struct
{
    int mat;
    char nome[T1];
    float nota[N2],soma=0;
}aluno;

void ap(aluno a[N1])
{
    int i=0,j=0;

    for(i=0;i<N1;i++)
    {
         if((a[i].soma/2)>=60) printf("\n%s\n",a[i].nome);
       

    }
}


int main()
{
    aluno a[N1];

   int i=0,j=0;

    for(i=0;i<N1;i++)
    {
        printf("Informe o nome");
        scanf("%s",&a[i].nome);
        printf("Informe a matricula");
        scanf("%d",&a[i].mat);

        for(j=0;j<N2;j++)
        {
            printf("Informe a nota %d\n",j+1);
            scanf("%f",&a[i].nota[j]);
           a[i].soma+=a[i].nota[j];
        }
    }
    
    ap(a);




}





