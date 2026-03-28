/**
 * @file lista_s_circ.h
 * @brief Protótipos para a lista sequencial circular (lista_s_circ).
 * 
 * Este arquivo contém os protótipos da estrutura de dados lista
 * sequencial circular (implementada com vetor e alocação dinâmica
 * de memória), além das declarações de tipos para a 'lista' e os
 * dados a serem armazenados ('item').
 * 
 * @author Anderson Grandi Pires (agpires@cefetmg.br)
 * @bug Nenhum bug conhecido.
 */

#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>
#include "item.h"

typedef struct lista lista;

/**
 * @brief Procura por um item na lista.
 * @param l uma lista
 * @param it o item a ser procurado
 * @return 'true' se o item encontra-se na lista; 'false' caso contrário
 */
bool lista_buscar(lista* l, item it);

/**
 * @brief Retorna a capacidade da lista
 * @param l uma lista (ponteiro)
 * @return quantidade máximo de itens que podem estar na lista
*/
int lista_capacidade(lista *l);

/**
 * @brief Informa se a lista está cheia
 * @param l uma lista (ponteiro)
 * @return 'true' se estiver cheia; 'false' caso contrário
*/
bool lista_cheia(lista* l);

/**
 * @brief Cria uma lista vazia com determinada capacidade
 * @param capacidade número máximo de itens da lista
 * @return a lista criada (ponteiro para a lista) ou NULL em caso de erro
*/
lista* lista_criar();


/**
 * @brief Exibe o conteúdo da lista
 * @param l uma lista (ponteiro)
 * @return Não tem
*/
void lista_exibir(lista* l);

/**
 * @brief Insere um item na da lista
 * @param l uma lista (ponteiro)
 * @param it item a ser inserido
 * @return 'true' se inserido com sucesso; 'false' caso contrário
*/
bool lista_inserir(lista* l, item it);

/**
 * @brief Libera a memória alocada para a lista
 * 
 * Utilize esta função da seguinte forma:
 * l = liberar(l);
 * onde 'l' é uma lista. Poderia ser 'l1', 'l2', etc.
 * Com isso, a variável 'l' terá seu valor atualizado para 'NULL' após a
 * utilização desta função.
 * 
 * @param l uma lista (ponteiro)
 * @return NULL
*/
lista* lista_liberar(lista* l);

/**
 * @brief Remove um item da lista
 * @param l uma lista (ponteiro)
 * @param v o item removido
 * @return 'true' se removido com sucesso; 'false' caso contrário
*/
bool lista_remover(lista* l, item *v);

/**
 * @brief Retorna o tamanho da lista
 * @param l uma lista (ponteiro)
 * @return quantidade de itens presentes na lista
*/
int lista_tamanho(lista* l);

/**
 * @brief Informa se a lista está vazia
 * @param l uma lista (ponteiro)
 * @return 'true' se estiver vazia; 'false' caso contrário
*/
bool lista_vazia(lista* l);

#endif // LISTA_H
