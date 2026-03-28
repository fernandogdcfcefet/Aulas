#include <stdio.h>
#include <stdlib.h>

typedef  int  TipoChave;
typedef  struct  {
int  Chave;
char pa[3];
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

void  Imprime( TipoPilha  Pilha )
{
    TipoApontador  Aux;
    Aux =  Pilha.Topo->Prox ;
    while  (Aux  !=  NULL){
        printf ( "%d\n" ,  Aux->Item.Chave) ;
        Aux = Aux->Prox ;
    }
}

int main()
{
    TipoPilha pilha;
	TipoItem item,item1,item2,item3,item4;
	item.pa={A};
	item1.Chave='A';
	item2.Chave=4;
	item3.Chave=5;
	item4.Chave=6;
	FPVazia(&pilha);
	Vazia(pilha);
	Empilha(item,&pilha);
	Empilha(item1,&pilha);
	Empilha(item2,&pilha);
	Empilha(item3,&pilha);
	
	Imprime(pilha);
    
}
