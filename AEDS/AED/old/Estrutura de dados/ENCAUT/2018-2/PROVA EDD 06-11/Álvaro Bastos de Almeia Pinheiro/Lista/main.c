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
    int tamanho;
}  TipoLista ;

void  FLVazia( TipoLista  * Lista )
{ 	Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
    Lista->tamanho=0;
}

int  Vazia( TipoLista  Lista )
{  return  ( Lista . Primeiro ==  Lista . Ultimo ) ;  }

void  Insere(TipoItem  x ,	TipoLista  * Lista )
{  	Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Ultimo->Prox ;
    Lista->Ultimo->Item  =  x;
    Lista->Ultimo->Prox  =  NULL;
    Lista->tamanho++;
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
    Lista->tamanho--;
}

void RetiraTodos(TipoLista *Lista,TipoItem Item){
    TipoApontador aux=Lista->Primeiro;
    TipoItem a;
    while(aux!=NULL){
        if(aux->Prox!=NULL&&aux->Prox->Item.Chave==Item.Chave){
                Retira(aux,Lista,&a);
        }
        else{
        aux=aux->Prox;}
    }
}

void InsereOrdenado(TipoItem x,TipoLista *Lista){
    TipoApontador aux=Lista->Primeiro->Prox;
    int t = Lista->tamanho+1;
    int k =0;
    TipoItem b,a[t];
    while(aux!=NULL){
        a[k]=aux->Item;
        k++;
        aux=aux->Prox;
    }
    a[t-1]=x;
    for(int i = 0;i<t;i++){
        for(int j = i ; j<t;j++){
            if(a[i].Chave>a[j].Chave){
                            b=a[i];
            a[i]=a[j];
            a[j]=b;
            }
        }
    }
    FLVazia(Lista);
    for(int m=0;m<t;m++){
        Insere(a[m],Lista);
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
}
