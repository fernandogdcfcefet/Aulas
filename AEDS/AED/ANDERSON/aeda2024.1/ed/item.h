/**
 * @file item.h
 * @brief Protótipos para o tipo de item a ser armazenado nas estruturas.
 * 
 * Este arquivo contém os protótipos da estrutura de dados 'item', além
 * da declaração de tipo. Esta estrutura deve ser ajustada para atender
 * às necessidades da aplicação. As estruturas de dados do tipo coleção
 * (lista, fila, pilha, etc.) armazenam dados do tipo 'item'.
 * 
 * Este arquivo deverá ser editado para comportar outros tipos de dados.
 * 
 * @author Anderson Grandi Pires (agpires@cefetmg.br)
 * @bug Nenhum bug conhecido.
 */

#ifndef ITEM_H
#define ITEM_H

#include <stdbool.h>

/**
 * @brief Definição do tipo 'item' que será armazenado nas estruturas de dados.
 * Altere este item para armazenar o tipo de dado desejado.
 */ 
typedef int item;

/**
 * @brief Exibe um item
 * 
 * Esta função deve ser implementada no arquivo 'item.c' de acordo com
 * a definição do tipo item acima.
 * 
 * @param it o item a ser exibido
*/
void item_exibir(item it);

/**
 * @brief Compara dois itens
 * 
 * Esta função deve ser implementada no arquivo 'item.c' de acordo com
 * a definição do tipo item acima.
 * 
 * @param it1 o primeiro item a ser comparado
 * @param it2 o segundo item a ser comparado
 * @return '0' se os itens forem iguais; '>0' se it1 > it2; e '<0' se it1 < it2
*/
int item_comparar(item it1, item it2);

#endif // ITEM_H