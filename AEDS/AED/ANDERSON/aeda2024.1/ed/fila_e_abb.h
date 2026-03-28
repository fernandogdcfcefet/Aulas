/**
 * @file fila_s.h
 * @brief Protótipos para a fila encadeada usada na abb (fila_e_abb).
 * 
 * Este arquivo contém os protótipos da estrutura de dados fila
 * encadeada (implementada com alocação dinâmica de memória), além
 * das declarações de tipos para a 'fila' e os nós 'no' da abb 
 * a serem armazenados.
 * 
 * @author Anderson Grandi Pires (agpires@cefetmg.br)
 * @bug Nenhum bug conhecido.
 */

#ifndef FILA
#define FILA

#include <stdbool.h>

typedef struct fila fila;
typedef struct no no;

/**
 * @brief Cria uma fila vazia.
 * @return Uma fila (o endereço de uma fila) ou 'NULL' caso ocorra erro.
 */
fila* fila_criar();

/**
 * @brief Retorna o nó da frente da fila.
 * @param f Uma fila (ponteiro).
 * @return O 'no' da frente da fila.
 */
no* fila_frente(fila* f);

/**
 * @brief Insere um nó na fila.
 * @param f Uma pilha (ponteiro).
 * @param n O 'no' a ser inserido.
 * @return 'true' se a inserção ocorreu com sucesso; 'false' caso contrário.
*/
bool fila_inserir(fila* f, no* n);

/**
 * @brief Libera a memória alocada para a fila.
 * 
 * Utilize esta função da seguinte forma:
 * liberar(&f);
 * onde 'f' é uma fila. Poderia ser 'f1', 'f2', etc.
 * Com isso, a variável 'f' terá seu valor atualizado para 'NULL' após a
 * utilização desta função.
 *  
 * @param f Um ponteiro para a fila f (ponteiro).
 * @return retorna 'NULL'.
*/
void fila_liberar(fila* *f);

/**
 * @brief Remove um nó da fila.
 * @param f Uma fila f (ponteiro).
 * @return 'true' se a remoção ocorreu com sucesso; 'false' caso contrário.
*/
bool fila_remover(fila* f);

/**
 * @brief Retorna o tamanho da fila.
 * @param f Uma fila f (ponteiro).
 * @return O tamanho da fila.
*/
int fila_tamanho(fila* f);

/**
 * @brief Informa se a fila está vazia.
 * @param f Uma fila f (ponteiro).
 * @return 'true' se estiver vazia; 'false' caso contrário.
*/
bool fila_vazia(fila* l);

#endif  // FILA