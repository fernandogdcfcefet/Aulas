#include<stdio.h>
#include<conio.h>
# define N 4

typedef int Tipoapontador;
typedef int TipoChave;

typedef struct {
    TipoChave Chave;

} TipoItem;

typedef struct {
    TipoItem vet[N] ;
    TipoApontador Frente ;
    int n;
} TipoFila ;


void FFVazia(TipoFila *Fila )
{
    Fila->Frente = 0;
    Fila->n=0;
}

int Vazia(TipoFila Fila )
{
    return ( Fila->n==0 ) ;
}



void Enfileira (TipoItem x , TipoFila *Fila )
{
    if ( Fila->n==N)
        printf ( " Erro f i la est a cheia\n" ) ;
    else {
    	int fim;
        fim=(Fila->Frente + Fila->n)%N;
        Fila->vet[fim]=x;
        Fila->n++;
        
    }
}

void Desenfileira(TipoFila *Fila , TipoItem *Item){


    if (Vazia(*Fila ) ){
        printf ( "Erro f i la esta vazia\n" ) ;
}
    else {
        *Item =Fila->vet[Fila->Frente];
        Fila->Frente=(Fila->Frente % N)+1;
        
    }
}


void imprime(TipoFila Fila){
	Tipoapontador aux;
	
	for(aux=Fila.Frente->proximo;aux!=NULL;aux=aux->proximo){
		printf("%d\n",aux->item.chave);
	}
}



int main(){
	return 0;
}
