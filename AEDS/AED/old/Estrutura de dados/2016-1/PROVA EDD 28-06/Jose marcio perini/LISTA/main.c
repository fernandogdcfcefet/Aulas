#include <stdio.h>
#include <stdlib.h>

typedef  int  Chave;

typedef  struct  {

    Chave Chave;

} Item;

typedef  struct  Celula  *Apontador;

typedef  struct  Celula  {

    Item  Item;
    Apontador  Prox;

} Celula;

typedef  struct  {

    Apontador  Primeiro ,  Ultimo;

} Lista ;

void  FLVazia( Lista  * Lista )
{

    Lista->Primeiro  =  (Apontador)  malloc( sizeof ( Celula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;

}

int  Vazia( Lista  Lista )

{
    return  ( Lista . Primeiro ==  Lista . Ultimo ) ;

}

void  Insere(Item  x ,	Lista  * Lista )
{

    Lista->Ultimo->Prox  =  (Apontador)  malloc( sizeof ( Celula ) ) ;
    Lista->Ultimo  =  Lista->Ultimo->Prox ;
    Lista->Ultimo->Item  =  x;
    Lista->Ultimo->Prox  =  NULL;

}

void  Retira(Apontador  p, Lista  *Lista ,  Item  *Item)
{
    /*-- O item  a  ser  retirado  e  o  seguinte  ao  apontado  por  p --*/
    Apontador  q;

    if ( Vazia( *Lista )	||	p == NULL	||	p->Prox == NULL){

        printf ( "  Erro : Lista  vazia  ou  posicao  nao  existe \n" ) ;

    return ;
}

    q =  p->Prox;  *Item  =  q->Item ;
    p->Prox  =  q->Prox ;
    if ( p->Prox == NULL )  Lista->Ultimo  = p;
    free (q);

}

void imprime(Lista ML){

    Apontador aux = ML.Primeiro->Prox;

    while(aux != NULL){

        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;

    }
}

void Sort (Lista *ML){

Apontador aux;

for(aux->ML.Primeiro ; aux->NULL; aux->Prox){
    for(aux->ML.Ultimo ; aux->ML.Primeiro ; aux->prox){

        Troca(Apontador p , Lista *Lista);

    }
}
}


void Troca (Apontador p , Lista *Lista){

if (p->ML.item.chave > p->Prox->ML.item.chave){

    p = p->Prox->Prox;
    p->Prox = p->Prox->Prox->Prox;
    p->Prox->Prox = p->Prox;

}

}


int main()
{
    Lista ML;
    Lista Pilha;

    Item item;

    FLVazia(&ML);

    item.Chave = 1;
    Insere(item,&ML);

    item.Chave = 7;
    Insere(item,&ML);

    item.Chave = 13;
    Insere(item,&ML);

    item.Chave = 5;
    Insere(item,&ML);

    item.Chave = 9;
    Insere(item,&ML);

    Retira(ML.Primeiro->Prox, &ML , &item);

    imprime(ML);

    return 0;
}
