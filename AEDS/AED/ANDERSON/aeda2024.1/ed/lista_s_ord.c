/**
 * @file lista_s_ord.c
 * @brief Implementação de uma lista sequencial (lista_s) ordenada.
 * 
 * Este arquivo contém a implementação dos protótipos da estrutura de dados
 * lista sequencial ordenada definidos no arquivo cabeçalho 'lista_s_ord.h'.
 * Contém, também, a definição do tipo 'lista'.
 * 
 * @author Anderson Grandi Pires (agpires@cefetmg.br)
 * @bug Nenhum bug conhecido.
 */

#include <stdlib.h>
#include <stdio.h>
#include "lista_s_ord.h"

// Estrutura da lista
struct lista {
    item *dados;
    int qtde, cap;
};

bool lista_buscar(lista *l, item it) {
    if(l == NULL || lista_vazia(l))
        return false;
    
    for(int i = 0; i < l->qtde; i++) {
        if(item_comparar(l->dados[i], it) == 0)
            return true;
        else if(item_comparar(l->dados[i], it) > 0)
            break;
    }

    return false;
}

int lista_capacidade(lista *l) {
    if(l == NULL)
        return 0;
    
    return l->cap;
}

bool lista_cheia(lista *l) {
    if(l == NULL)
        return true;
    
    return l->qtde == l->cap;
}

lista* lista_criar(int capacidade) {
    lista *nova = (lista*) calloc(1, sizeof(lista));
    if(!nova)
        return NULL;
    nova->dados = (item*) calloc(capacidade, sizeof(item));
    if(!nova->dados) {
        free(nova);
        return NULL;
    }
    nova->cap = capacidade;

    return nova;
}

void lista_exibir(lista *l) {
    if(l == NULL || lista_vazia(l))
        return;
    
    for(int i = 0; i < l->qtde; i++) {
        item_exibir(l->dados[i]);
        printf(" ");
    }
}

bool lista_inserir(lista *l, item it) {
    if(l == NULL || lista_cheia(l))
        return false;
    
    int i = l->qtde-1;
    while(i >= 0 && item_comparar(l->dados[i], it) > 0) {
        l->dados[i+1] = l->dados[i];
        i--;
    }
    l->dados[i+1] = it;
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
    
    for(int i = k-1; i < l->qtde-1; i++)
        l->dados[i] = l->dados[i+1];
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