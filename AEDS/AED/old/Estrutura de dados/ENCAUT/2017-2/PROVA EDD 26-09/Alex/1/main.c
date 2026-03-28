#include <stdio.h>
#include <stdlib.h>

typedef  int  TipoChave;
typedef  struct  {
    TipoChave Chave;
}TipoItem;
typedef struct  TipoCelula  *TipoApontador;
typedef struct  TipoCelula  {
    TipoItem  Item;
    TipoApontador Prox;
}TipoCelula;

typedef struct  {
    TipoApontador  Primeiro ,  Ultimo;
}TipoLista ;

void FLVazia( TipoLista  * Lista ){
    Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox = NULL;
}

int Vazia( TipoLista  Lista )
{  return  ( Lista.Primeiro == Lista.Ultimo); }

void Insere(TipoItem x , TipoLista * Lista )
{  	Lista->Ultimo->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox ;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
}

void Retira(TipoApontador  p,	TipoLista  *Lista,  TipoItem  *Item)
{
    TipoApontador  q;
    if (Vazia(*Lista ) || p == NULL|| p->Prox == NULL){
        printf ( " Erro : Lista  vazia  ou  posicao  nao  existe \n" ) ;
        return ;
    }
    q = p->Prox; *Item = q->Item ;
    p->Prox = q->Prox ;
    if (p->Prox == NULL) Lista->Ultimo = p;
    free (q);
}

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;
    }
}

void RetiraTodos(TipoLista *Lista, TipoItem Item){
    TipoApontador aux=Lista->Primeiro->Prox;
    while(aux!=NULL){
        if(aux->Item.Chave==Item.Chave){
            TipoItem x;
            //printf("-%d-\n",aux->Item.Chave);
            Retira(aux,Lista,&x);

        }
        aux=aux->Prox;
    }
}
void InsereOrdenado(TipoItem x, TipoLista *Lista){
    TipoApontador aux=Lista->Primeiro->Prox;
    while(aux!=NULL){
        if((x.Chave>aux->Item.Chave)&&(x.Chave<aux->Prox->Item.Chave)){
            TipoApontador y;
            y=(TipoApontador) malloc(sizeof(TipoCelula));
            y->Item=x;
            y->Prox=aux->Prox;
            aux->Prox=y;
        }
        aux=aux->Prox;

    }
}

int main()
{
    TipoLista Lista;
    FLVazia(&Lista);
    TipoItem item;
    item.Chave=1;
    Insere(item, &Lista);
    item.Chave=1;
    Insere(item, &Lista);
    item.Chave=3;
    Insere(item, &Lista);
    item.Chave=4;
    Insere(item, &Lista);
    imprime(Lista);
    printf("\n\n");
    item.Chave=2;
    InsereOrdenado(item,&Lista);
    item.Chave=1;
    RetiraTodos(&Lista, item);
    imprime(Lista);
    return 0;
}
