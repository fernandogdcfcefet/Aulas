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
{ // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  o item a ser retirado é o item apontador por p <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    TipoApontador  aux;
    int cont;
    if ( Vazia(*Lista )	||	p == NULL){
        printf ( "  Erro : Lista  vazia  ou  posicao  nao  existe \n" ) ;
    return ;
}
    aux=Lista->Primeiro;
    for(int cont=0; aux->Prox != NULL; cont++) {aux=aux->Prox; cont++;}
    aux=Lista->Primeiro->Prox;
    while(aux->Prox != p) aux=aux->Prox;
    *Item  =  p->Item ;
    aux->Prox  =  p->Prox ;
    if ( p->Prox == NULL )  Lista->Ultimo  = aux;
    free (aux);
}

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;
    }
}

void RetiraTodos (TipoLista *Lista, TipoItem Item)
{
    TipoApontador aux=Lista->Primeiro->Prox;
    TipoItem i;
    while(aux != NULL)
    {
        if(aux->Item.Chave==Item.Chave) Retira(aux, Lista, &i);
        aux=aux->Prox;
    }
}

void InsereOrdenado(TipoItem Item, TipoLista *Lista)
{
    TipoApontador aux=Lista->Primeiro->Prox;
    if(Vazia(*Lista)) Insere(Item, Lista);
    else
    {
        while(aux!=NULL)
        {
            if(aux->Item.Chave<Item.Chave && aux->Prox->Item.Chave>Item.Chave)
            {
                TipoApontador q=aux->Prox;
                aux->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) );
                aux->Prox->Item=Item;
                aux->Prox->Prox=q;
                free(q);
            }
            aux=aux->Prox;
        }
    }
}

int main()
{

    printf("\n\n");
    return 0;
}
