#include <stdio.h>
#include <stdlib.h>

typedef  struct  {
    int Chave;
    /*  outros  componentes  */
}  TipoItem;

typedef  struct  TipoCelula  *TipoApontador;
typedef  struct  TipoCelula  {
    TipoItem  Item;
    TipoApontador  Prox;
}  TipoCelula;

typedef  struct  {
    TipoApontador  Primeiro ,  Ultimo;
    int tam;
}  TipoLista ;

//======================================================

void  FLVazia( TipoLista  * Lista )
{ 	Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
    Lista->tam=0;
}

//=====================================================

int  Vazia( TipoLista  Lista )
{  return  ( Lista . Primeiro ==  Lista . Ultimo ) ;  }

//======================================================

void  Insere(TipoItem  x ,	TipoLista  * Lista )
{  	Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Ultimo->Prox ;
    Lista->Ultimo->Item  =  x;
    Lista->Ultimo->Prox  =  NULL;
    Lista->tam++;
}

//======================================================

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
    Lista->tam--;
}

//======================================================

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;
    }
    //printf("\nTamanho: %d\n", ML.tam);
}

//======================================================

// Verifica somente listas com mesma quantidade de itens.
void VerificaIguais (TipoLista lista1, TipoLista lista2)
{
    TipoApontador aux1, aux2;
    aux1= lista1.Primeiro;
    aux2= lista2.Primeiro;
    int j=0;

    if( Vazia(lista1) && Vazia(lista2))
    {
        printf("\nListas vazias..\n");
        return;
    }

    while ((aux1->Prox!=NULL) && (aux2->Prox!=NULL))
    {
        if(aux1->Item.Chave==aux2->Item.Chave)
        {
            j++;
        }
        aux1=aux1->Prox;
        aux2=aux2->Prox;
    }
    //printf("\nJ: %d\n", j);
    if ((j==lista1.tam) && (j==lista2.tam))
    {
        printf("\nSao iguais\n");
    }else
    {
        printf("\nDiferentes\n");
    }
}

//======================================================


int main()
{
    TipoLista lista1;
    TipoLista lista2;
    TipoItem item;
    FLVazia(&lista1);
    FLVazia(&lista2);

    item.Chave=1;
    Insere(item, &lista1);
    Insere(item, &lista2);
    item.Chave=2;
    Insere(item, &lista1);
    item.Chave=2;
    Insere(item, &lista2);
    item.Chave=3;
    Insere(item, &lista1);
    Insere(item, &lista2);
    item.Chave=4;
    Insere(item, &lista1);
    Insere(item, &lista2);


    printf("\nLista 1: \n");
    imprime(lista1);

    printf("\n_______________________________________________\n");

    printf("\nLista 2: \n");
    imprime(lista2);

    printf("\n_______________________________________________\n");

    VerificaIguais(lista1, lista2);

    printf("\n_______________________________________________\n");



    printf("\n_______________________________________________\n");


    return 0;
}
