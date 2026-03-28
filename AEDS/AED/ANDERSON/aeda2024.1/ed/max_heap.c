/**
 * @file max_heap.c
 * @brief Implementação de uma heap máxima (max_heap).
 * 
 * Este arquivo contém a implementação dos protótipos da estrutura de dados
 * heap máxima definidos no arquivo cabeçalho 'heap_max.h'. Contém, também,
 * a definição do tipo 'lista'.
 * 
 * @author Anderson Grandi Pires (agpires@cefetmg.br)
 * @bug Nenhum bug conhecido.
 */

#include <stdio.h>
#include <stdlib.h>
#include "max_heap.h"

#define FLAG_ERRO -1

static int filho_esq(heap *h, int id_p);
static int filho_dir(heap *h, int id_p);
static bool inserir_fim(heap* h, item v);
static void max_heapify(heap *h, int id_p);
static int pai(heap *h, int id_f);
static void trocar(heap *h, int p1, int p2);

struct heap {
    item *dados;
    unsigned int capacidade;
    unsigned int qtde;
};

heap *heap_criar(int n) {
    heap* h = (heap*) malloc(sizeof(heap));
    if (h == NULL)
        return NULL;
    
    h->dados = (item*) malloc(n * sizeof(item));
    if(h->dados == NULL) {
        free(h);
        return NULL;
    }

    h->qtde = 0;
    h->capacidade = n;
    
    return h;
}

bool heap_cheia(heap* h) {
    if(h == NULL)
        return false;

    return h->qtde == h->capacidade;
}

bool heap_vazia(heap* h) {
    if(h == NULL)
        return false;

    return h->qtde == 0;
}

bool heap_esvaziar(heap* h) {
    if(h == NULL)
        return false;
    
    h->qtde = 0;
    return true;
}

void heap_exibir(heap *h) {
    int i, nivel = 1;
    for (i = 1; i <= h->qtde; i++) {
        if(i == nivel) {
            printf("\n");
            nivel = 2*i;
        }
        printf("%d ", h->dados[i-1]);
    }
}

static int filho_esq(heap *h, int id_p) { // id_p: índice de um pai
    int esq = 2*id_p + 1;
    if(esq >= h->qtde)
        return FLAG_ERRO;
    
    return esq;
}

static int filho_dir(heap *h, int id_p) { // id_p: índice de um pai
    int dir = 2*id_p + 2;
    if (dir >= h->qtde)
        return FLAG_ERRO;
    
    return dir;
}

static int pai(heap *h, int id_f) {     // id_f: índice de um filho
    if (id_f <= 0)
        return FLAG_ERRO;

    return (id_f-1)/2;                  // truncado: divisão inteira
}

void heap_liberar(heap** h) {
    free((*h)->dados);
    free(*h);
    *h = NULL;
}

bool heap_inserir(heap *h, item v) {
    if(!inserir_fim(h, v))
        return false;

    int id_v = h->qtde - 1;                 // índice atual de v
    int id_p = pai(h, id_v);         // índice do pai atual de v
    while(id_p >= 0 && h->dados[id_v] > h->dados[id_p]) {
        trocar(h, id_v, id_p);
        id_v = id_p;
        id_p = pai(h, id_v);
    }

    return true;
}

static bool inserir_fim(heap* h, item v) {
    if (h == NULL || heap_cheia(h))
        return false;

    h->dados[h->qtde] = v;
    h->qtde++;

    return true;
}

void heap_inserir_vetor(heap *h, item* vetor, int n) {
    for (int i = 0; i < n; i++)
        heap_inserir(h, vetor[i]);
}

static void max_heapify(heap *h, int id_p) {          // id_p: índice do elemento pai
    if(h == NULL || id_p < 0 || id_p >= h->qtde)
        return;

    int id_fe = filho_esq(h, id_p),
        id_fd = filho_dir(h, id_p);
    if(id_fe >= h->qtde)
        return;
    
    while((id_fe > 0 && h->dados[id_p] < h->dados[id_fe]) ||
          (id_fd > 0 && h->dados[id_p] < h->dados[id_fd])) {
        
        if(id_fd >= h->qtde) {
            trocar(h, id_p, id_fe);
            return;
        } else if(h->dados[id_fe] >= h->dados[id_fd]) {
            trocar(h, id_p, id_fe);
            id_p = id_fe;
        } else {
            trocar(h, id_p, id_fd);
            id_p = id_fd;
        }
        id_fe = filho_esq(h, id_p);
        if(id_fe >= h->qtde)
            return;
        id_fd = filho_dir(h, id_p);
    }
}

int heap_remover(heap *h) {
    if(h == NULL || heap_vazia(h))
        return FLAG_ERRO;

    int retorno = h->dados[0];
    h->dados[0] = h->dados[h->qtde - 1];
    h->qtde--;

    max_heapify(h, 0);
    
    return retorno;
}

int hap_tamanho(heap* h) {
    if(h == NULL)
        return FLAG_ERRO;

    return h->qtde;
}

static void trocar(heap *h, int id1, int id2) {
    int aux = h->dados[id1];
    h->dados[id1] = h->dados[id2];
    h->dados[id2] = aux;
}
