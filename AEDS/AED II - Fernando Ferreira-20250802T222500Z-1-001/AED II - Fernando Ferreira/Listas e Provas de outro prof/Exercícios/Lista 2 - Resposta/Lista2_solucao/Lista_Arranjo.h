#ifndef LISTA_ARRANJO_H_INCLUDED
#define LISTA_ARRANJO_H_INCLUDED
//=================================================================================================
// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
//=================================================================================================
#define MAXTAM 1000
//=================================================================================================
// Define o tipo Lista usando arranjos
typedef struct TipoLista{
 int Item[MAXTAM];
 int Primeiro, Ultimo;
};
//=================================================================================================

// Procedimentos para manipular os dados na Lista

// Procedimento que inicializa a Lista
void FLVazia(TipoLista &Lista){
    Lista.Primeiro = 1;
    Lista.Ultimo = Lista.Primeiro;
}

// Procedimento que verifica se a Lista está vazia
bool Vazia(TipoLista Lista){
    return (Lista.Primeiro == Lista.Ultimo);
}

// Procedimento que insere um novo elemento na Lista
void Insere(TipoLista &Lista, int item){
    if( Lista.Ultimo > MAXTAM ){
        printf("Erro: Lista Cheia!\n");
    } else {
        Lista.Item[Lista.Ultimo-1] = item;
        Lista.Ultimo++;
    }
}

// Procedimento que remove um elemento da Lista
int Remove(TipoLista &Lista, int p){
    if(Vazia(Lista) || p >= Lista.Ultimo){
        printf("Erro: Lista Vazia ou Posicao Inexistente!\n");
        return -1;
    }
    else{
        int item  = Lista.Item[p-1];

        Lista.Ultimo--;

        for(int i=p; i< Lista.Ultimo;i++)
            Lista.Item[i-1] = Lista.Item[i];

        return item;
    }
}

// Procedimento que retorna o tamanho da Lista
int Tamanho(TipoLista Lista){
    return Lista.Ultimo-1;
}

// Procedimento que imprimi os dados da Lista
void Imprimi(TipoLista Lista){

    printf("Tamanho da Lista: %d\n",Tamanho(Lista));

    for(int i=Lista.Primeiro-1; i < Lista.Ultimo - 1; i++)
        printf("%d\n",Lista.Item[i]);
}
//=================================================================================================
#endif // LISTA_ARRANJO_H_INCLUDED
