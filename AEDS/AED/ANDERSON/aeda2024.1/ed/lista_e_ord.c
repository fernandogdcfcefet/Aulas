/**
 * @file lista_e_ord.c
 * @brief Implementação de uma lista encadeada (lista_e) ordenada.
 * 
 * Este arquivo contém a implementação dos protótipos da estrutura de dados
 * lista encadeada ordenada definidos no arquivo cabeçalho 'lista_e.h'. Contém,
 * também, a definição do tipo 'lista'.
 * 
 * @author Anderson Grandi Pires (agpires@cefetmg.br)
 * @bug Nenhum bug conhecido.
 */

#include <stdlib.h>
#include <stdio.h>
#include "lista_e_ord.h"

// Estrutura interna da lista (células)
typedef struct celula celula;
struct celula {
    item ctd;
    celula* prox;
};

// Estrutura da lista
struct lista {
    celula* prim;
    int qtde;
};

bool lista_buscar(lista *l, item it) {
    if(l == NULL || lista_vazia(l))
        return false;
    
    celula *temp = l->prim;
    while(temp != NULL && item_comparar(temp->ctd, it) <= 0) {
        if(item_comparar(temp->ctd, it))
            return true;
        temp = temp->prox;
    }

    return false;
}

lista* lista_criar() {
    return (lista*) calloc(1, sizeof(lista));
}

void lista_exibir(lista *l) {
    if(l == NULL || lista_vazia(l))
        return;
    
    celula* temp = l->prim;
    while(temp != NULL) {
        item_exibir(temp->ctd);
        printf(" ");
        temp = temp->prox;
    }
}

bool lista_inserir(lista *l, item it) {
    if(l == NULL)
        return false;
    
    celula* nova;
    if(lista_vazia(l) || item_comparar(it, l->prim->ctd) < 0) {
        nova = (celula*) malloc(sizeof(celula));
        if(nova == NULL)
            return false;
        nova->ctd = it;
        nova->prox = l->prim;
        l->prim = nova;
    } else {
        celula *atual = l->prim;
        celula *prox = atual->prox;
        while(prox != NULL && item_comparar(prox->ctd, it) < 0) {
            atual = prox;
            prox = atual->prox;
        }
        nova = (celula*) malloc(sizeof(celula));
        if(nova == NULL)
            return false;
        nova->ctd = it;
        if(prox == NULL)
            nova->prox = NULL;
        else
            nova->prox = prox;
        atual->prox = nova;
    }
    l->qtde++;

    return true;
}

lista* lista_liberar(lista *l) {
    while(!lista_vazia(l))
        lista_remover(l, 1);
    free(l);

    return NULL;
}

bool lista_remover(lista *l, int k) {
    if(l == NULL || lista_vazia(l) || k < 1 || k > l->qtde)
        return false;
    
    celula* rem;
    if(k == 1) {
        rem = l->prim;
        l->prim = rem->prox;
    } else {
        celula *temp = l->prim;
        for(int i = 1; i < k-1; i++)
            temp = temp->prox;
        rem = temp->prox;
        temp->prox = rem->prox;
    }
    free(rem);
    l->qtde--;

    return true;
}

int lista_tamanho(lista *l) {
    if(l == NULL)
        return 0;
    
    return l->qtde;
}

bool lista_vazia(lista *l) {
    if(l == NULL)
        return true;
    
    return l->qtde == 0;
}