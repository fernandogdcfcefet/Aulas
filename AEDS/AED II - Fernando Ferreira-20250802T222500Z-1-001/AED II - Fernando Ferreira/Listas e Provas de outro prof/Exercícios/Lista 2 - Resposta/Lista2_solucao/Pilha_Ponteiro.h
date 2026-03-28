#ifndef PILHA_PONTEIRO_H_INCLUDED
#define PILHA_PONTEIRO_H_INCLUDED
//=================================================================================================
// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
//=================================================================================================
typedef char TipoItem;
//=================================================================================================
// Define o tipo Celula para armazenar os itens da Pilha
typedef struct TipoCelula
{
    TipoItem Item;
    TipoCelula *Prox;
};

// Define o tipo Pilha
typedef struct TipoPilha
{
    TipoCelula *Fundo, *Topo;
    int Tamanho;
};
//=================================================================================================

// Procedimentos para manipular os dados na pilha

// Procedimento que inicializa a pilha
void FPVazia(TipoPilha *Pilha)
{
    Pilha->Topo = (TipoCelula*) malloc(sizeof(TipoCelula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
}

// Procedimento que verifica se a pilha está vazia
bool Vazia(TipoPilha *Pilha)
{
    return (Pilha->Topo == Pilha->Fundo);
}

// Procedimento que insere um novo elemento no topo da pilha
void Empilha(TipoPilha *Pilha, TipoItem item)
{

    TipoCelula *temp = (TipoCelula*)malloc(sizeof(TipoCelula));

    if(temp==NULL)
    {
        printf("Memoria insuficiente!!!");
        exit(0);
    }

    Pilha->Topo->Item = item;
    temp->Prox = Pilha->Topo;
    Pilha->Topo = temp;
    Pilha->Tamanho++;
}

// Procedimento que remove um elemento do topo da pilha
TipoItem Desempilha(TipoPilha *Pilha)
{

    if(Vazia(Pilha))
    {
        printf("Erro: Pilha Vazia!\n");
        return -1;
    }
    else
    {

        TipoCelula *temp = Pilha->Topo;
        Pilha->Topo = Pilha->Topo->Prox;
        free(temp);

        TipoItem Item = Pilha->Topo->Item;
        Pilha->Tamanho--;
        return Item;
    }
}

// Procedimento que retorna o tamanho da pilha
int Tamanho(TipoPilha *Pilha)
{
    return Pilha->Tamanho;
}

// Procedimento que imprimi os dados da pilha
void Imprimi(TipoPilha *Pilha)
{

    printf("Tamanho da Pilha: %d\n",Tamanho(Pilha));

    TipoCelula *temp = Pilha->Topo->Prox;

    while(temp!=NULL)
    {
        printf("%c\n", temp->Item);
        temp = temp->Prox;
    }
}

TipoPilha* clone(TipoPilha *Pilha)
{

    TipoPilha *p1 = (TipoPilha*)malloc(sizeof(TipoPilha));
    TipoPilha *p2 = (TipoPilha*)malloc(sizeof(TipoPilha));

    FPVazia(p1);
    FPVazia(p2);

    while(!Vazia(Pilha))
        Empilha(p1,Desempilha(Pilha));

    while(!Vazia(p1))
    {
        TipoItem item = Desempilha(p1);
        Empilha(Pilha,item);
        Empilha(p2,item);
    }

    return p2;
}

TipoPilha* concatena(TipoPilha *Pilha1, TipoPilha *Pilha2)
{

    TipoPilha *p1 = (TipoPilha*)malloc(sizeof(TipoPilha));

    p1->Fundo = Pilha1->Fundo;
    p1->Topo = Pilha2->Topo;
    p1->Tamanho = Pilha1->Tamanho + Pilha2->Tamanho;

    TipoCelula *aux = Pilha1->Topo;

    Pilha1->Topo = Pilha1->Topo->Prox;
    Pilha2->Fundo->Prox = Pilha1->Topo;

    FPVazia(Pilha1);
    FPVazia(Pilha2);

    free(aux);

    return p1;
}

bool verifica(char *expressao, int n)
{

    TipoPilha *p = (TipoPilha*)malloc(sizeof(TipoPilha));
    FPVazia(p);

    for(int i=0; i<n; i++)
    {
        if(expressao[i]=='(')
            Empilha(p,expressao[i]);

        if(expressao[i]==')')
            if(Vazia(p))
            {
                free(p);
                return false;
            }
            else
                Desempilha(p);
    }

    if(Vazia(p))
    {
        free(p);
        return true;
    }
    else
    {
        free(p);
        false;
    }
}

//=================================================================================================
#endif // PILHA_PONTEIRO_H_INCLUDED
