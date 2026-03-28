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

void RetiraTodos(TipoLista *Lista, TipoItem Item){
    TipoApontador p = Lista->Primeiro->Prox;
    TipoItem aux;
    while(p!=NULL){
        if(p->Item.Chave==Item.Chave){
            Retira(p, Lista, &aux);
        }
        p=p->Prox;
    }
}

void InsereOrdenado(TipoItem x, TipoLista *Lista){
    TipoApontador p,aux;
    p = Lista->Primeiro->Prox;
    if(p==NULL){
        Insere(x, Lista);
        return;
    }
    else{
        while(p!=NULL){
            if(x.Chave<=p->Prox->Item.Chave){
                aux = (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
                aux->Prox=p->Prox;
                return;
            }
            p=p->Prox;
        }
    }
}

int main()
{
    TipoLista ML;
    FLVazia(&ML);
    TipoItem a;
    a.Chave=5;
    InsereOrdenado(a,&ML);

    a.Chave=3;
    InsereOrdenado(a,&ML);
    a.Chave=1;
    InsereOrdenado(a,&ML);
    a.Chave=2;
    InsereOrdenado(a,&ML);
    InsereOrdenado(a,&ML);
    imprime(ML);
    printf("\n\n");
    RetiraTodos(&ML,a);
    imprime(ML);
    return 0;
}
