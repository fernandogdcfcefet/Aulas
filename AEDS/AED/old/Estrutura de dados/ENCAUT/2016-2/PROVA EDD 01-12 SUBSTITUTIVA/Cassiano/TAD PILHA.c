#include <stdio.h>
#include <stdlib.h>

typedef  char  TipoChave;
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

void palindromo(TipoPilha P1, TipoPilha P2){
	
	
}
int main()
{	
	TipoChave chave;
	TipoItem item;
	TipoPilha MP;
	FPVazia(&MP);
	
	item.Chave='a';
	Empilha(item,&MP);
	item.Chave='r';
	Empilha(item,&MP);
	item.Chave='a';
	Empilha(item,&MP);
	item.Chave='r';
	Empilha(item,&MP);
	item.Chave='a';
	Empilha(item,&MP);
	
	Desempilha(&MP, 'a');
	
	
	
	Imprime(MP);
	
	
	
   // printf("Hello world!\n");
    return 0;
}
