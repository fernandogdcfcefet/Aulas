#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 3
typedef int TipoApontador;

typedef int TipoChave;

typedef struct {
    TipoChave Chave;
	int cod;
} TipoItem;

typedef struct {
    TipoItem Item[MAXTAM] ;
    TipoApontador Frente ;
    int n; //numeri de elementos
} TipoFila ;

void FFVazia(TipoFila *Fila )
{
    Fila->Frente = 0;
    int n=0;
   // Fila->Tras = Fila->Frente;
}

int Vazia(TipoFila Fila )
{
    return ( Fila.n== 0/*Fila .Tras*/ ) ;

}

void Enfileira (TipoItem x , TipoFila *Fila )
{
    if ( Fila->n==MAXTAM)
        printf ( " Erro f i la est a cheia\n" ) ;
    
	else {
        Fila->Item[Fila->n] = x;
        Fila->n++;
        //Fila->Tras = Fila->Tras % MAXTAM + 1;
    }
}

void Desenfileira(TipoFila *Fila , TipoItem *Item)
{
    if (Vazia(*Fila ) )
        printf ( "Erro f i la esta vazia\n" ) ;
    else {
        *Item = Fila->Item[ Fila->Frente - 1];
        Fila->Frente = Fila->Frente % MAXTAM + 1;
    }
}

void Imprime(TipoFila Fila)
{
	int i=0;
	
	  if (Vazia(Fila ) ) printf ( "Erro f i la esta vazia\n" ) ;
    else
	 {
	
	for(i=0;i<MAXTAM;i++)//while(Fila.n!=MAXTAM)
	{
		printf ( "Chave:%d\n" ,  Fila.Item[i].Chave) ;
        printf ( "Mat:%d\n" ,  Fila.Item[i].cod) ;
        //Fila.n++ ;
	}
}
}

int main()
{
	
	TipoItem it1;
	it1.Chave=0;
	it1.cod=0;
	
	TipoItem it2;
	it1.Chave=1;
	it1.cod=1;
	
	TipoItem it3;
	it1.Chave=0;
	it1.cod=0;
	
	TipoFila mf;
	FFVazia(&mf);
	
	Imprime(mf);
	
	Enfileira(it1,&mf);
	Enfileira(it2,&mf);
	Enfileira(it3,&mf);
	

	
//	Imprime(mf);
	
    return 0;
}
