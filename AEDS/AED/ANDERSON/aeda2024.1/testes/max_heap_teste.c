/**
 * @file max_heap_teste.c
 * 
 * Aplicação para testes da estrutura max-heap
 * 
 * Para executar, proceda conforme a seguir:
 * Compilação: gcc max_heap_teste.c ../ed/max_heap.c ../ed/item.c
 * Execução: ./a.exe (Windows) e ./a.out (Linux)
 * 
 * Utiliza a estrutura de dados 'max-heap' como coleção e 'item' para
 * definir o tipo de dado da max-heap
 * @see ../ed/max_heap.h
 * @see ../ed/item.h
 * 
 * @author: Anderson Grandi Pires (agpires@cefetmg.br)
 */

#include <stdio.h>
#include <stdlib.h>
#include "../ed/max_heap.h"

int main() {
    printf("------ TESTE BASICO ------\n");

    heap* h1 = heap_criar(20);
    if(h1 == NULL)
        exit(EXIT_FAILURE);

    printf("> Inserir elementos\n");
    int i;
    for(i = 1; i <= 20; i++) {
        if(heap_inserir(h1, i))
            printf("\nInsercao de %d com sucesso", i);
        else
            printf("Valor %d nao inserido", i);
        
        heap_exibir(h1);
        printf("\n");
    }
    
    printf("> Remover todos os elementos\n");
    while(!heap_vazia(h1)) {
        printf("%d ", heap_remover(h1));
    }
    printf("\n");
    heap_liberar(&h1);

    printf("\n\n>>>> INSERIR os elementos de um vetor \n");
    int vetor[] = {50, 29, 33, 21, 11, 78, 66, 99},
        tam = sizeof(vetor)/sizeof(int);
    for(int i = 0; i < tam; i++)
        printf("%d ", vetor[i]);
    printf("\n");

    heap* h2 = heap_criar(20);
    if(h2 == NULL)
        exit(EXIT_FAILURE);
    
    heap_inserir_vetor(h2, vetor, tam);
    heap_exibir(h2);
    printf("\n");

    printf("\n> REMOVER\n");
    int r;
    while(!heap_vazia(h2)) {
        r = heap_remover(h2);
        if(r != -1)
            printf("\nRemocao efetuada com sucesso. Valor removido: %d.", r);
        else
            printf("\nRemocao nao efetuada.");
        heap_exibir(h2);
        printf("\n");
    }

    heap_liberar(&h2);

    return 0;
}
