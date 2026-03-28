/**
 * @file lista_de.h
 * @brief Implementação de uma lista duplamente encadeada (lista_de).
 * 
 * Este arquivo contém a implementação dos protótipos da estrutura de dados
 * lista duplamente encadeada definidos celula arquivo cabeçalho 'lista_de.h'.
 * Contém, também, a definição do tipo 'lista'.
 * 
 * @author Anderson Grandi Pires (agpires@cefetmg.br)
 * @bug Nenhum bug conhecido.
 */

#include <stdio.h>
#include <stdlib.h>

#include "lista_de.h"

// Estrutura interna da lista (células)
struct celula {
    item ctd;
    celula *prox;
    celula* ant;
};

// Estrutura da lista
struct lista {
    celula *prim;
    int qtde;
};

bool lista_buscar(lista* l, item it) {
    if(lista_vazia(l))
        return false;
    
    celula *temp = l->prim;
    while(temp != NULL) {
        if(item_comparar(temp->ctd, it) == 0) {
            return true;
        }
        temp = temp->prox;
    }

    return false;
}

lista* lista_criar() {
    lista* l = (lista*) calloc(1, sizeof(lista));

    return l;
}

static celula* criar_celula(int valor) {
    celula* celulavo = (celula*) calloc(1, sizeof(celula));
    if(celulavo == NULL)
        return NULL;
    
    celulavo->prox = celulavo->ant = NULL;
    celulavo->ctd = valor;

    return celulavo;
}

bool lista_vazia(lista* l) {
    if(l == NULL)
        return true;
    
    return l->qtde == 0;
}

void lista_exibir(lista* l) {
    if(l == NULL)
        return;
    
    celula *temp = l->prim;
    while(temp != NULL) {
        item_exibir(temp->ctd);
        printf(" ");
        temp = temp->prox;
    }
}

bool lista_inserir(lista* l, int k, item it) {
    if(l == NULL || k <= 0 || k > l->qtde+1)
        return false;
    
    celula *nova = criar_celula(it);
    if(nova == NULL)
        return false;
    nova->ctd = it;
    if(lista_vazia(l)) {
        l->prim = nova;
    } else if(k == 1) {
        nova->prox = l->prim;
        l->prim->ant = nova;
        l->prim = nova;
    } else {
        celula *temp = l->prim;
        for(int i = 2; i < k; i++)
            temp = temp->prox;
        nova->prox = temp->prox;
        nova->ant = temp;
        temp->prox = nova;
        if(nova->prox != NULL)
            nova->prox->ant = nova;
    }
    l->qtde++;

    return true;
}

void lista_liberar(lista **l) {
    if(l == NULL || *l == NULL)
        return;

    celula *temp = (*l)->prim;
    while(temp != NULL) {
        (*l)->prim = (*l)->prim->prox;
        free(temp);
        temp = (*l)->prim;
        (*l)->qtde--;
    }

    free(*l);
    *l = NULL;
}

bool lista_remover(lista* l, int k, item *it) {
    if(l == NULL || lista_vazia(l) || k <= 0 || k > l->qtde)
        return false;
    
    celula *removida;
    if(k == 1) {
        removida = l->prim;
        l->prim = l->prim->prox;
        if(l->prim != NULL)
            l->prim->ant = NULL;
    } else {
        celula *temp = l->prim;
        for(int i = 2; i < k; i++)
            temp = temp->prox;
        removida = temp->prox;
        temp->prox = removida->prox;
        if(temp->prox != NULL)
            temp->prox->ant = temp;
    }
    *it = removida->ctd;
    free(removida);
    l->qtde--;

    return true;
}

int lista_tamanho(lista* l) {
    if(l == NULL)
        return 0;
    
    return l->qtde;
}