/**
 * @file item.c
 * @brief Implementação de um item a ser armazenado nas estruturas.
 * 
 * Este arquivo contém a implementação dos protótipos da estrutura de dados
 * item definidos no arquivo cabeçalho 'item.h'.
 * 
 * Este arquivo deverá ser editado para comportar outros tipos de dados.
 * 
 * @author Anderson Grandi Pires (agpires@cefetmg.br)
 * @bug Nenhum bug conhecido.
 */

#include <stdio.h>
#include "item.h"

void item_exibir(item it) {
    printf("%d", it);
}

int item_comparar(item it1, item it2) {
    if(it1 > it2)
        return 1;
    else if(it1 < it2)
        return -1;
    else
        return 0;
}