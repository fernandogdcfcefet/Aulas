#include <stdio.h>
#include <stdlib.h>
typedef struct celula *apontador;
typedef struct celula{
    int item;
    apontador prox;
}celula;

typedef struct{
    apontador frente, tras;
    int tam;
}fila;

void inicializa(fila *minhaFila){//FFVazia
    minhaFila->frente = (apontador)malloc(sizeof(celula));
    minhaFila->tras = minhaFila->frente;
    minhaFila->tras->prox = NULL;
    minhaFila->tam = 0;
}
void enfilera(fila *minhaFila, int x){
    minhaFila->tras->prox=(apontador)malloc(sizeof(celula));
    minhaFila->tras->item=x;
    minhaFila->tras=minhaFila->tras->prox;
    minhaFila->tam++;
    minhaFila->tras->prox=NULL;
}

void imprime(fila minhaFila){
    apontador aux = minhaFila.frente;
    while(aux->prox != NULL){
        printf("%d ",aux->item);
        aux = aux->prox;
    }
}
int isVazia(fila minhaFila){
    return ((minhaFila.frente==minhaFila.tras)&&(minhaFila.tam==0));
}

void desenfilera(fila *minhaFila, int * item){
    if(isVazia(*minhaFila)){
        printf("Fila vazia\n");
    }else{
        apontador q = minhaFila->frente;
        *item = minhaFila->frente->item;
        minhaFila->frente=minhaFila->frente->prox;

        free(q);
        minhaFila->tam--;
    }

}

int main()
{
    fila mf;
    int x;
    inicializa(&mf);
//    desenfilera(&mf);
//    enfilera(&mf,0);
//    enfilera(&mf,5);
//    enfilera(&mf,3);
//    desenfilera(&mf,&x);
//    desenfilera(&mf,&x);
//    printf("ultimo item desenfilerado %d",x);
    imprime(mf);
    return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAXTAM 5
//typedef struct{
//    int item[MAXTAM];
//    int frente, tras, tam;
//}fila;
//
//void inicializa(fila *minhaFila){//FPVazia
//    minhaFila->frente = 0;
//    minhaFila->tras = 0;
//    minhaFila->tam = 0;
//}
//
//int isVazia(fila minhaFila){
//    return((minhaFila.frente==minhaFila.tras)&&(minhaFila.tam==0));
//}
//
//void enfilera(fila *minhaFila, int x){
//    if(minhaFila->tam==MAXTAM){
//        printf("fila cheia");
//    }else{
//        minhaFila->item[minhaFila->tras]=x;
//        minhaFila->tras=(minhaFila->tras+1)%MAXTAM;
//        minhaFila->tam++;
//    }
//
//}
//void imprime(fila minhaFila){
//    int i;
//    for(i=minhaFila.frente;i<minhaFila.frente+minhaFila.tam;i++){
//        printf("%d ",minhaFila.item[i%MAXTAM]);
//    }
//}
//
//void desenfilera(fila *minhaFila, int *x){
//    if(isVazia(*minhaFila)){
//        printf("Fila vazia");
//    }else{
//        *x=minhaFila->item[minhaFila->frente];
//        minhaFila->frente=(minhaFila->frente+1)%MAXTAM;
//        minhaFila->tam--;
//    }
//}
//
////void desenfilera(fila *minhaFila){
////    if(isVazia(*minhaFila)){
////        printf("Fila vazia");
////    }else{
////        minhaFila->frente=(minhaFila->frente+1)%MAXTAM;
////        minhaFila->tam--;
////    }
////}
//int main()
//{
//    int x;
//    fila mf;
//    inicializa(&mf);
////    desemfilera(&mf,&x);
//    enfilera(&mf,5);
//    enfilera(&mf,7);
//    enfilera(&mf,8);
//    enfilera(&mf,9);
//    enfilera(&mf,10);
//    desenfilera(&mf,&x);
//    desenfilera(&mf,&x);
////    printf("desenfilerei o %d\n",x);
//    enfilera(&mf,4);
//    enfilera(&mf,3);
//    desenfilera(&mf,&x);
//    imprime(mf);
//    return 0;
//}

