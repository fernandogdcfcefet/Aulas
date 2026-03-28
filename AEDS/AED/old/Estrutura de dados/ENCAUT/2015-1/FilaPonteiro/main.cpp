#include <stdio.h>
#include <stdlib.h>

typedef struct celula * ponteiro;

typedef struct celula{
    char item;
    ponteiro prox;
}celula;

typedef struct{
    ponteiro primeiro, ultimo;
    int tam;
}lista;

void esvazia(lista * ML){
    ML->primeiro = (ponteiro)malloc(sizeof(celula));
    ML->ultimo = ML->primeiro;
    ML->primeiro->prox = NULL;
    ML->tam = 0;
}

//int verificaVazia(lista * ML){
//    return (ML->primeiro==ML->ultimo);//ML->tam==0
//}

int verificaVazia(lista ML){
    return (ML.primeiro==ML.ultimo);//ML.tam==0
}

void insere(lista *ML, char c){
    ML->ultimo->prox = (ponteiro)malloc(sizeof(celula));
    ML->ultimo->item = c;
    ML->ultimo=ML->ultimo->prox;
    ML->ultimo->prox = NULL;
    ML->tam++;
}

void imprime(lista ML){
    int i;
    ponteiro aux = ML.primeiro;
    for(i=0;i<ML.tam;i++){
        printf("%c ",aux->item);
        aux=aux->prox;
    }
}

int main()
{
    lista minhaLista;
    esvazia(&minhaLista);
    printf("\t \n");
    insere(&minhaLista,'p');
    insere(&minhaLista,'a');
    insere(&minhaLista,'r');
    insere(&minhaLista,'a');
    insere(&minhaLista,'b');
    insere(&minhaLista,'e');
    insere(&minhaLista,'n');
    insere(&minhaLista,'s');
    printf("/t");
    insere(&minhaLista,'a');
    insere(&minhaLista,'l');
    insere(&minhaLista,'i');
    insere(&minhaLista,'c');
    insere(&minhaLista,'e');
    imprime(minhaLista);

    return 0;
}
