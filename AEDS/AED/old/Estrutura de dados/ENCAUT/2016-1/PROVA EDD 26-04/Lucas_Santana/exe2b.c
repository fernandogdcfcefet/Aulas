#include <stdio.h>
#define MAXTAM 1000
typedef int TipoApontador;
typedef int TipoChave;
typedef struct{
	TipoChave Chave;
}TipoItem;

typedef struct{
	TipoItem Item[MAXTAM];
	TipoApontador Frente, Tras;
}TipoFila;

void FFVazia(TipoFila *Fila){
	Fila->Frente=1;
	Fila->Tras = Fila->Frente;
}

int Vazia(TipoFila Fila){
	return (Fila.Frente==Fila.Tras);
}

void Enfileira(TipoItem x, TipoFila *Fila){
	if(Fila->Tras%MAXTAM+1 == Fila->Frente){
		printf("Erro fila esta cheia\n");
	}else{
		Fila->Item[Fila->Tras-1]=x;
		Fila->Tras = Fila->Tras%MAXTAM+1;
	}
}

void Desenfileira(TipoFila *Fila, TipoItem *Item){
	if(Vazia(*Fila))
		printf("Erro fila esta vazia\n");
	else{
		*Item = Fila -> Item[Fila->Frente-1];
		Fila->Frente = Fila->Frente%MAXTAM+1;
	}
}

void ImprimeFila(TipoFila Fila){
	TipoApontador i;
	for(i=Fila.Frente-1;i!=Fila.Tras-1;i=(i+1)%MAXTAM){
		printf("%d \n",Fila.Item[i].Chave);
	}
}
int main(){
	TipoFila F;
	TipoItem x;
	
	FFVazia(&F);
	
	x.Chave = 2;
	Enfileira(x, &F);
	
	x.Chave = 5;
	Enfileira(x, &F);
	
	x.Chave = 7;
	Enfileira(x, &F);
	
	ImprimeFila(F);
}
