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

void RetiraTodos(TipoLista *Lista, TipoItem Item){
	TipoApontador aux=Lista->Primeiro->Prox;
	TipoApontador antes;
	printf("Retirar o : %d\n", Item.Chave);
	TipoItem salvar;
	while(aux!=NULL){
		printf("Item Aux:%d \n",aux->Item.Chave);
		
		if(aux->Item.Chave==Item.Chave){
			printf("Retirou %d \n", aux->Item.Chave);
			Retira(antes,Lista,&salvar);
		}
		
		antes=aux;
		printf("Item Antes:%d \n",antes->Item.Chave);
		aux=aux->Prox;
	
	}	
}

void ImprimeLista(TipoLista Lista){
	
	TipoApontador aux=Lista.Primeiro->Prox;
	
	while(aux!=NULL){
		printf("%d \n", aux->Item.Chave);
		aux=aux->Prox;
	}
	
	printf("\n------------------------\n");
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
	
	RetiraTodos(&L,x);
	
	ImprimeLista(L);
	
	
	
}
