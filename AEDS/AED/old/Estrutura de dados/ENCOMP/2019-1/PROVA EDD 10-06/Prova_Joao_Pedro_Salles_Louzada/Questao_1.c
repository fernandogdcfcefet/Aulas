#include <stdio.h>
#include <stdlib.h>
typedef  int  TipoChave;
typedef  struct  {
    TipoChave Chave;
    /*  outros  componentes  */
}  TipoItem;
typedef  struct  TipoCelula  *TipoApontador;
typedef  struct  TipoCelula  {//-------------------------------------------------------------------------------------------------------------------------------------------
    TipoItem  Item;
    TipoApontador  Prox, Anterior; // Adicionando um apontador para o anterior alem do apontador para o proximo, podemos percorrer a lista tambem no sentido contrario.
}  TipoCelula;

typedef  struct  {
    TipoApontador  Primeiro ,  Ultimo;
}  TipoLista ;

void  FLVazia( TipoLista  * Lista )//--------------------------------------------------------------------------------------------------------------------------------------
{ 	Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
    Lista->Ultimo->Anterior = NULL; //Torna o Anterior Nulo
}

int  Vazia( TipoLista  Lista )
{  return  ( Lista . Primeiro ==  Lista . Ultimo ) ;  }

void  Insere(TipoItem  x ,	TipoLista  * Lista )//------------------------------------------------------------------------------------------------------------------------
{  	TipoApontador aux = Lista->Ultimo; // Guarda o apontador para o ultimo.
    Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Ultimo->Prox ;
    Lista->Ultimo->Anterior = aux; // Anterior da nova celula recebe o antigo ultimo.
    Lista->Ultimo->Item  =  x;
    Lista->Ultimo->Prox  =  NULL;
    free (aux); // Libera o auxiliar.
}

void  Retira(TipoApontador  p,	TipoLista  *Lista ,  TipoItem  *Item)//----------------------------------------------------------------------------------------------------
{	/*--O item  a  ser  retirado  e  o  seguinte  ao  apontado  por  p--*/
    TipoApontador  q;
    if ( Vazia(*Lista )	||	p == NULL	||	p->Prox == NULL){
        printf ( "  Erro : Lista  vazia  ou  posicao  nao  existe \n" ) ;
    return ;
}
    q =  p->Prox;
    *Item  =  q->Item ;
    p->Prox  =  q->Prox ;
    q->Prox->Anterior = q->Anterior; // Passa o apontador anterior para o novo anterior
    if ( p->Prox == NULL )
        Lista->Ultimo  = p;
    free (q);
}

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;
    }
}

int main()//---------------------------------------------------------------------------------------------------------------------------------------------------------------
{

    return 0;
}
