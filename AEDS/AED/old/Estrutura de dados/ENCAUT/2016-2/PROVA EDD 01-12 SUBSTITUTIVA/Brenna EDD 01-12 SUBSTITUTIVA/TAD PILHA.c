#include <stdio.h>
#include <stdlib.h>

typedef  int  TipoChave;
typedef  struct  {
int  Chave;
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
    Pilha->Topo = Aux; 
	Pilha->Tamanho++;
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

void Inverte(TipoPilha *Pilha ){
	TipoPilha a,b;
	TipoItem it;
	 FPVazia(&a);
	  FPVazia(&b);
	  while(!(Vazia(*Pilha))){
	  	Desempilha(Pilha,&it);
	  	Empilha(it,&a);
	  	Empilha(it,&b);
	  }
	  
	  while(!(Vazia(b))){
	  	Desempilha(&b,&it);
	  	Empilha(it,Pilha);
	  
	  }
}
int Palindromo(TipoPilha Pilha1,TipoPilha Pilha2){
	FPVazia(&Pilha1);
	FPVazia(&Pilha2);
	Inverte(&Pilha1);
	TipoApontador p,q;
	p=Pilha1.Topo;
	q=Pilha2.Topo;
	Inverte(&Pilha1);
	 while((p->Item.Chave)==( q->Item.Chave)){
		return 1;
	}
	return 0;
}
	  

int main()
{
   
   TipoPilha mp;
   TipoPilha mp1;
   FPVazia(&mp1);
   FPVazia(&mp);
   Vazia(mp);
    Vazia(mp1);
   
   
   TipoItem item,item1,item2;
   item.Chave= 'a' ;
   Empilha(item,&mp); 
    item1.Chave= 'b' ;
   Empilha(item1,&mp); 
    item2.Chave= 'a';
   Empilha(item2,&mp); 
   Imprime(mp);
   printf("\n");
  
  Imprime(mp);
   printf("%d \n",Palindromo(mp,mp1));
   return 0;
   
   
    
}
