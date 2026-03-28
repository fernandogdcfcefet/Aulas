#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 5
typedef int TipoApontador;

typedef int TipoChave;

typedef struct {
    TipoChave Chave;
/* outros componentes */
} TipoItem;

typedef struct {
    TipoItem Item[MAXTAM] ;
    TipoApontador Frente , Tras;
} TipoFila ;

void FFVazia(TipoFila *Fila )
{
    Fila->Frente = 1;
    Fila->Tras = Fila->Frente;
}

int Vazia(TipoFila Fila )
{
    return ( Fila .Frente == Fila .Tras ) ;
}

void Enfileira (TipoItem x , TipoFila *Fila )
{
    if ( Fila->Tras % MAXTAM + 1 == Fila->Frente)
        printf ( " Erro f i la est a cheia\n" ) ;
    else {
        Fila->Item[ Fila->Tras - 1] = x;
        Fila->Tras = Fila->Tras % MAXTAM + 1;
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
void imprime(TipoFila Fila){
	TipoApontador aux;
	for(aux=Fila.Frente-1;aux!=Fila.Tras-1;aux=(aux+1)% MAXTAM){
		printf("[%d]\n",Fila.Item[aux]);
	}

}

int main()
{

	TipoFila fila;
	TipoItem item,item1,item2;
	item.Chave=2;
	item1.Chave=3;
	item2.Chave=4;
	FFVazia(&fila);
	Vazia(fila);
	Enfileira(item,&fila);
	Enfileira(item1,&fila);
	Enfileira(item2,&fila);
	imprime(fila);






    return 0;
}
