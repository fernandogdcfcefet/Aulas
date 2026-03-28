#include <stdio.h>
#include <stdlib.h>

typedef  int  TipoChave;
typedef  struct  {
char  Chave;
/*  outros  componentes  */
}  TipoItem;
typedef  struct  TipoCelula  *TipoApontador;
typedef  struct  TipoCelula  {
    TipoItem  Item;
    TipoApontador  Prox;
}  TipoCelula;
typedef  struct  {
    TipoApontador  Fundo,  Topo;
    int  Tamanho;
}  TipoPilha ;

void  FPVazia( TipoPilha  *Pilha)
{
    Pilha->Topo =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Pilha->Fundo =  Pilha->Topo;
    Pilha->Topo->Prox  = NULL;
    Pilha->Tamanho =  0;
}
int  Vazia( TipoPilha  Pilha)
{
    return  ( Pilha .Topo == Pilha .Fundo) ;
}

void  Empilha(TipoItem  x ,	TipoPilha  *Pilha)
{
    TipoApontador  Aux;
    Aux =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Pilha->Topo->Item  =  x;
    Aux->Prox  =  Pilha->Topo;
    Pilha->Topo = Aux; Pilha->Tamanho++;
}

void  Desempilha( TipoPilha  *Pilha ,  TipoItem  *Item)
{
    TipoApontador  q;
    if	( Vazia(*Pilha ) )  {
            printf ( "Erro :lista vazia\n");
            return ;
    }
    q =  Pilha->Topo;
    Pilha->Topo =  q->Prox ;
    *Item  =  q->Prox->Item ;
    free (q) ;
    Pilha->Tamanho--;
}

int  Tamanho( TipoPilha  Pilha)
{
    return  ( Pilha .Tamanho) ;
}

void  Imprime( TipoPilha  Lista )
{
    TipoApontador  Aux;
    Aux =  Lista.Topo->Prox ;
    while  (Aux  !=  NULL){
        printf ( "%c\n" ,  Aux->Item .Chave) ;
        Aux = Aux->Prox ;
    }
}

int palindromo(TipoPilha *p1){
    TipoPilha p2,p3;
    TipoItem aux,aux2;
    FPVazia(&p2);
    FPVazia(&p3);
    while(Vazia(*p1)!=1){
        Desempilha(p1,&aux);
        Empilha(aux,&p2);
        Empilha(aux,&p3);
    }
    while(Vazia(p2)!=1){
        Desempilha(&p2,&aux);
        Empilha(aux,p1);
    }
    while(Vazia(*p1)!=1){
        Desempilha(p1,&aux);
        Desempilha(&p3,&aux2);
        if(aux.Chave!=aux2.Chave){
            return 0;
        }
    }
    return 1;
}

int main()
{
    TipoPilha p1;
    TipoItem itemA,itemR;
    FPVazia(&p1);
    itemA.Chave='a';
    itemR.Chave='r';
    Empilha(itemA,&p1);
    Empilha(itemA,&p1);
    Empilha(itemR,&p1);
    Empilha(itemA,&p1);
    Imprime(p1);
    printf("%d\n",palindromo(&p1));
    return 0;
}
