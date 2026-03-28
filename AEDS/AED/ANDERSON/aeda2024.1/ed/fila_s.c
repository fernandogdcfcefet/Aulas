/**
 * @file fila_s.c
 * @brief Implementação de uma fila sequencial (fila_s).
 * 
 * Este arquivo contém a implementação dos protótipos da estrutura de dados
 * fila sequencial definidos no arquivo cabeçalho 'fila_s.h'. Contém, também,
 * a definição do tipo 'fila'.
 * 
 * @author Anderson Grandi Pires (agpires@cefetmg.br)
 * @bug Nenhum bug conhecido.
 */

#include <stdlib.h>
#include "fila_s.h"

struct fila {
    item *dados;
    int qtde, cap;
};

int fila_capacidade(fila *f) {
    return f->cap;
}

bool fila_cheia(fila *f) {
    return f->cap == f->qtde;
}

fila* fila_criar(int capacidade) {
    fila *nova = (fila*) malloc(sizeof(fila));
    if(nova != NULL) {
        nova->dados = (item*) malloc(capacidade * sizeof(item));
        if(nova->dados == NULL) {
            free(nova);
            return NULL;
        }
        nova->qtde = 0;
        nova->cap = capacidade;
    }
    
    return nova;
}

item fila_frente(fila *f) {
    return f->dados[0];
}

bool fila_inserir(fila *f, item it) {
    if(f == NULL || fila_cheia(f))
        return false;
    
    f->dados[f->qtde] = it;
    f->qtde++;

    return true;
}

fila* fila_liberar(fila *f) {
    if(f != NULL) {
        free(f->dados);
        free(f);
    }
    
    return NULL; 
}

bool fila_remover(fila *f) {
    if(f == NULL || fila_vazia(f))
        return false;

    for(int i = 1; i < fila_tamanho(f); i++)
        f->dados[i-1] = f->dados[i];
    f->qtde--;

    return true;
}

int fila_tamanho(fila *f) {
    return f->qtde;
}

bool fila_vazia(fila *f) {
    return f->qtde == 0;
}