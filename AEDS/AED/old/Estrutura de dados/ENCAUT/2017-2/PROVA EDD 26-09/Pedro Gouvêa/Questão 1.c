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
    printf("\n");
}

void RetiraTodos(TipoLista *Lista, TipoItem Item) {               // Letra A da questão 1
    TipoApontador i = Lista->Primeiro;
    while(i->Prox != NULL) {
        if(i->Prox->Item.Chave == Item.Chave)
            Retira(i, Lista, &Item);
        else
            i = i->Prox;
    }
}

void InsereOrdenado(TipoItem x, TipoLista *Lista) {                     // Letra B da questão 1
    TipoItem ItemAux;
    TipoApontador i = Lista->Primeiro;
    TipoLista ListaAux;
    FLVazia(&ListaAux);

    if(Vazia(*Lista))
        Insere(x, Lista);

    else {
        while(i->Prox != NULL) {
            Insere(x, Lista);
            if(i->Prox->Item.Chave > x.Chave) {
                ItemAux = Lista->Primeiro->Prox->Item;
                Lista->Primeiro->Prox->Item = Lista->Primeiro->Prox->Prox->Item;
                Lista->Primeiro->Prox->Prox->Item = ItemAux;
            }
            i = i->Prox;
        }
    }
}

int main() {
    TipoLista ML;
    FLVazia(&ML);
    TipoItem item;

    item.Chave = 1;
    Insere(item, &ML);
    item.Chave = 5;
    Insere(item, &ML);
    item.Chave = 1;
    Insere(item, &ML);
    item.Chave = 3;
    Insere(item, &ML);
    item.Chave = 4;
    Insere(item, &ML);



    item.Chave = 1;

    imprime(ML);

//    RetiraTodos(&ML, item);


    return 0;
}
