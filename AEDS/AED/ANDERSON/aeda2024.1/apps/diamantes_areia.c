/**
 * @file diamantes_areia.c
 * 
 * Diamantes e areia
 * Enunciado disponível em: https://www.beecrowd.com.br/repository/UOJ_1069.html
 * 
 * Proposta de solução na linguagem C
 * 
 * Para executar, proceda conforme a seguir:
 * Compilação: gcc diamantes_areia.c ../ed/pilha_e.c
 * Execução: ./a.exe (Windows) e ./a.out (Linux)
 * 
 * Para submeter ao juiz online é necessário agrudar os códigos em um único arquivo.
 * 
 * Utiliza uma pilha para implementar a solução.
 * @see '../ed/pilha_e.h'
 * 
 * @author: Anderson Grandi Pires (agpires@cefetmg.br)
 */

#include <stdio.h>
#include "../ed/pilha_e.h"

int main() {
    pilha *p = pilha_criar();
    if(p == NULL)
        return 0;

    int n;
    scanf("%d", &n);

    char entrada[1001], c;
    int pos, cont;
    for(int i = 1; i <= n; i++) {
        scanf("%s", entrada);
        pos = cont = 0;
        while((c = entrada[pos]) != '\0') {
            if(c == '<') {
                pilha_inserir(p, c);
            } else if(c == '>') {
                if(!pilha_vazia(p)) {
                    pilha_remover(p);
                    cont++;
                }
            }
            pos++;
        }

        while(!pilha_vazia(p))
            pilha_remover(p);

        printf("%d\n", cont);
    }

    pilha_liberar(p);

    return 0;
}