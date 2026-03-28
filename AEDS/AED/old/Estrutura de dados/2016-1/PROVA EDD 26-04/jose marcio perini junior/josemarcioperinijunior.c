#include <stdio.h>
#include <stdlib.h>

typedef int chave;

typedef struct{

 int chave;

} funcionario;

typedef struct celula *apontador;

typedef struct celula {

    funcionario f1;
    apontador prox;

}celula;

typedef struct {

    apontador primeiro, ultimo;

} lista;

void FLVazia (lista *lista){

    lista->primeiro = (apontador) malloc( sizeof(celula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;


}

int Vazia( lista lista){

    return (lista.primeiro == lista.ultimo);
}

void Retira (apontador p, lista *lista , funcionario *f1){

    apontador q;

    if (Vazia(*lista) || p == NULL || p->prox == NULL){

        printf("Erro: A lista esta vazia ou posicao noa existe \n");
        return;
    }

q = p->prox;
*f1 = q->f1;
p->prox = q->prox;

if(p->prox == NULL){

    lista->ultimo = p;

}

free(q);
}

void imprimelista(lista lista){

apontador aux;

    while (aux != NULL){

    printf(" %d \n\n" , aux->f1.chave);

    }

}

void RetiraTodos (lista *lista , funcionario f1){

apontador aux = lista->primeiro->prox;

    while(aux != NULL){


        if( aux->f1.chave = f1){

            free(aux);
        }

    }

}

void InsereOrdenado(funcionario x , lista *lista){

    lista->ultimo->prox = (apontador)malloc(sizeof(celula));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->f1 = x;
    lista->ultimo->prox = NULL;


}


int main(){

    lista lista1;

    funcionario F1 = {1};
    funcionario F2 = {2};
    funcionario F3 = {3};
    funcionario F4 = {4};
    funcionario F5 = {5};

    FLVazia(&lista1);
    Vazia(lista1);

    InsereOrdenado(F1, &lista1);
    InsereOrdenado(F2, &lista1);
    InsereOrdenado(F3, &lista1);
    InsereOrdenado(F4, &lista1);
    InsereOrdenado(F5, &lista1);

    imprimelista(lista1);

    printf(" \n\n\n\n\n ------------------------------------------------------ \n\n\n\n\n");

    RetiraTodos(&lista1, F2);

    imprimelista(lista1);

return 0
}

