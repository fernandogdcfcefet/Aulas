#include <stdio.h>
#include <stdlib.h>

typedef int TipoChave;

typedef struct{
    TipoChave Chave;
}TipoItem;

typedef struct *TipoApontador;

typedef struct TipoCelula{
    TipoItem Item;
    TipoApontador Prox;
}TipoCelula;

typedef struct{
    TipoApontador Primeiro, Ultimo;;
}TipoLista;

void FLVazia(TipoLista *Lista){
    Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista){
    return(Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista){
    Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
}

void InserePOS(TipoItem x, TipoLista *Lista, int POS){
    //Lista->[Ultimo-POS]->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->[Ultimo-POS] = (TipoApontador)malloc(sizeof(TipoCelula)); //Lista->[Ultimo-POS]->Prox;
    Lista->[Ultimo-POS]->Item = x;
    Lista->[Ultimo-POS]->Prox = Lista->[Ultimo-POS+1];
}

void Retira(TipoApontador p; TipoLista *Lista, TipoItem *Item){
    TipoApontador q;
    if(Vazia(*Lista) || p==NULL || p->Prox==NULL){
        printf("Lista vazia ou posicao nao existe");
        return;
    }
    q = p->Prox;
    *Item = q->Item;
    p->Prox = q->Prox;
    if(p->Prox == NULL)
        Lista->Ultimo = p;
    free(q);
}

void RetiraTodos(TipoLista *Lista, TipoItem Item){
    int i = 0;
    while(Lista->[Ultimo+i]->Prox != NULL){
        if(Item == Lista->[Ultimo+i]->Item)
            Retira(*Lista->Ultimo->Prox, Lista, *Item);
        i++;
    }
}

void InsereOrdenado(TipoItem x, TipoLista *Lista){
    int i=0, y=0;
    for(i=0;i<Lista->Ultimo;i++){
        if(Lista->[Ultimo-i]->Item > x)
            y++;
    }
    InserePOS(x, Lista, y);
}
