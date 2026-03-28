#include <stdio.h>
#include <stdlib.h>
typedef int TipoChave;
typedef struct{
	TipoChave Chave;
}TipoItem;

typedef struct TipoCelula *TipoApontador;
typedef struct TipoCelula{
	TipoItem Item;
	TipoApontador Prox;
}TipoCelula;

typedef struct{
	TipoApontador Primeiro, Ultimo;
}TipoLista;

void FLVazia(TipoLista *Lista){
	Lista->Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
	Lista->Ultimo = Lista->Primeiro;
	Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista){
	return (Lista.Primeiro==Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista){
	Lista->Ultimo->Prox = (TipoApontador) malloc (sizeof(TipoCelula));
	Lista->Ultimo = Lista->Ultimo->Prox;
	Lista->Ultimo->Item = x;
	Lista->Ultimo->Prox = NULL;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item){
	TipoApontador q;
	if(Vazia(*Lista) || p==NULL || p->Prox==NULL){
		printf("Erro Lista vazia ou posição não existe\n");
		return;
	}
	
	q = p->Prox;
	*Item = q->Item;
	p->Prox = q->Prox;
	if(p->Prox==NULL) Lista->Ultimo=p;
	free(q);
}

void ImprimeLista(TipoLista Lista){
	
	TipoApontador aux=Lista.Primeiro->Prox;
	
	while(aux!=NULL){
		printf("%d \n", aux->Item.Chave);
		aux=aux->Prox;
	}
	
	printf("\n------------------------\n");
}

void InsereOrdenado(TipoItem x, TipoLista *Lista){
	TipoApontador aux=Lista->Primeiro->Prox;
	
	while(aux!=NULL){
		if(aux->Item.Chave<x.Chave){
			aux->Prox = (TipoApontador) malloc (sizeof(TipoCelula));
			aux = aux->Prox;
			aux->Item = x;
			if(aux->Prox==Lista->Ultimo) aux->Prox = NULL;
		}
		
		aux=aux->Prox;
	}
	
	
	
}

int main(){
	TipoLista L;
	TipoItem x;
	
	FLVazia(&L);
	
	x.Chave = 2;
	Insere(x,&L);
	
	x.Chave = 4;
	Insere(x,&L);
	
	x.Chave = 6;
	Insere(x,&L);
	
	ImprimeLista(L);
	
	x.Chave = 4;
	
	
	ImprimeLista(L);
	
	x.Chave = 3;
	InsereOrdenado(x,&L);
	
	
	
}
