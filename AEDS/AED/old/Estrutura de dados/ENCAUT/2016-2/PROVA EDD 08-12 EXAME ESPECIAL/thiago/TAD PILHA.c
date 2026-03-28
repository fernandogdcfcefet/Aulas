#include <stdio.h>
#include <stdlib.h>
#define TAM 7

typedef  int  TipoChave;
typedef  struct  {
int  Chave; 
char nome[100];
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
        printf ( "%d  %s \n" ,  Aux->Item .Chave ,Aux->Item.nome) ;
        Aux = Aux->Prox ;
    }
}  



void Inverte(TipoPilha *Pilha ){
	TipoPilha P1,P2;
	TipoItem i1;
	  FPVazia(&P1);
	  FPVazia(&P2);
	  
	  
	  while(!(Vazia(*Pilha))){
	  	Desempilha(Pilha,&i1);
	  	Empilha(i1,&P1);
	  	Empilha(i1,&P2);
	  }
	  
	  while(!(Vazia(P2))){
	  	Desempilha(&P2,&i1);
	  	Empilha(i1,Pilha);
	  
	  }
}
int palindromo(TipoPilha Pilha1,TipoPilha Pilha2){
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


TipoPilha p1; 
FPVazia(&p1); 
TipoPilha p2; 
FPVazia(&p2); 


printf("A pilha esta vazia:  %i \n ",Vazia(p1));
printf("A pilha esta vazia:  %i \n ",Vazia(p2));



TipoItem i1={10,'A'};
TipoItem i2={10,'R'};
TipoItem i3={10,'A'};
TipoItem i4={10,'R'};
TipoItem i5={10,'A'}; 

Empilha(i1,&p1) ;
Empilha(i2,&p1) ;
Empilha(i3,&p1) ;
Empilha(i4,&p1) ;
Empilha(i5,&p1) ;

palindromo(p1,p2);

Imprime(p1);


    return 0;
}
