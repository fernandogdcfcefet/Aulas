/**
 * @file max_heap.h
 * @brief Protótipos para uma heap máxima (max_heap).
 * 
 * Este arquivo contém os protótipos da estrutura de dados heap
 * máxima sequencial (implementada com vetor e alocação dinâmica
 * de memória), além das declarações de tipos para a 'lista' e os
 * dados a serem armazenados ('item').
 * 
 * @author Anderson Grandi Pires (agpires@cefetmg.br)
 * @bug Nenhum bug conhecido.
 */

#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>
#include "item.h"

typedef struct heap heap;

/**
 * @brief Cria uma heap vazia com determinada capacidade
 * @param capacidade número máximo de itens na heap
 * @return a heap criada (ponteiro para a heap) ou NULL em caso de erro
*/
heap* heap_criar(int n);

/**
 * @brief Informa se a heap está cheia
 * @param h uma heap (ponteiro)
 * @return 'true' se estiver cheia; 'false' caso contrário
*/
bool heap_cheia(heap* h);

/**
 * @brief Remove todos os itens da heap
 * @param h uma heap (ponteiro)
 * @return 'true' se heap vazia; 'false' caso contrário
*/
bool heap_esvaziar(heap* h);

/**
 * @brief Exibe o conteúdo da heap para fins de verificação
 * @param h uma heap (ponteiro)
*/
void heap_exibir(heap *h);

/**
 * @brief Insere um item na heap
 * @param h uma heap (ponteiro)
 * @param it item a ser inserido
 * @return 'true' se inserido com sucesso; 'false' caso contrário
*/
bool heap_inserir(heap *h, item it);

/**
 * @brief Insere os itens de um vetor na heap
 * @param h uma heap (ponteiro)
 * @param vetor vetor de itens a serem inseridos
 * @param n tamanho do vetor
 * @return 'true' se inserido com sucesso; 'false' caso contrário
*/
void heap_inserir_vetor(heap *h, item* vetor, item n);

/**
 * @brief Libera a memória alocada para a heap
 * 
 * Utilize esta função da seguinte forma:
 *
 * heap *h = heap_criar(10);
 * ...
 * hap_liberar(&h);
 *
 * onde 'h' é uma heap. Poderia ser 'h1', 'h2', etc.
 * Internamente, a variável 'h' terá seu valor atualizado para 'NULL' após a
 * utilização desta função.
 * 
 * @param h uma heap (ponteiro)
*/
void heap_liberar(heap** l);

/**
 * @brief Remove o item máximo da heap
 * @param h uma lista (ponteiro)
 * @return o item removido
*/
item heap_remover(heap *h);

/**
 * @brief Informa se a heap está vazia
 * @param h uma heap (ponteiro)
 * @return 'true' se estiver vazia; 'false' caso contrário
*/
bool heap_vazia(heap* h);

#endif //HEAP_H