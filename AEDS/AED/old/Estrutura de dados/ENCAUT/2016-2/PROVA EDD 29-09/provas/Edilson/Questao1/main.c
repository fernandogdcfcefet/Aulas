#include <stdio.h>
#include <stdlib.h>

typedef  int  TipoChave;

typedef  struct  { TipoChave Chave;
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

void  FLVazia( TipoLista   *Lista )
{
    Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
}

int  Vazia( TipoLista  Lista )
{
    return  ( Lista . Primeiro ==  Lista . Ultimo ) ;
}

void  Insere(TipoItem  x ,	TipoLista  * Lista )
{
    Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Ultimo->Prox ;
    Lista->Ultimo->Item  =  x;
    Lista->Ultimo->Prox  =  NULL;
}
void  Retira(TipoApontador  p,	TipoLista  *Lista ,  TipoItem  *Item)
{	/*--O item  a  ser  retirado  e  o  seguinte  ao  apontado  por  p--*/
    TipoApontador  q;
    if	( Vazia(*Lista )	||	p == NULL	||	p->Prox == NULL){
        printf ( "  Erro :	Lista  vazia  ou  posicao  nao  existe \n" ) ;
        return ;
    }
    q =  p->Prox;  *
    Item  =  q->Item ;
    p->Prox  =  q->Prox ;
    if	( p->Prox == NULL )
        Lista->Ultimo  = p;
    free (q);
}
void  Imprime( TipoLista  Lista )
{
    TipoApontador  Aux;
    Aux =  Lista . Primeiro->Prox ;
    while  (Aux  !=  NULL){
        printf ( "%d\n" ,  Aux->Item .Chave) ;
        Aux = Aux->Prox ;
    }
}

void RetiraTodos(TipoLista *lista, TipoItem x){
    TipoApontador  aux, p;
    TipoItem a;
    aux =  lista->Primeiro;
    while  (aux->Prox  !=  NULL){
        if (aux->Prox->Item.Chave == x.Chave){
            Retira(aux, lista, &a);
        }
        aux = aux->Prox ;
    }
}

int main()
{
    TipoLista lista;
    TipoItem itemA;
    FLVazia(&lista);
    int i;
    for (i=0; i<5; i++){
        itemA.Chave=i+1;
        Insere(itemA, &lista);
    }
    for (i=0; i<5; i++){
        itemA.Chave=i+1;
        Insere(itemA, &lista);
    }
    Imprime(lista);
    puts("\n");

    itemA.Chave=3;

    RetiraTodos(&lista, itemA);
    Imprime(lista);
    return 0;
}
