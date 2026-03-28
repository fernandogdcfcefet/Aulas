#include <stdio.h>
#include <string.h>

#define MAXTAM 10

typedef struct{
    char nome[100];
}doce;

typedef struct{
    doce vet[MAXTAM];
    int topo;
}pilha;

void esvazia(pilha *minhaPilha){
    minhaPilha->topo=0;
}

int verificaVazia(pilha minhaPilha){
    return (minhaPilha.topo==0);
}

void empilha(pilha *minhaPilha, doce d){
    if(minhaPilha->topo==MAXTAM)
        puts("Pilha cheia");
    else{
        minhaPilha->vet[minhaPilha->topo]=d;
        minhaPilha->topo++;
    }
}

void desempilha(pilha *minhaPilha){
    if(verificaVazia(*minhaPilha)){
        puts("Pilha vazia");
    }else{
        minhaPilha->topo--;
    }
}

void imprime(pilha minhaPilha){
//    int i;
//    for(i=minhaPilha.topo-1;i>=0;i--){
//        puts(minhaPilha.vet[i].nome);
//    }

    while(!verificaVazia(minhaPilha)){
        puts(minhaPilha.vet[minhaPilha.topo-1].nome);
        desempilha(&minhaPilha);
    }
}


int main()
{
    pilha MP;
    doce d;
    strcpy(d.nome,"chocolate");
    esvazia(&MP);
    empilha(&MP,d);
    strcpy(d.nome,"Brigadeiro");
    empilha(&MP,d);
    strcpy(d.nome,"KitKat");
    empilha(&MP,d);
    desempilha(&MP);
    strcpy(d.nome,"Chiclete");
    empilha(&MP,d);

    imprime(MP);
    return 0;
}
