/**
 * @file jogando_cartas.c
 * 
 * Jogando cartas fora
 * Enunciado disponível em: https://www.beecrowd.com.br/repository/UOJ_1110.html
 * 
 * Proposta de solução na linguagem C
 * 
 * Para executar, proceda conforme a seguir:
 * Compilação: gcc jogando_cartas.c ../ed/fila_s.c
 * Execução: ./a.exe (Windows) e ./a.out (Linux)
 * 
 * Para submeter ao juiz online é necessário agrudar os códigos em um único arquivo.
 * 
 * Utiliza uma fila para implementar a solução.
 * @see ../ed/fila_s.h
 * 
 * @author: Anderson Grandi Pires (agpires@cefetmg.br)
 */
#include <stdio.h>
#include "../ed/fila_s.h"

int main() {
    fila *f = fila_criar(50);
    if(f == NULL)
        return 0;
    
    int n;
    scanf("%d", &n);

    while(n != 0) {
        if(n == 1) {
            printf("Discarded cards:\n");
            printf("Remaining card: 1\n");
            scanf("%d", &n);
            continue;
        }

        for(int i = 1; i <= n; i++)
            fila_inserir(f, i);

        printf("Discarded cards: ");
        bool primeira = true;   // flag
        while(fila_tamanho(f) > 1) {
            if(primeira) {
                printf("%d", fila_frente(f));
                primeira = false;
            } else {
                printf(", %d", fila_frente(f));
            }
            fila_remover(f);
            fila_inserir(f, fila_frente(f));
            fila_remover(f);
        }
        printf("\nRemaining card: %d\n", fila_frente(f));
        fila_remover(f);

        scanf("%d", &n);
    }

    f = fila_liberar(f);

    return 0;
}