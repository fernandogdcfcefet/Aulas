#include <stdio.h>
#include <stdlib.h>
typedef  int  TipoChave;
typedef  struct  {
    TipoChave Chave;
    /*  Outros  componentes  */
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
    q =  p->Prox;
    *Item  =  q->Item ;
    p->Prox  =  q->Prox ;
    if ( p->Prox == NULL )  Lista->Ultimo  = p;
    free (q);
}

void RetiraTodos(TipoLista *Lista, TipoItem Item)
{
    TipoApontador aux=Lista->Primeiro;
    while(aux!=NULL)
    {
        if(aux->Item.Chave==Item.Chave)
        {
            Retira(aux,Lista,&Item);
        }
        else
            aux=aux->Prox;
    }

}
int tamLista(TipoLista lista)
{
    int cont=0;
    TipoApontador aux=lista.Primeiro->Prox;
    while(aux!=NULL)
    {
        cont++;
        aux=aux->Prox;
    }
    return cont;
}
void troca (TipoApontador *a, TipoApontador *b)
{
    TipoApontador aux=*a;
    *a=*b;
    *b=aux;
}
void OrdenaLista(TipoLista *Lista)
{
    TipoApontador aux,aux2,AUX;
    int i,j;
    aux=Lista->Primeiro;
    for(i=0;i<tamLista(*Lista);i++)
    {
        aux2=Lista->Primeiro->Prox;
        for(j=i;j<tamLista(*Lista);j++)
        {
            if(aux->Item.Chave<aux2->Item.Chave)
            {
                troca(&aux,&aux2);
            }
        }
    }
}
void insereOrdenado(TipoItem x, TipoLista *Lista)
{
    Insere(x,Lista);
    OrdenaLista(Lista);
}
void imprime(TipoLista ML)
{
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
    TipoItem x;
    for(i=0;i<10;i++)
    {
        x.Chave=rand()%10;
        insereOrdenado(x,&ML);
    }
    imprime(ML);
    return 0;
}
