#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 1000
typedef int TipoApontador;
typedef int TipoChave;

typedef struct{
	TipoChave Chave;
}TipoItem;

typedef struct{
	TipoItem Item[MAXTAM];
	TipoApontador Topo;
}TipoPilha;

void FPVazia(TipoPilha *Pilha){
	Pilha->Topo=0;
}

int Vazia(TipoPilha Pilha){
	return (Pilha.Topo==0);
}

void Empilha(TipoItem x, TipoPilha *Pilha){
	if(Pilha->Topo==MAXTAM){
		printf("pilha cheia\n");
	}else{
		Pilha->Topo++;
		Pilha->Item[Pilha->Topo-1] = x;
	}
}

void Desempilha(TipoPilha *Pilha, TipoItem *Item){
	if(Vazia(*Pilha)){
		printf("PILHA VAZIA\n");
	}else{
		*Item = Pilha->Item[Pilha->Topo-1];
		Pilha->Topo--;
	}
}

int Tamanho(TipoPilha Pilha){
	return (Pilha.Topo);
}

void Imprime(TipoPilha P){
	TipoApontador aux;
	
	for(aux=P.Topo;aux>0;aux--){
		printf("%d \n",P.Item[aux-1]);
	}
	
	printf("----------------\n");
	
	
}

int main(){
	TipoPilha P1,P2,P3;
	TipoItem x,salva;
	
	
	FPVazia(&P1);
	FPVazia(&P2);
	FPVazia(&P3);
	
	x.Chave=3;
	Empilha(x,&P1);
	
	x.Chave=2;
	Empilha(x,&P1);
	
	x.Chave=1;
	Empilha(x,&P1);
	
	Imprime(P1);
	getchar();
	
	Desempilha(&P1,&salva);
	Empilha(salva,&P3);
	printf("P1\n");
	Imprime(P1);
	printf("P3\n");
	Imprime(P3);
	getchar();
	system("cls");
	
	
	Desempilha(&P1,&salva);
	Empilha(salva,&P2);
	printf("P1\n");
	Imprime(P1);
	printf("P2\n");
	Imprime(P2);
	printf("P3\n");
	Imprime(P3);
	getchar();
	system("cls");
	
	Desempilha(&P3,&salva);
	Empilha(salva,&P2);
	printf("P1\n");
	Imprime(P1);
	printf("P2\n");
	Imprime(P2);
	printf("P3\n");
	Imprime(P3);
	getchar();
	system("cls");
	
	Desempilha(&P1,&salva);
	Empilha(salva,&P3);
	printf("P1\n");
	Imprime(P1);
	printf("P2\n");
	Imprime(P2);
	printf("P3\n");
	Imprime(P3);
	getchar();	
	system("cls");
	
	Desempilha(&P2,&salva);
	Empilha(salva,&P1);
	printf("P1\n");
	Imprime(P1);
	printf("P2\n");
	Imprime(P2);
	printf("P3\n");
	Imprime(P3);
	getchar();	
	system("cls");
	
	Desempilha(&P2,&salva);
	Empilha(salva,&P3);
	printf("P1\n");
	Imprime(P1);
	printf("P2\n");
	Imprime(P2);
	printf("P3\n");
	Imprime(P3);
	getchar();	
	system("cls");
	
	Desempilha(&P1,&salva);
	Empilha(salva,&P3);
	printf("P1\n");
	Imprime(P1);
	printf("P2\n");
	Imprime(P2);
	printf("P3\n");
	Imprime(P3);
	getchar();	
	//system("cls");
	
	
	
}
