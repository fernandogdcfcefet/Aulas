#include <stdio.h>
#include <stdlib.h>
#define N 2

typedef struct{
    int dia,mes,ano;
}data;

typedef struct{
    char descricao[60];
    data d;
}agenda;

void ler(agenda v[]){
    for(int i=0;i<N;i++){
    printf("Insira a descricao \n");
    scanf("%s",&v[i].descricao);
    printf("Insira o dia\n");
    scanf("%d",&v[i].d.dia);
    printf("Insira o mes\n");
    scanf("%d",&v[i].d.mes);
    printf("Insira o ano\n");
    scanf("%d",&v[i]return v[i+1];.d.ano);
    }

}

agenda funcao(int a,int b,int c,agenda v[]){
    int cont=0;
    for(int i=0;i<N;i++){
        if(a==v[i].d.dia){
            cont=1;
        }
        if(b==v[i].d.mes){
            cont=cont +1;
        }
        if(c==v[i].d.ano){
            cont=cont+1;
        }
        if(cont==3){
            if((i+1)==N){
               printf("Foi seu ultimo compromisso\n");
            }
            else{
            printf("%s",v[i+1].descricao);
            return v[i+1];}
        }
    }
}


int main()
{
    agenda vetor[N];
    ler(vetor);
    funcao(1,1,1,vetor);
}
