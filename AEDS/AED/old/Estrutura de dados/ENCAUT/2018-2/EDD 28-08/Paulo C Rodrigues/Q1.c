#include <stdlib.h>
#include <stdio.h>
#define N 2

typedef struct{
  int dia, mes, ano;
}data;

typedef struct{
  char descricao[60];
  data dt;
}compromisso;

void titulo(){
  printf("\t\t-- AGENDA --\n\n");
}

void agenda(){
  int i;
  compromisso c[N];
  char p;

  titulo();

  for(i=0; i<N; i++){
    printf("Insira um compromisso: ");
    scanf("%s", &c[i].descricao);
    printf("Insira o dia: ");
    scanf("%d", &c[i].dt.dia);
    printf("Insira o mes: ");
    scanf("%d", &c[i].dt.mes);
    printf("Insira o ano: ");
    scanf("%d", &c[i].dt.ano);

    system("cls");
    titulo();
  }

  system("cls");
  titulo();


  /*for(i=0; i<N; i++){
    printf("Compromisso: %s\nData: %d/%d/%d\n\n", c[i].descricao, c[i].dt.dia, c[i].dt.mes, c[i].dt.ano);
  }*/
}

int main(){

  agenda();

  return 0;
}
