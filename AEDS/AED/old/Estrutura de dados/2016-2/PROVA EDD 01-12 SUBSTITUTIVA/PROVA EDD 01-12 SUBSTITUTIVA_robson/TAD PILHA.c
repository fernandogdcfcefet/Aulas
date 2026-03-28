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
        printf ( "%d\n" ,  Aux->Item .Chave) ;
        Aux = Aux->Prox ;
    }
}
void palindromo(TipoPilha P1){
	int cont = 0;
	TipoItem x;
	TipoPilha P2;
	TipoPilha P3;
	FPVazia(&P2);
	FPVazia(&P3);
	TipoApontador  Aux;
	TipoApontador  Aux2;
	TipoApontador  Aux3;
	Aux = P1.Topo->Prox;
	Aux2 = P2.Topo->Prox;
    while  (Aux  !=  NULL){
        Desempilha(&P1 ,x);
        Empilha(TipoItem  x ,&P2);
        Empilha(TipoItem  x ,&P3);
        Aux = Aux->Prox ;
    }
    Aux3= P3.Topo->Prox;
    while  (Aux3  !=  NULL){
        Desempilha(&P3 ,x);
        Empilha(TipoItem  x ,&P1);
        Aux3 = Aux3->Prox ;
    }
    Aux = P1.Topo->Prox;
    Aux2 = P2.Topo->Prox;
    while  (Aux !=  NULL){
        if(Aux2->Item.Chave != Aux->Item.Chave){
        	cont++;
		}
   }
   if(cont==o)printf("palindromo");
   if(cont!=o)printf("nao é palindromo");

}

int main()
{
    printf("Hello world!\n");
    return 0;
}
