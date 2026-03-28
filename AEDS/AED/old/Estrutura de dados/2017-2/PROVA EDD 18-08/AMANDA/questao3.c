#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define N 5 //N é o número de livros

typedef struct{
 char nome[50];
 int idade;
 char cpf[15];

}autor;
typedef struct{
 char titulo[30];
 autor aut;
 int ano;
}livro;
void leitura(livro l[N])
{
  int i,j;
  for(i=0;i<N;i++)
    {
     printf("********LIVRO %d*********\n",i+1);
     puts("Titulo:\n");
     fflush(stdin);
     gets(l[i].titulo);
     puts("Nome do autor:\n");
     fflush(stdin);
     gets(l[i].aut.nome);
     printf("Idade do autor:\n");
     //fflush(stdin);
     scanf("%d",&l[i].aut.idade);
     puts("cpd do autor:\n");
     fflush(stdin);
     gets(l[i].aut.cpf);
     printf("Ano:\n");
     //fflush(stdin);
     scanf("%d",&l[i].titulo);
     system("cls");
   }
}
 char retorne(livro l[N])
 {
     int i,j;

     for(i=0;i<N;i++){
        for(j=0;j<N;j++){

            if(strcmp(l[i].titulo,l[j].titulo)==0){
                 leitura(l);
                return l[i].titulo;
            } else printf(" Nao existe esse livro no programa\n");
        }
     }
 }
return 0;
}
int main(){
livro l[N];
char d;
leitura(l);
d=retorne(l);

return 0;
}
