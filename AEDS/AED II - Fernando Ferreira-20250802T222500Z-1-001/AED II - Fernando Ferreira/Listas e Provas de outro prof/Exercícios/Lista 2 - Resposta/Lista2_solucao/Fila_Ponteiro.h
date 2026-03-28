#ifndef FILA_PONTEIRO_H_INCLUDED
#define FILA_PONTEIRO_H_INCLUDED
//=================================================================================================
// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
//=================================================================================================
typedef struct Cliente
{
    char nome[100];
    int idade;
};
typedef Cliente TipoItem;
//=================================================================================================
// Define o tipo Celula para armazenar os itens da Fila
typedef struct TipoCelula
{
    TipoItem Item;
    TipoCelula *Prox;
};

// Define o tipo Fila
typedef struct TipoFila
{
    TipoCelula *Frente, *Tras;
    int Tamanho;
};
//=================================================================================================

// Procedimentos para manipular os dados na fila

// Procedimento que inicializa a fila
void FFVazia(TipoFila *Fila)
{
    Fila->Frente = (TipoCelula*) malloc(sizeof(TipoCelula));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox = NULL;
    Fila->Tamanho = 0;
}

// Procedimento que verifica se a fila está vazia
bool Vazia(TipoFila *Fila)
{
    return (Fila->Frente == Fila->Tras);
}

// Procedimento que insere um novo elemento no topo da fila
void Enfileira(TipoFila *Fila, TipoItem item)
{

    TipoCelula *temp = (TipoCelula*)malloc(sizeof(TipoCelula));

    if(temp==NULL)
    {
        printf("Memoria insuficiente!!!");
        exit(0);
    }

    Fila->Tras->Prox = temp;
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->Item = item;
    Fila->Tras->Prox = NULL;
    Fila->Tamanho++;
}

// Procedimento que remove um elemento do topo da fila
TipoItem Desenfileira(TipoFila *Fila)
{

    if(Vazia(Fila))
    {
        printf("Erro: Fila Vazia!\n");
    }
    else
    {

        TipoCelula *temp = Fila->Frente;
        Fila->Frente = Fila->Frente->Prox;
        free(temp);

        Fila->Tamanho--;
        return Fila->Frente->Item;
    }
}

// Procedimento que retorna o tamanho da fila
int Tamanho(TipoFila *Fila)
{
    return Fila->Tamanho;
}

// Procedimento que imprimi os dados da fila
void Imprimi(TipoFila *Fila)
{

    printf("Tamanho da Fila: %d\n",Tamanho(Fila));

    TipoCelula *temp = Fila->Frente->Prox;

    while(temp!=NULL)
    {
        printf("%i - %s\n",temp->Item.idade,temp->Item.nome);
        temp = temp->Prox;
    }
}

void EnfileiraComPrioridade(TipoFila *Fila, TipoItem item)
{

    TipoCelula *temp = (TipoCelula*)malloc(sizeof(TipoCelula));

    if(temp==NULL)
    {
        printf("Memoria insuficiente!!!");
        exit(0);
    }

    Fila->Tras->Prox = temp;
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->Item = item;
    Fila->Tras->Prox = NULL;
    Fila->Tamanho++;

    if(item.idade >= 65)
    {

        TipoItem aux1 = item, aux2;

        for(TipoCelula *i = Fila->Frente->Prox; i != NULL; i = i->Prox)

            if(i->Item.idade < 65 || i == Fila->Tras)
            {
                aux2 = i->Item;
                i->Item = aux1;
                aux1 = aux2;
            }
    }
}
//=================================================================================================
#endif // FILA_PONTEIRO_H_INCLUDED
