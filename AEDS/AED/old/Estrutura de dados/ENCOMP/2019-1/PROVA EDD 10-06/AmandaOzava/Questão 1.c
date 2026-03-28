#include <stdio.h>
#include <stdlib.h>
typedef  int  TipoChave;
typedef  struct  {
    TipoChave Chave;
    /*  outros  componentes  */
}  TipoItem;
typedef  struct  TipoCelula  *TipoApontador;
typedef  struct  TipoCelula  {
    TipoItem  Item;
    TipoApontador  Prox, Ant;
}  TipoCelula;

typedef  struct  {
    TipoApontador  Primeiro ,  Ultimo;
    int tamanho;
}  TipoLista ;

void  FLVazia( TipoLista  * Lista )
{ 	Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
    Lista->Primeiro->Ant  =  NULL;
    Lista->tamanho=0;
}

int  Vazia( TipoLista  Lista)
{
    return  (Lista.tamanho==0);
}

void  Insere(TipoItem  x ,	TipoLista  * Lista )
{
    if(Vazia(*Lista))
    {
        Lista->Primeiro->Item=x;
    }
    else
    {
        Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
        TipoApontador aux=Lista->Ultimo;
        Lista->Ultimo  =  Lista->Ultimo->Prox ;
        Lista->Ultimo->Item  =  x;
        Lista->Ultimo->Prox=  NULL;
        Lista->Ultimo->Ant= aux;
    }
    Lista->tamanho++;

}

void  Retira(TipoApontador  p,	TipoLista  *lista ,  TipoItem  *item)
{
    if(Vazia(*lista))
        return;
    else if(p==NULL)
        return;
    else if(p->Prox==NULL)
    {
        lista->Ultimo=p->Ant;
        p->Ant->Prox=NULL;
        free(p);
    }
    else if(p->Ant==NULL)
    {
        lista->Primeiro=p->Prox;
        p->Prox->Ant=NULL;
        free (p);
    }
    else
    {
        p->Ant->Prox=p->Prox;
        p->Prox->Ant=p->Ant;
        free(p);
    }
    lista->tamanho--;

}

void imprime(TipoLista lista){
    TipoApontador aux = lista.Primeiro;
    while(aux!=NULL)
    {
        printf("%d \t", aux->Item.Chave);
        aux=aux->Prox;
    }
    printf("\ntamanho da lista: %d\n", lista.tamanho);
}

int main()
{
    TipoLista lista;
    TipoItem item;
    FLVazia(&lista);
    item.Chave=1;
    Insere(item,&lista);
    item.Chave=2;
    Insere(item,&lista);
    item.Chave=6;
    Insere(item,&lista);
    item.Chave=5;
    Insere(item,&lista);
    item.Chave=4;
    Insere(item,&lista);
    imprime(lista);
    Retira(lista.Primeiro->Prox->Prox->Prox->Prox->Prox, &lista, &item);
    imprime(lista);
    return 0;
}
