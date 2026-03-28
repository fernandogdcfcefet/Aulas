#include <stdio.h>
#include <stdlib.h>

int main(){

    TipoPilha pilha1, pilha2, pilha3;

    TipoItem Item1; ///amarelo(maior)
    TipoItem Item2; ///vermelho(medio)
    TipoItem Item3; ///azul(menor)


    FPVazia(&pilha1);
    Vazia (pilha1);

    FPVazia(&pilha2);
    Vazia(pilha2);

    FPVazia(&pilha3);
    Vazia(pilha3);


    Empílha(Item1, &pilha1);
    Empilha(Item2, &pilha1);
    Empilha(Item3, &pilha1); ///comecouojogo

    ImprimePilha(pilha1); ///imprime o inicio do jogo na pilha 1 antes de modificar as pecas

    printf("  \n\n\n\n   -----------------------------------------------------------------   \n\n\n\n  ");

    Desempilha(&pilha1 , &Item3);
    Empilha (Item3 , &pilha3);

    Desempilha(&pilha1 , &Item2);
    Empilha( Item2 , &pilha2);

    Desempilha(&pilha3, &Item3);
    Empilha(Item3 , &pilha2);

    Desempilha(&pilha1, &Item1);
    Empilha(Item1 , &pilha3);

    Desempilha(&pilha2, &Item3);
    Empilha(Item3, &pilha1);

    Desempilha(&pilha2, &Item2);
    Empilha(Item2 , &pilha3);

    Desempilha(&pilha1 , &Item3);
    Empilha(Item3 , &pilha3);///terminouojogo

    ImprimePilha(pilha3); ///imprime o final do jogo na pilha 3 onde se encontra os 3 elementos empilhados


    return 0
}
