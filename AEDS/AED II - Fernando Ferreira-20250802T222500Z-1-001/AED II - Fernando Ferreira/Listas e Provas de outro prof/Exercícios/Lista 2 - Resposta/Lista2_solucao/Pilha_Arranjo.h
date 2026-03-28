#ifndef PILHA_ARRANJO_H_INCLUDED
#define PILHA_ARRANJO_H_INCLUDED
//=================================================================================================
// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
//=================================================================================================
#define MAXTAM 70
#define CANCELACARATER  '#'
#define CANCELALINHA    '/'
#define SALTALINHA      '@'
#define MARCAEOF '~'
//=================================================================================================
typedef char TipoItem;
//=================================================================================================
// Define o tipo Pilha usando arranjos
typedef struct TipoPilha{
 TipoItem Item[MAXTAM];
 int Topo;
};
//=================================================================================================

// Procedimentos para manipular os dados na pilha

// Procedimento que inicializa a pilha
void FPVazia(TipoPilha &Pilha){
    Pilha.Topo = 0;
}

// Procedimento que verifica se a pilha está vazia
bool Vazia(TipoPilha Pilha){
    return (Pilha.Topo == 0);
}

// Procedimento que insere um novo elemento no topo da pilha
void Empilha(TipoPilha &Pilha, TipoItem item){
    if(Pilha.Topo == MAXTAM){
        printf("Erro: Pilha Cheia!\n");
    } else {
        Pilha.Item[Pilha.Topo] = item;
        Pilha.Topo++;
    }
}

// Procedimento que remove um elemento do topo da pilha
TipoItem Desempilha(TipoPilha &Pilha){
    if(Vazia(Pilha)){
        printf("Erro: Pilha Vazia!\n");
        return -1;
    }
    else{
        Pilha.Topo--;
        return Pilha.Item[Pilha.Topo];
    }
}

// Procedimento que retorna o tamanho da pilha
int Tamanho(TipoPilha Pilha){
    return Pilha.Topo;
}

// Procedimento que imprimi os dados da pilha
void Imprimi(TipoPilha Pilha){

    printf("Tamanho da Pilha: %d\n",Tamanho(Pilha));

    for(int i=Pilha.Topo-1; i>=0;i--)
        printf("%c\n",Pilha.Item[i]);
}

TipoPilha clone(TipoPilha Pilha){

    TipoPilha p1, p2;
    FPVazia(p1);
    FPVazia(p2);

    while(!Vazia(Pilha))
       Empilha(p1,Desempilha(Pilha));

    while(!Vazia(p1))
       Empilha(p2,Desempilha(p1));

    return p2;
}

TipoPilha concatena(TipoPilha Pilha1, TipoPilha Pilha2){

    TipoPilha p1 = clone(Pilha1);
    TipoPilha p2;

    FPVazia(p2);

    while(!Vazia(Pilha2))
       Empilha(p2,Desempilha(Pilha2));

    while(!Vazia(p2))
       Empilha(p1,Desempilha(p2));

    return p1;
}

bool verifica(char *expressao, int n){

    TipoPilha p;
    FPVazia(p);

    for(int i=0;i<n;i++){
        if(expressao[i]=='(')
           Empilha(p,expressao[i]);

        if(expressao[i]==')')
            if(Vazia(p))
                return false;
            else
                Desempilha(p);
    }

    if(Vazia(p))
        return true;
    else false;
}


//=================================================================================================
#endif // PILHA_ARRANJO_H_INCLUDED
