#include <stdio.h>
#include <stdlib.h>

typedef  int  TipoChave;

typedef  struct  {
    int Chave;
/*  outros  componentes  */
} Item1;

typedef  struct  TipoCelula  *TipoApontador;

typedef  struct  TipoCelula  {
    Item1  Item;
    TipoApontador  Prox;
}  TipoCelula;

typedef  struct  {
    TipoApontador  Primeiro ,  Ultimo;
}  TipoLista ;

void  FLVazia( TipoLista   *Lista )
{
    Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
}

int  Vazia( TipoLista  Lista )
{
    return  ( Lista . Primeiro ==  Lista . Ultimo ) ;
}

void  Insere(Item1  x ,	TipoLista  * Lista )
{
    Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Ultimo->Prox ;
    Lista->Ultimo->Item  =  x;
    Lista->Ultimo->Prox  =  NULL;
}/*
void InsereOrdenado(Item1 ItemX,TipoLista *ListaX){
    TipoApontador Aux;
    Aux=ListaX->Primeiro
    while(Aux->Prox.Item.chave!=ItemX->Chave)


    }*/

void  Retira(TipoApontador  p,	TipoLista  *Lista ,  Item1  *Item)
{	/*--O item  a  ser  retirado  e  o  seguinte  ao  apontado  por  p--*/
    TipoApontador  q;
    if	( Vazia(*Lista )	||	p == NULL	||	p->Prox == NULL){
        printf ( "  Erro :	Lista  vazia  ou  posicao  nao  existe \n" ) ;
        return ;
    }
    q =  p->Prox;  *
    Item  =  q->Item ;
    p->Prox  =  q->Prox ;
    if	( p->Prox == NULL )
        Lista->Ultimo  = p;
    free (q);
}
void  Imprime( TipoLista  Lista )
{
    printf("\n__________\n");
    TipoApontador  Aux;
    Aux =  Lista . Primeiro->Prox ;
    while  (Aux  !=  NULL){
        printf ( "%d\n" ,  Aux->Item .Chave) ;
        Aux = Aux->Prox ;
    }
}

void RetiraTodos(TipoLista *ListaX,Item1 ItemX){
    TipoApontador Aux;
    Item1 Armazena;
    Aux=ListaX->Primeiro;
    while(Aux->Prox!=NULL){
       if(Aux->Prox->Item.Chave==ItemX.Chave){
        Retira(Aux,ListaX,&Armazena);
       }
       Aux=Aux->Prox;

    }




}


int main()
{
    Item1 i1={1};
    Item1 i2={2};
    Item1 i3={3};
    Item1 i4={1};
    Item1 i5={5};
    TipoLista L1;
    FLVazia(&L1);
    printf("Vazia: %d\n",Vazia(L1));

     Insere(i1,&L1);
     Insere(i2,&L1);
     Insere(i3,&L1);
     Insere(i4,&L1);
     Insere(i5,&L1);
     Imprime(L1);
     RetiraTodos(&L1,i1);
     Imprime(L1);




    return 0;
}
