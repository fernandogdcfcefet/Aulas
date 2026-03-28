#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
}salgado;

typedef struct celula * apontador;

typedef struct celula{
    salgado MS;
    apontador prox;
}celula;

typedef struct{
    apontador fundo, topo;
    int tamanho;
}pilha;

void esvazia(pilha * minhaPilha){
    minhaPilha->topo = (apontador)malloc(sizeof(celula));
    minhaPilha->fundo = minhaPilha->topo;
    minhaPilha->tamanho = 0;
    minhaPilha->topo->prox = NULL;
}

int verificaVazia(pilha minhaPilha){
    return (minhaPilha.fundo==minhaPilha.topo);
    // return (minhaPilha.tamanho == 0);
}

void empilha(pilha *minhaPilha, salgado s){
    apontador aux = (apontador)malloc(sizeof(celula));
    aux->prox = minhaPilha->topo;
    minhaPilha->topo->MS = s;
    minhaPilha->topo = aux;
    minhaPilha->tamanho++;
}

void desempilha(pilha * minhaPilha, salgado * item){
    if(verificaVazia(*minhaPilha)){
        puts("Erro:pilha vazia");
    }else{
        apontador q = minhaPilha->topo;
        minhaPilha->topo = q->prox;
        *item = minhaPilha->topo->MS;
        minhaPilha->tamanho--;
        free(q);
    }
}

int main()
{
    pilha MP;
    salgado s;
    strcpy(s.nome,"coxinha");
    esvazia(&MP);
    empilha(&MP,s);
    strcpy(s.nome,"empada");
    empilha(&MP,s);
    strcpy(s.nome,"pastel");
    empilha(&MP,s);
    desempilha(&MP,&s);
    puts(s.nome);
    desempilha(&MP,&s);
    puts(s.nome);
    desempilha(&MP,&s);
    puts(s.nome);
    desempilha(&MP,&s);
    return 0;
}
