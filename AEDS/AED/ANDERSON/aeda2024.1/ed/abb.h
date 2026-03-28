/**
 * @file abb.h
 * @brief Protótipos para uma árvore binária de busca(abb).
 * 
 * Este arquivo contém os protótipos da estrutura de dados árvore
 * binária de busca (implementada com alocação dinâmica de memória),
 * além das declarações de tipos para a 'fila' e os dados a serem
 * armazenados ('item').
 * 
 * @author Anderson Grandi Pires (agpires@cefetmg.br)
 * @bug Nenhum bug conhecido.
 */

#ifndef ABB_H    // INCLUDE GUARD
#define ABB_H

#include <stdbool.h>
#include "item.h"

typedef struct no no;

bool abb_buscar(no* a, item it);

/**
 * @brief Cria uma árvore vazia.
 * @param it Item a ser inserido na raiz da árvore.
 * @return Uma árvore (o endereço de uma abb) tendo 'it' armazenado
 * na raiz da árvore ou 'NULL' caso ocorra erro.
 */
no* abb_criar(item it);

/**
 * @brief Insere um item na árvore.
 * @param n Um ponteiro para um nó da árvore.
 * @param it O 'item' a ser inserido.
 * @return um novo nó se 'n' for NULL ou retorna 'n'
*/
no* abb_inserir(no* n, item it);

/**
 * @brief Executa uma busca em largura na árvore.
 * @param n Um nó da árvore (ponteiro).
 */
void abb_largura(no* n);

/**
 * @brief Libera a memória alocada para a árvore.
 * 
 * Utilize esta função da seguinte forma:
 * n = liberar(n);
 * onde 'n' é um nóa da abb. Poderia ser 'n1', 'n2', etc.
 * Com isso, a variável 'n' terá seu valor atualizado para 'NULL' após a
 * utilização desta função.
 *  
 * @param n Um nó da árvore binária de busca (ponteiro).
 * @return retorna 'NULL'.
*/
void abb_liberar(no* n);

/**
 * @brief Executa uma busca em profundidade na árvore.
 * @param n Um nó da árvore (ponteiro).
 */
void abb_profunidade(no *n);

/**
 * @brief Remove um item da árvore.
 * @param n Um nó da árvore (ponteiro).
 * @return a referência de algum nó da abb (o mesmo ou algum descendente).
*/
no* abb_remover(no* n, item item);

#endif // ABB_H