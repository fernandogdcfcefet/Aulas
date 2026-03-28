/**
 * @file pilha_e.h
 * @brief Protótipos para a pilha encadeada.
 * 
 * Este arquivo contém os protótipos da estrutura de dados pilha
 * encadeada (implementada com alocação dinâmica de memória), além
 * das declarações de tipos para a 'pilha' e os dados a serem
 * armazenados ('item').
 * 
 * @author Anderson Grandi Pires (agpires@cefetmg.br)
 * @bug Nenhum bug conhecido.
 */

#ifndef PILHA_H // INCLUDE GUARD
#define PILHA_H

#include <stdbool.h>
#include "item.h"

/*
 *  Definição do tipo de dado 'pilha'.
 */
typedef struct pilha pilha;

/**
 * @brief Cria uma pilha vazia.
 * @return O endereço de uma pilha com determinada 'capacidade'.
 */
pilha* pilha_criar();

/**
 * @brief Retorna o item do topo da pilha.
 * @param p Uma pilha (ponteiro).
 * @return O item do topo da pilha.
 */
item pilha_topo(pilha *p);

/**
 * @brief Insere um item na pilha.
 * @param p Uma pilha (ponteiro).
 * @param it O 'item' a ser inserido.
 * @return 'true' se a inserção ocorreu com sucesso; 'false' caso contrário.
*/
bool pilha_inserir(pilha *p, item it);

/**
 * @brief Libera a memória alocada para a pilha.
 * 
 * Utilize esta função da seguinte forma:
 * p = liberar(p);
 * onde 'p' é uma pilha. Poderia ser 'p1', 'p2', etc.
 * Com isso, a variável 'p' terá seu valor atualizado para 'NULL' após a
 * utilização desta função.
 * 
 * @param p Uma pilha p (ponteiro).
 * @return NULL
*/
pilha* pilha_liberar(pilha *p);

/**
 * @brief Remove um item da pilha.
 * @param p Uma pilha p (ponteiro).
 * @return 'true' se a remoção ocorreu com sucesso; 'false' caso contrário.
*/
bool pilha_remover(pilha *p);

/**
 * @brief Retorna o tamanho da pilha.
 * @param p Uma pilha p (ponteiro).
 * @return O tamanho da pilha.
*/
int pilha_tamanho(pilha *p);

/**
 * @brief Informa se a pilha está vazia.
 * @param p Uma pilha p (ponteiro).
 * @return 'true' se estiver vazia; 'false' caso contrário.
*/
bool pilha_vazia(pilha *p);

#endif // PILHA_H