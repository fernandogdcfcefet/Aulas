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
    TipoApontador  Prox;
}  TipoCelula;

typedef  struct  {
    TipoApontador  Primeiro ,  Ultimo;
}  TipoLista ;

void  FLVazia( TipoLista  * Lista )
{ 	Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
}

int  Vazia( TipoLista  Lista )
{  return  ( Lista . Primeiro ==  Lista . Ultimo ) ;  }

void  Insere(TipoItem  x ,	TipoLista  * Lista )
{  	Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Ultimo->Prox ;
    Lista->Ultimo->Item  =  x;
    Lista->Ultimo->Prox  =  NULL;
}

void  Retira(TipoApontador  p,	TipoLista  *Lista ,  TipoItem  *Item)
{	/*--O item  a  ser  retirado  e  o  seguinte  ao  apontado  por  p--*/
    TipoApontador  q;
    if ( Vazia(*Lista )	||	p == NULL	||	p->Prox == NULL){
        printf ( "  Erro : Lista  vazia  ou  posicao  nao  existe \n" ) ;
    return ;
}
    q =  p->Prox;  *Item  =  q->Item ;
    p->Prox  =  q->Prox ;
    if ( p->Prox == NULL )  Lista->Ultimo  = p;
    free (q);
}

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;
    }
}

void RetiraTodos(TipoLista *lista, TipoItem item) {
    TipoItem itemAux;
    TipoApontador aux=lista->Primeiro;
    TipoApontador aux2;
    while(aux->Prox!=NULL){
        aux2=aux;

        if(aux2->Prox->Item.Chave==item.Chave) {
            printf("Deletar %d\n", aux2->Prox->Item.Chave);
            Retira(aux2, lista, &itemAux);
        }
        aux=aux->Prox;
    }
}

void InsereOrdenado(TipoItem x, TipoLista *lista) {
    TipoItem itemAux;
    TipoApontador aux=lista->Primeiro;


        while(aux->Prox->Item.Chave < x.Chave) {
            aux=aux->Prox;
        }
        itemAux = aux->Prox->Item;
        aux->Prox->Item.Chave = x.Chave;
        aux = aux->Prox;
        Insere(lista->Ultimo->Item, lista);

        // Empurrar os itens uma casa a frente
        while(aux->Prox->Prox!=NULL) {
            //itemAux = aux->Prox->Item;
            aux->Prox->Item = itemAux;
            itemAux = aux->Prox->Item;
            aux = aux->Prox;


        }

}

int main()
{
    TipoLista ML;
    FLVazia(&ML);
    TipoItem item;


    item.Chave = 1;
    Insere(item, &ML);
    item.Chave = 2;
    Insere(item, &ML);
    item.Chave = 3;
    Insere(item, &ML);
    item.Chave = 5;
    Insere(item, &ML);
    item.Chave = 6;
    Insere(item, &ML);
    item.Chave = 7;
    Insere(item, &ML);

    item.Chave = 4;
    InsereOrdenado(item, &ML);


    item.Chave = 2;
    //RetiraTodos(&ML, item);
    imprime(ML);

    return 0;
}
