#include <stdio.h>
#include <stdlib.h>

typedef  struct  {
    int Chave;
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

void  FLVazia( TipoLista  *Lista )
{ 	Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
    Lista->tam=0;
}

int  Vazia( TipoLista  Lista )
{  return  ( Lista . Primeiro ==  Lista . Ultimo ) ;  }

void  Insere(TipoItem  x ,	TipoLista  *Lista )
{  	Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Ultimo->Prox ;
    Lista->Ultimo->Item  =  x;
    Lista->Ultimo->Prox  =  NULL;
    Lista->tam++;
}

void Ordena (TipoLista *lista){
    TipoApontador aux=lista->Primeiro, q;
    int i;
    while (aux->Prox->Prox!=NULL)
    {
        for(i=0; i< lista->tam; i++)
        {
        if (aux->Prox->Item.Chave > aux->Prox->Prox->Item.Chave)
        {
            q=aux->Prox->Item.Chave;
            aux->Prox->Item.Chave= aux->Prox->Prox->Item.Chave;
            aux->Prox->Prox->Item.Chave=q;
            //imprime(*lista); para teste
            //printf("\n"); para teste
        }
        }

        aux=aux->Prox;
    }
}

void InsereOrdenado (TipoItem x, TipoLista *Lista){

    Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Ultimo->Prox ;
    Lista->Ultimo->Item  =  x;
    Lista->Ultimo->Prox  =  NULL;
    Lista->tam++;
    Ordena(&Lista);
}

void  Retira(TipoApontador  p,	TipoLista  *Lista ,  TipoItem  *Item)
{
    TipoApontador  q;
    if ( Vazia(*Lista )	||	p == NULL	||	p->Prox == NULL){
        printf ( "  Erro : Lista  vazia  ou  posicao  nao  existe \n" ) ;
    return ;
}
    q =  p->Prox;
    *Item  =  q->Item ;
    p->Prox  =  q->Prox ;
    if ( p->Prox == NULL )  Lista->Ultimo  = p;
    free (q);
    Lista->tam--;
}

void RetiraTodos (TipoLista *lista, TipoItem item){
    TipoApontador aux=lista->Primeiro;
    TipoItem itemaux;
     if ( Vazia(*lista )){
        printf ( "  Erro : Lista  vazia");
     }
     else{
        while (aux->Prox!=NULL)
        {
            if (aux->Prox->Item.Chave== item.Chave)
            {
                Retira(aux,lista, &itemaux);
                lista->tam--;
            }else
            {
               aux=aux->Prox;
            }
        }
     }

}

void imprime(TipoLista lista){
    int i=1;
    TipoApontador aux=lista.Primeiro->Prox;
    while(aux!=NULL){
        printf("Chave%d: %d\n",i, aux->Item.Chave);
        aux=aux->Prox;
        i++;
    }
}

int main()
{
    TipoLista lista;
    TipoItem item;

    FLVazia(&lista);

    item.Chave=3;
    InsereOrdenado(item,&lista);
    item.Chave=2;
    InsereOrdenado(item,&lista);
    item.Chave=4;
    InsereOrdenado(item,&lista);
    item.Chave=1;
    InsereOrdenado(item,&lista);


    imprime(lista);

    printf("____________________________________\n");

    item.Chave=2;
    RetiraTodos(&lista, item);
    imprime(lista);

    printf("____________________________________\n");

    Ordena(&lista);
    imprime(lista);



    return 0;
}
