#include<stdio.h>
#include<conio.h>
#define TAM 3
  typedef struct
   {
   char rua[100];


   }endereco;




  typedef struct
  {
   char nome[100];
   int telefone[100];
   endereco end;

  }pessoa;


  int main()
  {
    pessoa d[TAM];
    int i,j;
    for(i=0;i<TAM;i++)
    {
    printf("NOME:");
    scanf("%s",&d[i].nome);
    printf("rua:");
    scanf("%s",&d[i].end.rua);
    printf("telefone:");
    scanf("%s",&d[i].telefone);
    }

   for(i=0;i<TAM;i++)
    {
    printf("pessoas nq moram na mesma rua %s\n",d[i].nome);
    for(j=0;j<TAM;j++)
        {
           if((strcmp(d[i].end.rua,d[j].end.rua)==0) &&(!(strcmp(d[i].nome,d[j].nome))==0))
           {
            printf("%s\n",d[j].nome);
           }


        }

    }









  return 0;

  }




















