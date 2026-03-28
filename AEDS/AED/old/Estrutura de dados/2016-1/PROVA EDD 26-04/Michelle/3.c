#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define MAXTAM 1000

typedef int TipoApontador;
typedef int TipoChave;

typedef struct{
    TipoChave Chave;
}TipoItem;


typedef struct{
    TipoItem Item[MAXTAM];
    TipoApontador Topo;
}TipoPilha;

void FPVazia(TipoPilha *Pilha){
    Pilha->Topo = 0;
}

int Vazia(TipoPilha Pilha){
    return (Pilha.Topo == 0);
}

void Empilha(TipoItem x, TipoPilha *Pilha){
    if(Pilha->Topo == MAXTAM)
       printf("Erro: pilha esta cheia\n");
    else{
        Pilha->Topo++;
        Pilha->Item[Pilha->Topo - 1] = x;
    }
}

void ImprimePilha(TipoPilha Pilha){
    int i = 0;

   for(i=Pilha.Topo-1; i>=0; i--){
        printf("%d ", Pilha.Item[i].Chave);
    }
}


void Desempilha(TipoPilha *Pilha, TipoItem *Item){
    if(Vazia(*Pilha))
    printf("Erro: pilha esta vazia\n");

    else{
        *Item = Pilha->Item[Pilha->Topo-1];
        Pilha->Topo--;
    }
}

/*void ImprimePilha(TipoPilha Pilha){
    int i;

    while (Tamanho(Pilha) > 0){
        printf("%d ", Pilha.Topo.Item.Chave);
    }
}
*/
int Tamanho(TipoPilha Pilha){
    return (Pilha.Topo);
}

int main(){
    TipoPilha p1, p2, p3;
    TipoItem p, m, g;

    p.Chave = 1;
    m.Chave = 2;
    g.Chave = 3;

    FPVazia(&p1);
    FPVazia(&p2);
    FPVazia(&p3);

    //Inicio
    Empilha(g, &p1);
    Empilha(m, &p1);
    Empilha(p, &p1);

    printf("\nPilha 1:\n");
    ImprimePilha(p1);
    printf("\nPilha 2:\n");
    ImprimePilha(p2);
    printf("\nPilha 3:\n");
    ImprimePilha(p3);

    //Movimento 1
    Desempilha(&p1, &p);
    Empilha(p, &p3);

    printf("\nPilha 1:\n");
    ImprimePilha(p1);
    printf("\nPilha 2:\n");
    ImprimePilha(p2);
    printf("\nPilha 3:\n");
    ImprimePilha(p3);

    //Movimento 2
    Desempilha(&p1, &m);
    Empilha(m, &p2);

    printf("\nPilha 1:\n");
    ImprimePilha(p1);
    printf("\nPilha 2:\n");
    ImprimePilha(p2);
    printf("\nPilha 3:\n");
    ImprimePilha(p3);

    //Movimento 3
    Desempilha(&p3, &p);
    Empilha(p, &p2);

    printf("\nPilha 1:\n");
    ImprimePilha(p1);
    printf("\nPilha 2:\n");
    ImprimePilha(p2);
    printf("\nPilha 3:\n");
    ImprimePilha(p3);

    //Movimento 4
    Desempilha(&p1, &g);
    Empilha(g, &p3);

    printf("Pilha 1:\n");
    ImprimePilha(p1);
    printf("\nPilha 2:\n");
    ImprimePilha(p2);
    printf("\nPilha 3:\n");
    ImprimePilha(p3);

    //Movimento 5
    Desempilha(&p2, &p);
    Empilha(p, &p1);

    printf("Pilha 1:\n");
    ImprimePilha(p1);
    printf("\nPilha 2:\n");
    ImprimePilha(p2);
    printf("\nPilha 3:\n");
    ImprimePilha(p3);

    //Movimento 6
    Desempilha(&p2, &m);
    Empilha(m, &p3);

    printf("Pilha 1:\n");
    ImprimePilha(p1);
    printf("\nPilha 2:\n");
    ImprimePilha(p2);
    printf("\nPilha 3:\n");
    ImprimePilha(p3);

    //Movimento 7
    Desempilha(&p1, &p);
    Empilha(p, &p3);

    printf("Pilha 1:\n");
    ImprimePilha(p1);
    printf("\nPilha 2:\n");
    ImprimePilha(p2);
    printf("\nPilha 3:\n");
    ImprimePilha(p3);



    getch();
    return 0;
}
