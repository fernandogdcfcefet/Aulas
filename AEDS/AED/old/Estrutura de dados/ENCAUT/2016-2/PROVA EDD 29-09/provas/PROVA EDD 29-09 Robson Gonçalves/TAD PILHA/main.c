#include <stdio.h>
#include <stdlib.h>

typedef  int  TipoChave;
typedef  struct  {
//int  Chave;
char chave;

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
        printf ( "%c\n" ,  Aux->Item .chave) ;
        Aux = Aux->Prox ;
    }
}
void palindromo(TipoPilha p1){
    TipoPilha p2;
    int cont=0;
    TipoApontador  Aux,Aux2;
    FPVazia(&p2);
    Aux =  p1.Topo->Prox;
    Aux2 = p2.Topo->Prox;
    while(Aux!=NULL){
        Empilha(Aux->Item,&p2);
        Aux = Aux->Prox ;
    }
    while(Aux!=NULL){
        while(Aux2!=NULL){
            if(Aux->Item.chave == Aux2->Item.chave){
                cont++;
            }
            Aux2 = Aux2->Prox ;
        }
        Aux = Aux->Prox ;
    }
    if(cont==0)printf("palindromo\n");
    if(cont>0) printf("nao e palindromo\n");

}

int main()
{
    TipoPilha p;
    TipoItem x,y,z;
    FPVazia(&p);
    x.chave='o';
    y.chave='v';
    z.chave='o';
    Empilha(x,&p);
    Empilha(y,&p);
    Empilha(z,&p);
    Imprime(p);
    palindromo(p);
    return 0;

}
