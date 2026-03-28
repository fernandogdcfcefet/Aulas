#include <stdio.h>
#include <stdlib.h>

#define N 1

typedef struct {
    int dia;
    int mes;
    int ano;
}date;

typedef struct {
    char desc[60];
    date data;
}agenda;


void leVetor(agenda a[]) {
  int i;
  for(i=0; i<N; i++) {
    printf("Insira a desc do compromisso %d\n", i+1);
    fflush(stdin);
    gets(a[i].desc);
    fflush(stdin);
    printf("Insira o dia do compromisso %d\n", i+1);
    scanf("%d", &a[i].data.dia);
    printf("Insira o mes do compromisso %d\n", i+1);
    scanf("%d", &a[i].data.mes);
    printf("Insira o ano do compromisso %d\n", i+1);
    scanf("%d", &a[i].data.ano);
  }
}

void imprimeVetor(agenda a[N]) {
int i;
  for(i=0; i<N; i++) {

    puts(a->desc);
    printf("dia: %d", a[i].data.dia);
    printf(", mes: %d", a[i].data.mes);
    printf(", ano: %d\n\n", a[i].data.ano);
  }
}

void proxCompromisso(date d, agenda a[N]) {
int i;
for(i=0; i<N; i++) {
    if(a[i].data.ano > d.ano) {
        if(a[i].data.mes > d.mes) {
            if(a[i].data.dia > d.dia) {
                 printf("proximo compromisso e:\n");
                 puts(a[i].desc);
            }
        }
    }
}
}




int main()
{
    //Letra a
    agenda compromissos[N];

    leVetor(compromissos);
    imprimeVetor(compromissos);


    // Letra b
    date dataprox;
    dataprox.ano=18;
    dataprox.mes=9;
    dataprox.dia=7;
    //verificar se a data é anterior a 7/9/18

    proxCompromisso(dataprox, compromissos);



    return 0;
}
