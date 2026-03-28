#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 5

typedef int apontador;


typedef struct{

 int chave;

} funcionario;

typedef struct {

    funcionario f1 [MAXTAM];
    apontador frente, tras;

} fila;

void FFVazia (fila *fila){

    fila->frente = 1;
    fila->tras = fila->frente;

}

int Vazia( fila fila){

    return (fila.frente == fila.tras);
}

void desenfileira( fila *fila , funcionario *f1){

    if (Vazia(*fila)){

        printf("Erro: A fila esta vazia \n");

    }
    else{

        *f1 = fila->f1[fila->frente - 1];
        fila->frente = fila->frente + 1;
    }

}
void enfileira( funcionario x, fila *fila){

    if(fila->tras % MAXTAM  == fila->frente){

        printf("a fila esta cheia!!! \n\n");

    }
    else{

        fila->f1[fila->tras] = x;
        fila->tras = fila->tras % MAXTAM;
    }

}

void Imprime(fila fila){

int i;

    for(i = fila->frente - 1 ; i < fila->tras - 2 ; i ++){

        printf(" %d \n\n\n " , fila->f1[i].chave);

    }

}


int main(){

    fila fila1;

    funcionario F1 = {1};
    funcionario F2 = {2};
    funcionario F3 = {3};
    funcionario F4 = {4};
    funcionario F5 = {5};

    FFVazia(&fila1);
    Vazia(fila1);

    enfileira(F1, &fila1);
    enfileira(F2, &fila1);
    enfileira(F3, &fila1);
    enfileira(F4, &fila1);
    enfileira(F5, &fila1);

    Imprime(fila1);

    printf(" \n\n\n\n\n ------------------------------------------------------ \n\n\n\n\n");


return 0
}
