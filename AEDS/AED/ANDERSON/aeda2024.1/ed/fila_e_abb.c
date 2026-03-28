#include <stdio.h>
#include <stdlib.h>

#include "fila_e_abb.h"
#include "abb.h"

// IMPLEMENTAÇÃO DA FILA ENCADEADA

typedef struct cel celula;
struct cel {
    no* conteudo;
    celula *prox;
};

struct fila {
    celula *prim;
    int qtde;
};

fila* fila_criar() {
    fila *f = (fila*) calloc(1, sizeof(fila));

    return f;
}

static celula* criar_celula(item it) {
    celula *nova = (celula*) malloc(sizeof(celula));
    if(nova != NULL) {
        nova->conteudo = abb_criar(it);
        nova->prox = NULL;
    }

    return nova;
}

no* fila_frente(fila* f) {
    return f->prim->conteudo;
}

bool fila_inserir(fila* f, no* n) {
    if(f == NULL)
        return false;

    celula *cel = (celula*) calloc(1, sizeof(celula));
    cel->conteudo = n;
    cel->prox = NULL;

    if(fila_vazia(f))
        f->prim = cel;
    else {
        celula *temp = f->prim;
        while(temp->prox != NULL)
            temp = temp->prox;
        temp->prox = cel;
    }
    f->qtde++;

    return true;
}

void fila_liberar(fila* *f) {
    if(fila_vazia(*f))
        return;

    int r;    
    while(!fila_vazia(*f))
        fila_remover(*f);
    
    free(*f);
    *f = NULL;
}

bool fila_remover(fila *f) {
    if(fila_vazia(f))
        return false;
    
    celula *removida = f->prim;
    f->prim = f->prim->prox;
    free(removida);
    f->qtde--;

    return true;
}

int fila_tamanho(fila* f) {
    if(f == NULL)
        return 0;

    return f->qtde;
}

bool fila_vazia(fila* f) {
    if(f == NULL)
        return true;
    
    return f->qtde == 0;
}