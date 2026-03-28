/**
 * @file abb.h
 * @brief Protótipos para uma árvore binária de busca (abb).
 * 
 * Este arquivo contém a implementação da estrutura de dados árvore
 * binária de busca (implementada com alocação dinâmica de memória),
 * além das declarações de tipos para 'fila' e os dados a serem
 * armazenados ('item').
 * 
 * @author Anderson Grandi Pires (agpires@cefetmg.br)
 * @bug Nenhum bug conhecido.
 */

#include <stdlib.h>
#include <stdio.h>
#include "abb.h"
#include "fila_e_abb.h"

struct no {
    item info;
    no* sae;    // sub-árvore a esquerda
    no* sad;    // sub_árvore a direita
};

bool abb_buscar(no* n, item it) {
    if(n == NULL)
        return false;
    
    int cmp = item_comparar(it, n->info);
    if(cmp == 0)
        return true;
    else if(cmp < 0)
        return abb_buscar(n->sae, it);
    else
        return abb_buscar(n->sad, it);
}

no* abb_criar(item it) {
    no *novo = (no*) malloc(sizeof(no));
    if(novo != NULL) {    
        novo->info = it;
        novo->sae = novo->sad = NULL;
    }

    return novo;
}

no* abb_inserir(no* n, item it) {
    if(n == NULL)
        return abb_criar(it);

    if(item_comparar(it, n->info) < 0)
        n->sae = abb_inserir(n->sae, it);
    else
        n->sad = abb_inserir(n->sad, it);

    return n;
}

void abb_largura(no* n) {
    fila* f = fila_criar();
    fila_inserir(f, n);
    while(!fila_vazia(f)) {
        no* atual = fila_frente(f);
        item_exibir(atual->info);
        printf(" ");
        fila_remover(f);
        if(atual->sae)
            fila_inserir(f, atual->sae);
        if(atual->sad)
            fila_inserir(f, atual->sad);
    }
}

void abb_liberar(no* n) {
    if(n == NULL)
        return;
    
    no* temp = n;
    abb_liberar(n->sae);
    abb_liberar(n->sad);
    free(temp);
}

void abb_profunidade(no *n) {
    if(n == NULL)
        return;

    abb_profunidade(n->sae);
    abb_profunidade(n->sad);
    item_exibir(n->info);
    printf(" ");
}

static no* minimo(no* n) {
    if(n == NULL)
        return NULL;
    else if(n->sae != NULL)
        return minimo(n->sae);

    return n;
}

no* abb_remover(no* n, item it) {
    if(n == NULL)
        return NULL;
    
    int cmp = item_comparar(it, n->info);
    if(cmp < 0) {
        n->sae = abb_remover(n->sae, it);
    } else if(cmp > 0) {
        n->sad = abb_remover(n->sad, it);
    } else {
        no* temp = NULL;
        if(n->sae == NULL && n->sad == NULL) {
            free(n);
            return NULL;
        } else if(n->sae == NULL) {
            temp = n->sad;
            free(n);
            return temp;
        } else if(n->sad == NULL) {
            temp = n->sae;
            free(n);
            return temp;
        } else {
            no* temp = minimo(n->sad);
            n->info = temp->info;
            n->sad = abb_remover(n->sad, temp->info);
        }
    }
    
    return n;
}
