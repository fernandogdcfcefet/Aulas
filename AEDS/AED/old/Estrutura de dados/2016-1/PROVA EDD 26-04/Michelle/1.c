#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef int TipoChave;

typedef struct{
    TipoChave Chave;
}TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula{
    TipoItem Item;
    TipoApontador Prox;
}TipoCelula;

typedef struct{
    TipoApontador Primeiro, Ultimo;
}TipoLista;

void FLVazia(TipoLista *Lista){
    Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista){
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista){
    Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
}

void Retira(TipoApontador p, TipoLista *Lista){
    TipoApontador q;

    if(Vazia(*Lista) || p==NULL || p->Prox ==NULL){
        printf("Erro: Lista vazia ou posicao nao exite\n");
        return;
    }
    q = p->Prox;
    p->Prox = q->Prox;

    if(p->Prox==NULL){
        Lista->Ultimo = p;
        free(q);
    }
}


void ImprimeLista(TipoLista Lista){
    TipoApontador aux;
    aux = Lista.Primeiro->Prox;

    while(aux!=NULL){
        printf("%d ", aux->Item.Chave);
        aux = aux->Prox;
    }

}

void RetiraTodos(TipoLista *Lista, TipoItem Item){
    TipoApontador aux;
    aux = Lista->Primeiro;

    while(aux!=NULL){
            if(aux->Item.Chave == Item.Chave){
               Retira(aux, Lista);
               Lista->Ultimo--;
            }
        aux = aux->Prox;
    }
}

int main(){
    TipoItem x, y, z, w, k, comp;
    TipoLista ML;

    FLVazia(&ML);

    x.Chave = 1;
    y.Chave = 2;
    z.Chave = 3;
    w.Chave = 4;
    k.Chave = 5;
    comp.Chave = 1;

    Insere(x, &ML);
    Insere(y, &ML);
    Insere(z, &ML);
    Insere(w, &ML);
    Insere(k, &ML);

    ImprimeLista(ML);
    RetiraTodos(&ML, comp);
    printf("\n\n");
    ImprimeLista(ML);


    getch();
    return 0;
}
