#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAX 10

typedef int TipoChave;
typedef struct {
  int Chave;
  /* outros componentes */
} TipoItem;
typedef struct TipoCelula *TipoApontador;
typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;
typedef struct {
  TipoApontador Fundo, Topo;
  int Tamanho;
} TipoPilha;

void FPVazia(TipoPilha *Pilha)
{ Pilha->Topo = (TipoApontador) malloc(sizeof(TipoCelula));
  Pilha->Fundo = Pilha->Topo;
  Pilha->Topo->Prox = NULL;
  Pilha->Tamanho = 0;
}

int Vazia(TipoPilha Pilha)
{ 
	if(Pilha.Topo==Pilha.Fundo){
		//printf("PILHA VAZIA\n");
	}
	return (Pilha.Topo == Pilha.Fundo); 
}

void Empilha(TipoItem x, TipoPilha *Pilha)
{ TipoApontador Aux;
  Aux = (TipoApontador) malloc(sizeof(TipoCelula));
  Pilha->Topo->Item = x;
  Aux->Prox = Pilha->Topo;
  Pilha->Topo = Aux;
  Pilha->Tamanho++;
}

void Desempilha(TipoPilha *Pilha, TipoItem *Item)
{ TipoApontador q;
  if (Vazia(*Pilha)) { printf("Erro: pilha vazia\n"); return; }
  q = Pilha->Topo;
  Pilha->Topo = q->Prox;
  *Item = q->Prox->Item;
  free(q);  Pilha->Tamanho--;
}

int Tamanho(TipoPilha Pilha){ 
	return (Pilha.Tamanho); 
}

void ImprimePilha(TipoPilha Pilha){/////////////
	printf("\n------\n");
	if(Vazia(Pilha)){
		printf("\nPILHA VAZIA!\n");
	}
	else{
		while(Pilha.Tamanho!=0){
			printf("%d\n\n",Pilha.Tamanho);
			Pilha.Tamanho--;
		}
	}
}
int main(int argc, char *argv[]){
	TipoPilha P1;
	TipoPilha P2;
	TipoPilha P3;
	
	FPVazia(&P1);
	FPVazia(&P2);
	FPVazia(&P3);

	TipoItem Pequeno, Medio, Grande, guarda;
	Pequeno.Chave=1;
	Medio.Chave=2;
	Grande.Chave=3;
	
	//Cria a primeira pilha
	Empilha(Grande,&P1);
	Empilha(Medio, &P1);
	Empilha(Pequeno, &P1);
	ImprimePilha(P1);
	
	//Movimentos
	Desempilha(&P1,&guarda);
	Empilha(guarda, &P3);
	ImprimePilha(P3);
	
	Desempilha(&P1, &guarda);
	Empilha(guarda, &P2);
	ImprimePilha(P2);
	
	Desempilha(&P3, &guarda);
	Empilha(guarda, &P2);
	ImprimePilha(P2);
	
	Desempilha(&P1, &guarda);
	Empilha(guarda, &P3);
	ImprimePilha(P3);
	
	Desempilha(&P2, &guarda);
	Empilha(guarda, &P1);
	ImprimePilha(P1);
	
	Desempilha(&P2,&guarda);
	Empilha(guarda, &P3);
	ImprimePilha(P3);
	
	Desempilha(&P1, &guarda);
	Empilha(guarda, &P3);
	ImprimePilha(P3);
					
	system("pause");
	return 0;
}

