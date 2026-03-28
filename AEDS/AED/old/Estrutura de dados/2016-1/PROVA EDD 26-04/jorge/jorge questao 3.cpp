#include<stdio.h>
#include<conio.h>
#include<iostream>
# define MAXTAM 1000;

void imprime(TipoPilha * Pilha){
	tipoapontador aux;
	While(aux!=NULL){
	printf(Pilha->Topo[aux].Chave, Pilha->Topo--);
	}
}
// item 1 e o maio disco item 2 o medio item 3 o pequeno
int main(){
	TipoPilha p1,p2,p3;
	TipoItem item 1,item2,item3;
	FPVazia(&p1);
	FPvazia(&p2);
	FPvazia(&p3);
	empilha(item1,&p1);
	empilha(item2,&p1);
	empilha(item3,&p1);
	desempilha(&p1,&item3);
	imprime(&Pillha);
	empilha(item3,&p3);
	imprime(&Pilha);
	desempilha(&p1,&item2);
	imprime(&Pilha);
	empilha(item2,&p2);
	imprime(&Pilha);
	desempilha(&p3,&item3);
	imprime(&Pilha);
	empilha(item3,&p2);
	imprime(&Pilha);
	desempilha(&p1,&item1);
	imprime(&Pilha);
	empilha(item1,&p3);
	imprime(&Pilha);
	desempilha(&p2,&item3);
	imprime(&Pilha);
	empilha(item3,&p1);
	imprime(&Pilha);
	desempilha(&p2,&item2);
	imprime(&Pilha);
	empilha(item2,&p3);
	imprime(&Pilha);
	desempilha(&p1,&item3);
	imprime(&Pilha);
	empilha(item3,&p3);
	imprime(&Pilha);
	
	getch();
	return 0;
}
