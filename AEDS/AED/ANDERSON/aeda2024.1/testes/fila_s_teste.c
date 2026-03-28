/**
 * @file fila_s_teste.c
 * 
 * Aplicação para testes da estrutura fila (sequencial)
 * 
 * Para executar, proceda conforme a seguir:
 * Compilação: gcc fila_teste.c ../ed/fila_s.c ../ed/item.c
 * Execução: ./a.exe (Windows) e ./a.out (Linux)
 * 
 * Utiliza a estrutura de dados 'fila' como coleção e 'item' para
 * definir o tipo de dado da fila
 * @see ../ed/fila_s.h
 * @see ../ed/item.h
 * 
 * @author: Anderson Grandi Pires (agpires@cefetmg.br)
 */

#include <stdio.h>
#include "../ed/fila_s.h"

#define TAM 20

void apresentacao(fila *f) {
    printf("Fila vazia: %s\n", fila_vazia(f) ? "Sim" : "Nao");
    printf("Fila cheia: %s\n", fila_cheia(f) ? "Sim" : "Nao");
}

int main() {
    fila *f = fila_criar(TAM);
    if(f == NULL)
        return 0;
    else
        printf("ok\n");

    apresentacao(f);

    for(int i = 1; i <= TAM; i++) {
        fila_inserir(f, i);
    }
    apresentacao(f);

    while(!fila_vazia(f)) {
        item it = fila_frente(f);
        item_exibir(it);
        printf(" ");
        fila_remover(f);
    }
    printf("\n");
    apresentacao(f);

    f = fila_liberar(f);

    return 0;
}