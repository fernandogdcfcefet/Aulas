/**
 * @file pilha_e.c
 * @brief Implementação de uma pilha sequencial.
 * 
 * Este arquivo contém a implementação dos protótipos da estrutura de dados
 * pilha encadeada definidos no arquivo cabeçalho 'pilha_s.h'. Contém, também,
 * a definição do tipo 'pilha'.
 * 
 * @author Anderson Grandi Pires (agpires@cefetmg.br)
 * @bug Nenhum bug conhecido.
 */

#include <stdlib.h>
#include "pilha_e.h"

typedef struct celula celula;

struct celula {
    item ctd;
    celula *prox;
};

struct pilha {
    celula *prim;
    int qtde;
};

pilha* pilha_criar() {
    return calloc(1, sizeof(pilha));
}

item pilha_topo(pilha *p) {
    return p->prim->ctd;
}

bool pilha_inserir(pilha *p, item it) {
    if(p == NULL)
        return false;

    celula *cel = (celula*) malloc(sizeof(celula));
    if(cel == NULL)
        return false;
    
    cel->ctd = it;
    cel->prox = p->prim;
    p->prim = cel;
    
    p->qtde++;

    return true;
}

pilha* pilha_liberar(pilha *p) {
    if(p == NULL)
        return p;
    
    while(!pilha_vazia(p))
        pilha_remover(p);
    free(p);

    return NULL;
}

bool pilha_remover(pilha *p) {
    if(p == NULL || pilha_vazia(p))
        return false;
    
    celula *removida = p->prim;
    p->prim = p->prim->prox;
    free(removida);
    p->qtde--;
    
    return true;
}

int pilha_tamanho(pilha *p) {
    if(p == NULL)
        return 0;
    
    return p->qtde;
}

bool pilha_vazia(pilha *p) {
    if(p == NULL)
        return true;
    
    return p->qtde == 0;
}