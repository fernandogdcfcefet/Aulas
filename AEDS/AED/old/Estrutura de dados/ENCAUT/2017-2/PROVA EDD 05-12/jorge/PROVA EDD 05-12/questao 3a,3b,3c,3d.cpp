#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#define N 10

typedef struct no{
	int v;
	TipoApontador  Prox;
} No;


typedef struct{
	int n;
	TipoApontador No*  lista[N];
}Grafo;

void inicializa(Grafo *g){
	int i;
	for(i=0;i<N;i++){
		g->lista[i]=NULL;
	}
}

void imprime(Grafo g){
	int i;
	for(i=0;i<N;i++){
		if(g.lista[i]!=NULL){
			printf("%d -",i);
			TipoApontador aux=g.lista[i];
			while(aux->Prox!=NULL){
				printf(",%d",aux->v);
				aux=aux->Prox;
			}
			printf("\n");
		}
	}
	
}

void insere_aresta(Grafo *g, int v1, int v2){
	TipoApontador aux=g->lista[v1];
	while(aux!=NULL){
		No* n=(TipoApontador) malloc(sizeof(No));
		n->v=v2;
		n->Prox=NULL;
		g->lista[v1]=n;
	}
	if(aux==NULL){
		aux=aux->Prox;
	}
	else{
		No* n=(TipoApontador)malloc(sizeof(No));
		n->v=v2;
		n->Prox=NULL;
		aux->Prox=n;
	}
}

void insere(Grafo *g, int v1, int v2){
	insere_aresta(g,v1,v2);
	insere_aresta(g,v2,v1);
	
}

int main(){
	Grafo g;
	inicializa(&g);
	insere(&g,1,2);
	insere(&g,2,1);
	imprime(g);
	
	getch();
	return 0;
}
