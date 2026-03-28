/**
 * @file lista_s_circ.c
 * @brief Implementação de uma lista sequencial (lista_s_circ) circular.
 * 
 * Este arquivo contém a implementação dos protótipos da estrutura de dados
 * lista sequencial circular definidos no arquivo cabeçalho 'lista_s_circ.h'.
 * Contém, também, a definição do tipo 'lista'.
 * 
 * @author Anderson Grandi Pires (agpires@cefetmg.br)
 * @bug Nenhum bug conhecido.
 */

#include <stdlib.h>
#include <stdio.h>
#include "lista_s_circ.h"

struct lista {
    item *dados;
    int inicio, fim;
    int capacidade;
};

bool lista_buscar(lista* l, item valor) { 
    if(l == NULL || lista_vazia(l))
        return false;

    // Elementos do vetor
    int i, id_pos = l->inicio;
    for(i = 1; i <= lista_tamanho(l); i++) {
        if(id_pos == lista_capacidade(l))
            id_pos = 0;
        printf("%d ", id_pos);
        if(l->dados[id_pos] == valor)
            return true;
        id_pos++;
    }

    return false;
}

int lista_capacidade(lista *l) {
    if(l == NULL)
        return 0;
    return l->capacidade;
}

lista* lista_criar(int capacidade) {
    lista *temp = (lista*) malloc(sizeof(lista));
    if(temp == NULL)
        return NULL;

    temp->dados = (item*) malloc(capacidade * sizeof(item));
    if(temp->dados == NULL) {
        free(temp);
        return NULL;
    }

    temp->capacidade = capacidade;
    temp->inicio = -1;
    temp->fim = 0;

    return temp;
}

bool lista_cheia(lista* l) {
    if(l == NULL)
        return false;

    if(lista_tamanho(l) == l->capacidade)
        return true;

    return false;
}

bool lista_vazia(lista* l) {
    if(l == NULL)
        return false;

    if(lista_tamanho(l) == 0)
        return true;

    return false;
}

static void lista_esvaziar(lista* l) {
    if(l == NULL)
        return;
    l->inicio = -1;
    l->fim = 0;
}

void lista_exibir(lista* l) { 
    if(l == NULL || lista_vazia(l))
        return;

    int i, id_pos = l->inicio;
    printf("\n");
    
    // Índices do vetor
    printf("idx: ");
    for(i = 1; i <= lista_tamanho(l); i++) {
        printf("%3d ", id_pos++);
        if(id_pos == lista_capacidade(l))
            id_pos = 0;
    }
    printf("\n");

    // Elementos do vetor
    printf("val: ");
    id_pos = l->inicio;
    for(i = 1; i <= lista_tamanho(l); i++) {
        printf("%3d ", l->dados[id_pos++]);
        if(id_pos == lista_capacidade(l))
            id_pos = 0;
    }
}

bool lista_inserir(lista* l, item it)  {
    if(lista_cheia(l))
        return false;

    if(lista_vazia(l))
        l->inicio = l->fim = 0;

    l->dados[l->fim] = it;
    l->fim += 1;
    if(l->fim == lista_capacidade(l))
        l->fim = 0;

    return true;
}

lista* lista_liberar(lista* l) {
    free(l);
    return NULL;
}

bool lista_remover(lista* l, item *v) {
    if(l == NULL || v == NULL)
        return false;

    if(lista_vazia(l))
        return false;

    *v = l->dados[l->inicio];
    l->inicio++;
    if(l->inicio == lista_capacidade(l))
        l->inicio = 0;
    
    if(l->inicio == l->fim) {
        lista_esvaziar(l);
    }

    return true;
}

int lista_tamanho(lista* l) {
    if(l->inicio == -1)
        return 0;
    if(l->fim > l->inicio)
        return l->fim - l->inicio;
    else
        return l->fim - l->inicio + lista_capacidade(l);
}