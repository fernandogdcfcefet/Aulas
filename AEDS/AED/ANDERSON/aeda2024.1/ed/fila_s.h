/**
 * @file fila_s.h
 * @brief Protótipos para a fila sequencial (fila_s).
 * 
 * Este arquivo contém os protótipos da estrutura de dados fila
 * sequencial (implementada com alocação dinâmica de memória), além
 * das declarações de tipos para a 'fila' e os dados a serem
 * armazenados ('item').
 * 
 * @author Anderson Grandi Pires (agpires@cefetmg.br)
 * @bug Nenhum bug conhecido.
 */

#include <stdbool.h>
#include "item.h"

typedef struct fila fila;

/**
 * @brief Retorna a capacidada da fila (número máximo de itens).
 * 
 * O retorno está associado ao número máximo de itens que podem ser
 * armazenados na pilha. Está informação não está associada ao tamanho
 * atual da pilha.
 * 
 * @param f Uma fila (ponteiro)
 * @return número máximo de itens da pilha.
 */
int fila_capacidade(fila *f);

/**
 * Informa se a fila está cheia.
 * @param f Uma fila (ponteiro)
 * @return 'true' se estiver cheia; 'false' caso contrário.
 */
bool fila_cheia(fila *f);

/**
 * @brief Cria uma fila vazia.
 * @param capacidade Capacidade máxima da fila (número máximo de itens).
 * @return Uma fila (o endereço de uma fila) com determinada 'capacidade' ou
 * 'NULL' caso ocorra erro.
 */
fila* fila_criar(int capacidade);

/**
 * @brief Retorna o item da frente da fila.
 * @param f Uma fila (ponteiro).
 * @return O item da frente da fila.
 */
item fila_frente(fila *f);

/**
 * @brief Insere um item na fila.
 * @param f Uma pilha (ponteiro).
 * @param it O 'item' a ser inserido.
 * @return 'true' se a inserção ocorreu com sucesso; 'false' caso contrário.
*/
bool fila_inserir(fila *f, item it);

/**
 * @brief Libera a memória alocada para a fila.
 * 
 * Utilize esta função da seguinte forma:
 * f = liberar(f);
 * onde 'f' é uma fila. Poderia ser 'f1', 'f2', etc.
 * Com isso, a variável 'f' terá seu valor atualizado para 'NULL' após a
 * utilização desta função.
 *  
 * @param f Uma fila f (ponteiro).
 * @return retorna 'NULL'.
*/
fila* fila_liberar(fila *f);

/**
 * @brief Remove um item da fila.
 * @param f Uma fila f (ponteiro).
 * @return 'true' se a remoção ocorreu com sucesso; 'false' caso contrário.
*/
bool fila_remover(fila *f);

/**
 * @brief Retorna o tamanho da fila.
 * @param f Uma fila f (ponteiro).
 * @return O tamanho da fila.
*/
int fila_tamanho(fila *f);

/**
 * @brief Informa se a fila está vazia.
 * @param f Uma fila f (ponteiro).
 * @return 'true' se estiver vazia; 'false' caso contrário.
*/
bool fila_vazia(fila *f);
