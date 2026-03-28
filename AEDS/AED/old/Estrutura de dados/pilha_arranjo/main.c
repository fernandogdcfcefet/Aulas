#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct{
    int vet[TAM];
    int topo;
}pilha;

void inicializa(pilha *minhaPilha){//FLVazia
    minhaPilha->topo=0;
}

//int isVazia(pilha minhaPilha){
//    return (minhaPilha.topo==0);
//}

int isVazia(pilha *minhaPilha){
    return (minhaPilha->topo==0);
}

void empilha(pilha *minhaPilha,int x){
    if(minhaPilha->topo==TAM){
        puts("A pilha ja esta cheia!");
    }else{
        minhaPilha->vet[minhaPilha->topo]=x;
        minhaPilha->topo++;
    }
}

void imprimePilha(pilha *minhaPilha){
    int i;
    for(i=minhaPilha->topo-1;i>=0;i--){
        printf("%d\n",minhaPilha->vet[i]);
    }
}

void desempilha(pilha *minhaPilha, int *x){
    if(isVazia(minhaPilha)){
        puts("Pilha ja esta vazia");
    }else{
        *x=minhaPilha->vet[minhaPilha->topo-1];
        minhaPilha->topo--;
    }

}
void inicializaFila(pilha *pilhaA,pilha *pilhaB){
        inicializa(pilhaA);
        inicializa(pilhaB);
}

void enfilera(pilha *pilhaA,pilha *pilhaB, int x){
    empilha(pilhaA,x);
}

void desenfilera(pilha *pilhaA,pilha *pilhaB, int *x){
    int a;
    while(!isVazia(pilhaA)){
        desempilha(pilhaA,&a);
        empilha(pilhaB,a);
    }
    desempilha(pilhaB,x);

    while(!isVazia(pilhaB)){
        desempilha(pilhaB,&a);
        empilha(pilhaA,a);
    }
//    puts("pilha A");
//    imprimePilha(pilhaA);
//    puts("pilha B");
//    imprimePilha(pilhaB);

}

int main()
{
    pilha pilha1,pilha2;
    int x;
    inicializaFila(&pilha1,&pilha2);
    enfilera(&pilha1,&pilha2,1);
    enfilera(&pilha1,&pilha2,2);
    enfilera(&pilha1,&pilha2,3);
    desenfilera(&pilha1,&pilha2,&x);
////    desempilha(&mp);
//    empilha(&mp,0);
//    empilha(&mp,1);
//    empilha(&mp,2);
//    imprimePilha(&mp);
//    desempilha(&mp,&x);
//    desempilha(&mp,&x);
//    printf("Desempilhou %d\n",x);
////    empilha(&mp,3);
////    empilha(&mp,4);
////    empilha(&mp,5);
//    imprimePilha(&mp);

    return 0;
}
