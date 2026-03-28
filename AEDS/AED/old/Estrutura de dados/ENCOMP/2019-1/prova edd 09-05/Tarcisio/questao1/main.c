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
    q = p->Prox;  *Item=q->Item ;
    p->Prox=q->Prox ;
    if ( p->Prox == NULL )  Lista->Ultimo  = p;
    free (q);
}

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%d", aux->Item.Chave);
        aux=aux->Prox;
        printf("\n");
    }
}
void retiraTodos(TipoChave ch, TipoLista *lista, TipoItem *x)
{
    if(Vazia(*lista))
    {
        printf("A lista esta vazia.");
        return;
    }
    else
    {
        TipoApontador aux=lista->Primeiro;
        TipoApontador aux2=lista->Primeiro;
        while(aux!=NULL)
        {

                if(aux->Item.Chave==ch)
                {
                    Retira(aux, lista, x);
                }
            aux=aux->Prox;
        }
    }
}
void Ordenado(TipoItem *item, TipoLista *lista)
{
    TipoApontador aux=lista->Primeiro->Prox;
    TipoItem aux2;
    while(aux!=NULL){
        if(Vazia(*lista)||item->Chave > aux->Item.Chave )//comaparando item com item lista se for maior insere
        {
            Insere(*item,lista);
            aux=aux->Prox;
        }
        else
        {
            aux2=aux->Item;
            aux->Item=*item;
            *item=aux2;
            Insere(*item,lista);
        }

    }
}

int main()
{
    TipoLista lista;
    TipoItem item;
    TipoChave x;
    FLVazia(&lista);
        for(int i=0;i<10;i++)
        {
            item.Chave=rand()%10;
            Insere(item,&lista);
        }

    imprime(lista);

    x=8;
    retiraTodos(x, &lista, &item);
    imprime(lista);
    return 0;
}

