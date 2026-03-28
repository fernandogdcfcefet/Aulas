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
    TipoApontador  Prox, Ante;
}  TipoCelula;

typedef  struct  {
    TipoApontador  Primeiro ,  Ultimo;
}  TipoLista ;

void  FLVazia( TipoLista  * Lista )
{ 	Lista->Primeiro = (TipoApontador)  malloc(sizeof (TipoCelula));
    Lista->Ultimo=Lista->Primeiro ;
    Lista->Primeiro->Ante=NULL;
    Lista->Primeiro->Prox=NULL;
}

int  Vazia( TipoLista  Lista )
{  return  ( Lista . Primeiro ==  Lista . Ultimo ); }

void  Insere(TipoItem  x ,	TipoLista  *Lista )
{  	Lista->Ultimo->Prox =(TipoApontador) malloc( sizeof(TipoCelula));
    Lista->Ultimo->Ante=Lista->Ultimo;
    Lista->Ultimo=Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
}

void  Retira(TipoApontador  p,	TipoLista  *Lista ,  TipoItem  *Item)
{	/*--O item  a  ser  retirado  e  o  seguinte  ao  apontado  por  p--*/
    TipoApontador  q, t;
    if ( Vazia(*Lista )	||	p == NULL	||	p->Prox == NULL){
        printf ( "  Erro : Lista  vazia  ou  posicao  nao  existe \n" ) ;
    return ;
}
    q = p->Prox;
    t=p->Ante;
    *Item = q->Item;
    p->Prox = q->Prox ;
    p->Ante=t->Ante;
    if(p->Prox == NULL )  Lista->Ultimo =p;
    free (q);
    free(t);
}

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;
    }
}

void imprimeAnte(TipoLista ML)
{
    TipoApontador aux=ML.Ultimo;
    while(aux!=NULL){
        printf("%d\n", aux->Item.Chave);
        aux=aux->Ante;
    }
}

int main()
{
    TipoLista ML;
    TipoItem coisa;
    FLVazia(&ML);
    int i;
    for(i=0; i<3; i++)
    {
        coisa.Chave=rand()%10;
        Insere(coisa, &ML);
    }

    imprime(ML);
    //imprimeAnte(ML);

    return 0;
}
