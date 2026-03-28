#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef  int  TipoChave;
typedef  struct  {
int  Chave;


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
        printf ( "%c\n" ,  Aux->Item.Chave) ;
        Aux = Aux->Prox ;
    }
}


int Compara(TipoPilha *W,TipoPilha *A){
	TipoApontador p,q;
	p=W->Topo->Prox;
	q=A->Topo->Prox;
	while(p!= NULL && q!=NULL){
		if(p->Item.Chave == q->Item.Chave){
			return  0;
		}
		    q=p;
			p=p->Prox;
	
	}
	
	return (p==q);
	
	
}


int Palindromo(TipoPilha *Pilha){
	TipoPilha a,b;
	TipoItem it;
	while(!Vazia(*Pilha)){
		Desempilha(Pilha,&it);
		Empilha(it,&a);
		Empilha(it,&b);
		
	}
	while(!Vazia(b)){
		Desempilha(&b,&it);
		Empilha(it,&Pilha);
			
	}
	return Compara(Pilha,&a);
	

	
}













int main()
{
    TipoPilha mp;
    TipoItem item,item1,item2;
    item.Chave='a';
    Empilha(item,&mp);
    item1.Chave='c';
    Empilha(item1,&mp);
    item2.Chave='a';
    Empilha(item2,&mp);
    Imprime(mp);
    
    
  return 0;
    
    
}
