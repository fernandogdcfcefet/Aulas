#include<stdio.h>

int main (){
int matricula;
char nome [30];
float nota1,nota2;
int i ;
float media ;




 for ( i = 0; i < 2; i++){


     printf("Informe o seu nome: " );
    scanf ("%s", &nome);


     printf("Informe o numero  da sua matricula: " );
    scanf ("%d", &matricula);


    printf("Informe o valor da primeira nota: " );
    scanf ("%f", &nota1);

     printf("Informe o valor da segunda nota: " );
    scanf ("%f", &nota2);


   media = (nota1+nota2)/2;

    if (media>=60){

        printf(" O aluno foi aprovado ");

    }

    else {
        printf(" O aluno foi reprovado ");

    }



 }

}
