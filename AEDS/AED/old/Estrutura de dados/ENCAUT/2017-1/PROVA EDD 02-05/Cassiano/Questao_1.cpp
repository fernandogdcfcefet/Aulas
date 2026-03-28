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
{ return (Pilha.Topo == Pilha.Fundo); }

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
  if (Vazia(*Pilha)) { printf("Erro: lista vazia\n"); return; }
  q = Pilha->Topo;
  Pilha->Topo = q->Prox;
  *Item = q->Prox->Item;
  free(q);  Pilha->Tamanho--;
}

int Tamanho(TipoPilha Pilha)
{ return (Pilha.Tamanho); }

void Palindromo(TipoPilha Pilha_1){
	TipoPilha Pilha_2, Pilha_3, Pilha_4;
	FPVazia(&Pilha_2);
	FPVazia(&Pilha_3);
	FPVazia(&Pilha_4);
	
	TipoItem guarda;
	int i, cont=0;
	
	for(i=0; i<MAX; i++){
		Desempilha(&Pilha_1, &guarda);
		Empilha(guarda,&Pilha_2);
		Empilha(guarda, &Pilha_3);
	}
	
	for(i=0; i<MAX; i++){
		Desempilha(&Pilha_2, &guarda);
		Empilha(guarda,&Pilha_4);
	}
	
	for(i=0; i<MAX; i++){
		if(Pilha_3.Topo->Item.Chave==Pilha_4.Topo->Item.Chave){
			cont++;
		}
	}
	if(cont==MAX){
		printf("EH PALINDROMO");
	}	
}

int main(int argc, char *argv[])
{
}

