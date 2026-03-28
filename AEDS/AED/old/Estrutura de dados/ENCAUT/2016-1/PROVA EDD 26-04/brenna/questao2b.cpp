#include<stdio.h>
#include<conio.h>
#define MAXTAM 100
typedef int TipoApontador;

typedef int TipoChave;
typedef struct
{
	TipoChave Chave;
} TipoItem;
typedef struct {
	TipoItem Item[MAXTAM];
	TipoApontador Frente,Tras;
	
	
 } TipoFila;

void FFVazia (TipoFila *Fila)
{
	Fila->Frente =1;
	Fila->Tras =Fila -> Frente;
	
}

int Vazia (TipoFila Fila)
{
	return (Fila.Frente == Fila.Tras);
}

void Enfileira  ( TipoItem x, TipoFila *Fila)
{
	if ( Fila -> Tras % MAXTAM +1 == Fila -> Frente)
	printf("erro ");
	else {
		
		Fila ->Item [Fila-> Tras -1] =x;
		Fila->Tras =Fila -> Tras % MAXTAM +1;
		
	}
}
void Desemfileira  (  TipoFila *Fila,TipoItem *Item)
{
	if ( Vazia(*Fila))
	printf("erro ");
	else {
		
		*Item =Fila ->Item [Fila-> Tras -1] ;
		Fila->Frente =Fila -> Frente % MAXTAM +1;
		
        }
}


void Imprime(TipoFila Fila){
	TipoApontador aux;
	while(aux != Vazia(Fila))
	{
		printf("%d\n", Fila.Item->Chave);
		Fila -> Frente++;
		
		
		
	}
	
}
 int main ()
 
 {
 TipoFila mf;
 TipoItem item,item2;
 FFVazia(&mf);
 
 Vazia(mf);
 item.Chave=1;
 Enfileira(item,&mf);
 Imprime(mf);
 item2.Chave=2;
 Enfileira(item2,&mf);
 Imprime(mf);
 
 
 
 
 return 0; 
 }













