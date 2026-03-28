#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 3

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
    Pilha->Topo =0;
}

int Vazia(TipoPilha Pilha){
    return(Pilha.Topo == 0);
}

void Empilha(TipoItem x, TipoPilha *Pilha){
    if(Pilha->Topo == MAXTAM){
        printf("Erro: Pilha esta cheia\n");
    }
    else{
        Pilha->Topo++;
        Pilha->Item[Pilha->Topo-1] = x;
    }
}

void Desempilha(TipoItem *Item, TipoPilha *Pilha){
    if(Vazia(*Pilha)){
        printf("Erro: Pilha esta vazia\n");
    }
    else{
        *Item = Pilha->Item[Pilha->Topo-1];
        Pilha->Topo--;
    }
}

int Tamanho(TipoPilha Pilha){
    return(Pilha.Topo);
}

void Imprime(TipoPilha Pilha){
    int i=0;
    for(i=0;i<Tamanho(Pilha);i++)
        printf("%d \n", Pilha.Item[i].Chave);
}


int main(){
    TipoPilha Pilha1, Pilha2, Pilha3;
    TipoItem Item1, Item2, Item3;
    Item1.Chave = 1;
    Item2.Chave = 2;
    Item3.Chave = 3;
    FPVazia(&Pilha1);
    FPVazia(&Pilha2);
    FPVazia(&Pilha3);
    Empilha(Item3, &Pilha1);
    Empilha(Item2, &Pilha1);
    Empilha(Item1, &Pilha1);
    printf("PILHA 1 \n");
    Imprime(Pilha1);
    Desempilha(&Item1, &Pilha1);
    Item1.Chave = 1;
    Empilha(Item1, &Pilha3);
    printf("PILHA 3 \n");
    Imprime(Pilha3);
    Desempilha(&Item2, &Pilha1);
    Item2.Chave = 2;
    Empilha(Item2, &Pilha2);
    printf("PILHA 2 \n");
    Imprime(Pilha2);
    Desempilha(&Item1, &Pilha3);
    Item1.Chave = 1;
    Empilha(Item1, &Pilha2);
    printf("PILHA 2 \n");
    Imprime(Pilha2);
    Desempilha(&Item3, &Pilha1);
    Item3.Chave = 3;
    Empilha(Item3, &Pilha3);
    printf("PILHA 3 \n");
    Imprime(Pilha3);
    Desempilha(&Item1, &Pilha2);
    Item1.Chave = 1;
    Empilha(Item1, &Pilha1);
    printf("PILHA 1 \n");
    Imprime(Pilha1);
    Desempilha(&Item2, &Pilha2);
    Item2.Chave = 2;
    Empilha(Item2, &Pilha3);
    printf("PILHA 3 \n");
    Imprime(Pilha3);
    Desempilha(&Item1, &Pilha1);
    Item1.Chave = 1;
    Empilha(Item1, &Pilha3);
    printf("PILHA 3 \n");
    Imprime(Pilha3);
}
