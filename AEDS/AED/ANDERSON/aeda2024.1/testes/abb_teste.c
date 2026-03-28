#include <stdio.h>
#include "../ed/abb.h"

void apresentacao(no *n);

int main() {
    /*
                    20
                 /     \
               5        30
             /   \     /  \
            1    15   25  40
                /           \
              9             45
            /   \         /
           7     12      42
    */
    int valores[] = {5, 1, 15, 9, 7, 12, 30, 25, 40, 45, 42},
      tam = sizeof(valores)/sizeof(int);
    no* raiz = abb_criar(20);
    for(int i = 1; i <= tam; i++)
      abb_inserir(raiz, valores[i-1]);

    apresentacao(raiz);

    raiz = abb_remover(raiz, 1);
    /*
                   20
                /      \
               5       30
                  \   /  \
                  15 25   40
               /             \
              9              45
           /     \         /
          7      12       42
    */
    apresentacao(raiz);

    raiz = abb_remover(raiz, 40);
    /*
                    20
                /       \
               5        30
                \      /  \
                15    25  45
                /        /   
               9        42    
            /     \        
           7      12      
    */
    apresentacao(raiz);

    raiz = abb_remover(raiz, 45);
    /*
                    20
                /       \
               5        30
                  \    /  \
                  15  25  42
                 /          
               9            
            /     \        
           7      12      
    */
    apresentacao(raiz);

    raiz = abb_remover(raiz, 9);
    /*
                    20
                /       \
               5        30
                  \    /  \
                  15  25  42
                /            
               12            
            /             
           7            
    */
    apresentacao(raiz);

    abb_liberar(raiz);

    return 0;
}

void apresentacao(no *n) {
  abb_profunidade(n);
    printf("\n");
    abb_largura(n);
    printf("\n\n");
}