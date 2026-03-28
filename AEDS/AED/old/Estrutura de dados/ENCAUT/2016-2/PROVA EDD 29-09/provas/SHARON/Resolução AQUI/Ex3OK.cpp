#include <stdio.h>
#include <stdlib.h>

typedef  int  TipoChave;
typedef  struct  {
int  Chave;
char letra;
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
    printf("+++");
    while  (Aux  !=  NULL){
        printf ( "Chave %d\n" ,  Aux->Item .Chave) ;
        printf ( "Letra %d\n" ,  Aux->Item.letra) ;
        Aux = Aux->Prox ;
    }
}

void Palindromo(TipoPilha Pilha1,TipoPilha Pilha2)
{
 	TipoApontador  Aux;
    Aux =  Pilha1.Topo->Prox ;
    
	while(Aux!=NULL)
	{
		if(Pilha1.Topo->Prox->Item.letra==Pilha2.Topo->Prox->Item.letra) printf("Ok");
		Aux=Aux->Prox;
	}
	
	printf("PALINDROMO");
}


int main() //OBS ESTA "PEGANDO" O NUMERO DA LETRA
{
    TipoItem it1;
    it1.Chave=0;
    it1.letra='o';
    
    TipoItem it2;
    it1.Chave=1;
    it1.letra='v';
    ///
    TipoItem it3;
    it1.Chave=2;
    it1.letra='o';
    
    TipoPilha mp;
    
    FPVazia(&mp);
    
    Imprime(mp);
    
    Empilha(it1, &mp );
    Empilha(it2, &mp );
    Empilha(it2, &mp );
    
    Imprime(mp);
    
    TipoPilha mp2;
    
	FPVazia(&mp2);
	
	TipoItem guarda;
	
	Desempilha(&mp,&guarda);
	Empilha(guarda, &mp2 );
	
	Desempilha(&mp,&guarda);
	Empilha(guarda, &mp2 );
	
	Desempilha(&mp,&guarda);
	Empilha(guarda, &mp2 );
	
	Imprime(mp2);
	
	Palindromo(mp,mp2);
    
    
    
    return 0;
}

