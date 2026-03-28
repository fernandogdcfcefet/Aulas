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
    TipoApontador Frente , Tras,tam; //foi acrescentado a variavel tam para ir vendo o tamanho da fila
} TipoFila ;

void FFVazia(TipoFila *Fila )
{
    Fila->Frente = 1;
    Fila->Tras = Fila->Frente;
    Fila->tam=0; //inicializou o tam com 0
}

int Vazia(TipoFila Fila )
{
    return ( Fila .Frente == Fila .Tras ) ;
}

void Enfileira (TipoItem x , TipoFila *Fila )
{
    if ( Fila->tam ==MAXTAM)
        printf ( " Erro f i la est a cheia\n" ) ;
    else {
        Fila->Item[ Fila->Tras - 1] = x;
        Fila->Tras = Fila->Tras % MAXTAM + 1;
        Fila->tam++; //aumentou o tam
    }
}

void Desenfileira(TipoFila *Fila , TipoItem *Item)
{
    if (Vazia(*Fila ) )
        printf ( "Erro f i la esta vazia\n" ) ;
    else {
        *Item = Fila->Item[ Fila->Frente - 1];
        Fila->Frente = Fila->Frente % MAXTAM + 1;
        Fila->tam--; //diminuiu o tam ,por causa da retirada do elemento
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
	TipoItem item,item1,item2,item3,item4;
	item.Chave=2;
	item1.Chave=3;
	item2.Chave=4;
	item3.Chave=5;
	item4.Chave=6;
	FFVazia(&fila);
	Vazia(fila);
	Enfileira(item,&fila);
	Enfileira(item1,&fila);
	Enfileira(item2,&fila);
	Enfileira(item3,&fila);

	imprime(fila);
    printf("o tamanho da sua fila e : %d",fila.tam);
    return 0;
}
