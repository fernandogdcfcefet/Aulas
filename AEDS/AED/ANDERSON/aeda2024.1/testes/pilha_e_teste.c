/**
 * @file pilha_e_teste.c
 * 
 * Aplicação para testes da estrutura pilha (encadeada)
 * 
 * Para executar, proceda conforme a seguir:
 * Compilação: gcc pilha_e_teste.c ../ed/pilha_e.c ../ed/item.c
 * Execução: ./a.exe (Windows) e ./a.out (Linux)
 * 
 * Utiliza a estrutura de dados 'pilha' como coleção e 'item' para
 * definir o tipo de dado da pilha
 * @see ../ed/pilha_e.h
 * @see ../ed/item.h
 * 
 * @author: Anderson Grandi Pires (agpires@cefetmg.br)
 */

#include <stdio.h>
#include "../ed/pilha_e.h"

#define TAM 20

void apresentacao(pilha *p) {
    printf("pilha vazia: %s\n", pilha_vazia(p) ? "Sim" : "Nao");
}

int main() {
    pilha *p = pilha_criar(TAM);
    if(p == NULL)
        return 0;
    else
        printf("ok\n");

    apresentacao(p);

    printf("Inserido: ");
    for(int i = 1; i <= TAM; i++) {
        pilha_inserir(p, i);
        item_exibir(pilha_topo(p));
        printf(" ");
    }
    printf("\n");
    apresentacao(p);

    printf("Removido: ");
    while(!pilha_vazia(p)) {
        item it = pilha_topo(p);
        item_exibir(it);
        printf(" ");
        pilha_remover(p);
    }
    printf("\n");
    apresentacao(p);

    p = pilha_liberar(p);

    return 0;
}