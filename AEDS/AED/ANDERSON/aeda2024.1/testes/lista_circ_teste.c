/**
 * @file lista_s_circ_teste.c
 * 
 * Aplicação para testes da estrutura lista sequencial circular
 * 
 * Para executar, proceda conforme a seguir:
 * Compilação: gcc lista_s_circ_teste.c ../ed/lista_s_circ.c ../ed/item.c
 * Execução: ./a.exe (Windows) e ./a.out (Linux)
 * 
 * Utiliza a estrutura de dados 'lista' como coleção e 'item' para
 * definir o tipo de dado da lista
 * @see ../ed/lista_s_circ.h
 * @see ../ed/item.h
 * 
 * @author: Anderson Grandi Pires (agpires@cefetmg.br)
 */

#include <stdlib.h>
#include <stdio.h>
#include "../ed/lista_s_circ.h"

void info(lista *l) {
    printf("\nl1 esta vazia? %s", (lista_vazia(l) ? "Sim" : "Nao") );
    printf("\nl1 esta cheia? %s", (lista_cheia(l) ? "Sim" : "Nao") );
    printf("\nTamanho de l1: %d", lista_tamanho(l));
    printf("\nCapacidade de l1: %d\n", lista_capacidade(l));
}

int main() {
    lista *l1 = lista_criar(5);
    info(l1);

    lista *l2 = lista_criar(10);
    info(l2);
    
    int i;
    for(i = 5; i >= 0; i--) {
        if(lista_inserir(l1, i))
            printf("\ninsercao do valor %d com sucesso", i);
        else
            printf("\nvalor %d nao inserido", i);
        printf(" - tamanho: %d", lista_tamanho(l1));
    }
    printf("\n");
    info(l1);
    
    printf("\n\nl1: "); lista_exibir(l1); printf("\n");

    int valor_removido;
    for(i = 1; i <= 2; i++) {
        if(lista_remover(l1, &valor_removido))
            printf("\nremocao efetuada com sucesso - valor removido: %d", valor_removido);
        else
            printf("\nremocao nao efetuada");
        printf(" - tamanho: %d", lista_tamanho(l1));
    }
    
    printf("\n\nl1: "); lista_exibir(l1); printf("\n");

    for(i = 10; i <= 30; i += 10) {
        if(lista_inserir(l1, i))
            printf("\ninsercao do valor %d com sucesso", i);
        else
            printf("\nvalor %d nao inserido", i);
        printf(" - tamanho: %d", lista_tamanho(l1));
    }

    printf("\n\nl1: "); lista_exibir(l1); printf("\n");
    
    if(lista_remover(l1, &valor_removido))
            printf("\nremocao efetuada com sucesso - valor removido: %d", valor_removido);
        else
            printf("\nremocao nao efetuada");
    printf(" - tamanho: %d", lista_tamanho(l1));
    
    printf("\n\nl1: "); lista_exibir(l1); printf("\n");

    for(i = 100; i <= 103; i++) {
        if(lista_inserir(l1, i))
            printf("\ninsercao do valor %d com sucesso", i);
        else
            printf("\nvalor %d nao inserido", i);
        printf(" - tamanho: %d", lista_tamanho(l1));
    }

    printf("\n\nl1: "); lista_exibir(l1); printf("\n\n");

    int b = 6;
    int sinal = (b >= 0 ? 1 : -1); // 1 (não negativo) ou -1 (negativo)

    int valores[] = {102, 2, 1, 10, 20, 100},
        tam = sizeof(valores)/sizeof(int);
    for(int i = 0; i < tam; i++)
        printf("\nBuscar %d: %s\n", valores[i], (lista_buscar(l1, valores[i])) ? "OK" : ":(");

    l1 = lista_liberar(l1);

    return 0;
}