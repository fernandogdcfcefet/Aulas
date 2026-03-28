#ifndef FILA_ARRANJO_H_INCLUDED
#define FILA_ARRANJO_H_INCLUDED
//=================================================================================================
// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
//=================================================================================================
#define MAXTAM 1000
//=================================================================================================
typedef struct Cliente{
char nome[100];
int idade;
};
typedef Cliente TipoItem;
//=================================================================================================
// Define o tipo Fila usando arranjos
typedef struct TipoFila{
 TipoItem Item[MAXTAM];
 int Tamanho;
 int Frente, Tras;
};
//=================================================================================================

// Procedimentos para manipular os dados na fila

// Procedimento que inicializa a fila
void FFVazia(TipoFila &Fila){
    Fila.Frente = 1;
    Fila.Tras = Fila.Frente;
    Fila.Tamanho = 0;
}

// Procedimento que verifica se a fila está vazia
bool Vazia(TipoFila Fila){
    return (Fila.Frente == Fila.Tras);
}

// Procedimento que insere um novo elemento no topo da fila
void Enfileira(TipoFila &Fila, TipoItem item){
    if( (Fila.Tras % MAXTAM) + 1 == Fila.Frente){
        printf("Erro: Fila Cheia!\n");
    } else {
        Fila.Item[Fila.Tras-1] = item;
        Fila.Tras = Fila.Tras%MAXTAM + 1;
        Fila.Tamanho++;
    }
}

void EnfileiraComPrioridade(TipoFila &Fila, TipoItem item){
    if( (Fila.Tras % MAXTAM) + 1 == Fila.Frente){
        printf("Erro: Fila Cheia!\n");
    } else {

        int pos = Fila.Tras-1;
        Fila.Item[Fila.Tras-1] = item;
        Fila.Tras = Fila.Tras%MAXTAM + 1;
        Fila.Tamanho++;

        if(item.idade >= 65){

            TipoItem aux1 = item, aux2;


            for(int i=Fila.Frente-1; i != Fila.Tras - 1;i = i%MAXTAM+1)
                if(Fila.Item[i].idade < 65 || i == pos){
                    aux2 = Fila.Item[i];
                    Fila.Item[i] = aux1;
                    aux1 = aux2;
                }

        }

    }
}

// Procedimento que remove um elemento do topo da fila
TipoItem Desenfileira(TipoFila &Fila){
    if(Vazia(Fila)){
        printf("Erro: Fila Vazia!\n");
    }
    else{
        TipoItem item  = Fila.Item[Fila.Frente-1];
        Fila.Frente = Fila.Frente%MAXTAM + 1;
        Fila.Tamanho--;
        return item;
    }
}

// Procedimento que retorna o tamanho da fila
int Tamanho(TipoFila Fila){
    return Fila.Tamanho;
}

// Procedimento que imprimi os dados da fila
void Imprimi(TipoFila Fila){

    printf("Tamanho da Fila: %d\n",Tamanho(Fila));

    for(int i=Fila.Frente-1; i != Fila.Tras - 1;i = i%MAXTAM+1)
        printf("%i - %s\n",Fila.Item[i].idade,Fila.Item[i].nome);
}
//=================================================================================================
#endif // FILA_ARRANJO_H_INCLUDED
