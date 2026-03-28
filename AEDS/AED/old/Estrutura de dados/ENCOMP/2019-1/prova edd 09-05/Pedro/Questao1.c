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

void RetiraTodos(TipoLista *Lista, TipoItem Item){

    TipoApontador aux = Lista->Primeiro;
    TipoApontador aux2;
    TipoItem item;
    printf("A\n");
    while(aux!=NULL){
        if(aux->Item.Chave == Item.Chave){
            Retira(aux2,Lista,&item);
            //printf("%d\n",aux->Item.Chave);
        }
        aux=aux->Prox;
    }


}

void InsereOrdenado(TipoItem x, TipoLista *Lista){

    TipoApontador aux = Lista->Primeiro->Prox;

    while(aux!=NULL){



        aux=aux->Prox;
    }

}

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;
    }
}

int main()
{
    int i;
    TipoLista ML;

    FLVazia(&ML);

    TipoItem coisa1,coisa2,coisa3,coisa4;

    coisa1.Chave = 1;
    coisa2.Chave = 2;
    coisa3.Chave = 1;
    coisa4.Chave = 3;

    Insere(coisa1,&ML);
    Insere(coisa2,&ML);
    Insere(coisa3,&ML);
    Insere(coisa4,&ML);

    imprime(ML);

    RetiraTodos(&ML,coisa3);

    printf("\n");

    imprime(ML);




    return 0;
}
