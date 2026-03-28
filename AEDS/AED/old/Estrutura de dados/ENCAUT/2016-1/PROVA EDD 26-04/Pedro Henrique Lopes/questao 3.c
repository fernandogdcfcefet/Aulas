#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#define MAXTAM 1000
typedef int TipoApontador;
typedef int TipoChave;
typedef struct{
    TipoChave Chave;
    TipoApontador Prox;
} TipoItem;

typedef struct{
    TipoItem Item[Maxtam];
    TipoApontador Topo;
} TipoPilha;







int main()
{
    TipoPilha p1,p2,p3;
    TipoItem 1,2,3;

    FPVazia(&p1);
    FPVazia(&p2);
    FPVazia(&p3);

    Empilha(1,&p1);
    Empilha(2,&p1);
    Empilha(3,&p1);

    Desempilha(3,&p1);
    Empilha(3,&p3);

    Desempilha(2,&p1);
    Empilha(2,&p2);

    Desempilha(3,&p3);
    Empilha(3,&p2);

    Desempilha(1,&p1);
    Empilha(1,&p3);

    Desempilha(3,&p2);
    Empilha(3,&p1);

    Desempilha(2,&p2);
    Empilha(2,&p3);

    Desempilha(3,&p1);
    Empilha(3,&p3);

    return 0;
}

