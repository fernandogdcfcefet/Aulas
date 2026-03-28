/**
 * @file lista_s_teste.c
 * 
 * Aplicação para testes da estrutura lista sequencial
 * 
 * Para executar, proceda conforme a seguir:
 * Compilação: gcc lista_s_teste.c ../ed/lista_s.c ../ed/item.c
 * Execução: ./a.exe (Windows) e ./a.out (Linux)
 * 
 * Utiliza a estrutura de dados 'lista' como coleção e 'item' para
 * definir o tipo de dado da lista
 * @see ../ed/lista_s.h
 * @see ../ed/item.h
 * 
 * @author: Anderson Grandi Pires (agpires@cefetmg.br)
 */

#include <stdio.h>
#include "../ed/lista_s.h"

void apresentacao(lista* l);

int main() {
    lista *l1 = lista_criar(50);
    if(l1 == NULL)
        return 0;
    apresentacao(l1);

    for(int i = 1; i <= 10; i++)
        if(!lista_inserir(l1, 1, i))
            printf("item %d NAO inserido\n", i);
    apresentacao(l1);

    for(int i = 1; i <= 10; i++)
        if(!lista_inserir(l1, lista_tamanho(l1)+1, -i))
            printf("item %d NAO inserido\n", -i);
    apresentacao(l1);

    for(int i = 101; i <= 105; i++)
        if(!lista_inserir(l1, 5, i))
            printf("item %d NAO inserido\n", i);
    apresentacao(l1);

    while(!lista_vazia(l1)) {
        //lista_remover(l1, 1);
        lista_remover(l1, lista_tamanho(l1));
        printf("Lista: ");
        lista_exibir(l1);
        printf("\n");
    }
    apresentacao(l1);

    l1 = lista_liberar(l1);

    return 0;
}

void apresentacao(lista* l) {
    printf("\nVazia? %s", lista_vazia(l) ? "Sim\n" : "Nao\n");
    printf("Cheia? %s", lista_cheia(l) ? "Sim\n" : "Nao\n");
    printf("Tamanho: %d\n", lista_tamanho(l));
    printf("Capacidade: %d\n", lista_capacidade(l));
    printf("Lista: ");
    lista_exibir(l);
    printf("\n");
}