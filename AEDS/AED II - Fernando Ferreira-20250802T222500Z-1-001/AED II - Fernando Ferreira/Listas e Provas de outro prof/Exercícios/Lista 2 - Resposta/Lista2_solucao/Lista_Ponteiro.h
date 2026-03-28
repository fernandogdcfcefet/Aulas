#ifndef LISTA_PONTEIRO_H_INCLUDED
#define LISTA_PONTEIRO_H_INCLUDED
//=================================================================================================
// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
//=================================================================================================
// Define o tipo Celula para armazenar os itens da Lista
typedef struct TipoCelula {
int Item;
TipoCelula *Prox;
};

// Define o tipo Lista
typedef struct TipoLista{
TipoCelula *Primeiro, *Ultimo;
int Tamanho;
};
//=================================================================================================

// Procedimentos para manipular os dados na lista

// Procedimento que inicializa a lista
void FLVazia(TipoLista *Lista){
    Lista->Primeiro = (TipoCelula*) malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
    Lista->Tamanho = 0;
}

// Procedimento que verifica se a lista está vazia
bool Vazia(TipoLista *Lista){
    return (Lista->Primeiro == Lista->Ultimo);
}

// Procedimento que insere um novo elemento na lista
void Insere(TipoLista *Lista, int item){

    Lista->Ultimo->Prox = (TipoCelula*)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = item;
    Lista->Ultimo->Prox = NULL;
    Lista->Tamanho++;
}

// Procedimento que retorna o tamanho da lista
int Tamanho(TipoLista *Lista){
    return Lista->Tamanho;
}

// Procedimento que remove um elemento da lista
int Remove(TipoLista *Lista, int p){

    if(Vazia(Lista) || p > Tamanho(Lista)){
        printf("Erro: Lista Vazia ou Posicao Inexistente!\n");
        return -1;
    }else{

        TipoCelula *temp = Lista->Primeiro;

        for(int i=1; i<p; i++)
            temp = temp->Prox;

        TipoCelula *temp_item = temp->Prox;

        temp->Prox = temp_item->Prox;

        int item  = temp_item->Item;
        free(temp_item);
        Lista->Tamanho--;
        return item;
    }
}

// Procedimento que imprimi os dados da lista
void Imprimi(TipoLista *Lista){

    printf("Tamanho da Lista: %d\n",Tamanho(Lista));

    TipoCelula *temp = Lista->Primeiro->Prox;

    while(temp!=NULL){
        printf("%d\n", temp->Item);
        temp = temp->Prox;
    }
}
//=================================================================================================
#endif // LISTA_PONTEIRO_H_INCLUDED
