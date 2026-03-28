# include <stdio.h>


 typedef struct {

    char nome[30];
    int matricula;
    int nota1;
    int nota2;

 }aval;

 #define QUANT_ALUNOS 2


int main(){
  aval alunos[QUANT_ALUNOS];

  printf ("Campos: nome matricula notas\n");
int i;
    for ( i=0;i<QUANT_ALUNOS; ++i){
    printf ("informe os dados dos aluno:");
    scanf("%s %i %i %i", alunos[i].nome,&alunos[i].matricula,&alunos[i].nota1,&alunos[i].nota2);



   }




}
















