#include <stdio.h>
#define TAM 5

/*typedef struct TAD_lista{
    int vet[TAM];
    int primeiro, ultimo;
}lista;

void inicializa(lista *l){
    l->primeiro=-1;
    l->ultimo=-1;
}

int listaVazia(lista *l){
    if((l->primeiro==-1)&&(l->ultimo==-1)){
        return 1;
    }else{
        return 0;
    }

}

void insere(int i, lista *l){
    if(listaVazia(l)){
        l->vet[0]=i;
        l->primeiro=0;
        l->ultimo=0;
    }else if(l->ultimo<TAM-1){
        l->vet[l->ultimo+1]=i;
        l->ultimo++;
    }else{
        puts("Lista cheia");
    }
}

void imprimeLista(lista *l){
    int i;
    if(listaVazia(l)){
        puts("Lista vazia");
    }else{
        for(i=l->primeiro;i<=l->ultimo;i++){
            printf("%d ",l->vet[i]);
        }
    }
}

int main()
{
    lista minhaLista;
    inicializa(&minhaLista);
    insere(7,&minhaLista);
    insere(9,&minhaLista);
    insere(10,&minhaLista);
    insere(10,&minhaLista);
    insere(10,&minhaLista);
    insere(10,&minhaLista);
    imprimeLista(&minhaLista);

    return 0;
}
*/
