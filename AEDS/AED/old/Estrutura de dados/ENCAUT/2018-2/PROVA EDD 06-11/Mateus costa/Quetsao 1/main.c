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
    Lista->tamanho++;
}

void Imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;
    }
}
void RetiraTodos(TipoLista *Lista,TipoItem Item){
TipoApontador aux=0,pos=0,cont=0;
FLVazia(&aux);
aux=Lista->Primeiro->Prox;

int i=0;
TipoItem Itemaux;
Itemaux.Chave=Item.Chave;


            while(aux!=NULL){

                if(aux->Item.Chave==Itemaux.Chave){
                    aux=aux-2;
                    Retira(aux,Lista,&Item);


                }
                aux=aux->Prox;
            }

}

//void InsereOrdenado()





int main()
{
    TipoLista Lista;
    TipoItem Item,Itemaux;

    FLVazia(&Lista);

    Item.Chave=1;
    Insere(Item,&Lista);
    Item.Chave=2;
    Insere(Item,&Lista);
    Item.Chave=3;
    Insere(Item,&Lista);
    Imprime(Lista);
    printf("Digite o numero que deseja retirar: ");
    scanf("%d",&Itemaux.Chave);
    RetiraTodos(&Lista,Itemaux);
    Imprime(Lista);
    return 0;
}
