#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

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

void palindromo(TipoPilha Pilha, TipoPilha PilhaOrig){
	TipoItem aux, aux2;
	TipoPilha PilhaAux;
	
	FPVazia(&PilhaAux);

	while(Pilha.Topo->Prox!=NULL){
		Desempilha(&Pilha,&aux);
		Empilha(aux,&PilhaAux);	
	}
	
	TipoApontador  AuxP, AuxQ;
    AuxP = PilhaOrig.Topo->Prox ;
    AuxQ = PilhaAux.Topo->Prox;
    
    while  ((AuxP  !=  NULL) && (AuxQ != NULL)){
        int i;
        i=strcpy((AuxP->Item.Chave),(AuxQ->Item.Chave));
		printf ( "%d\n" ,i) ;
        
		AuxP = AuxP->Prox ;
		AuxQ = AuxQ->Prox ;
        
    }
}

int main()
{
	TipoItem item;
	TipoPilha MP;
	
	FPVazia(&MP);
	
	item.Chave='a';
	Empilha(item, &MP);
	item.Chave='r';
	Empilha(item, &MP);
	item.Chave='a';
	Empilha(item, &MP);
	item.Chave='r';
	Empilha(item, &MP);
	item.Chave='a';
	Empilha(item, &MP);
	
	Imprime(MP);
	
	printf("\n\n");
	palindromo(MP, MP);
    
	return 0;
}
