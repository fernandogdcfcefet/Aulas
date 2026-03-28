#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#define MAX 10

typedef int TipoChave;
typedef struct {
  char Chave;
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
  free(q);  
  Pilha->Tamanho--;
}

int Tamanho(TipoPilha Pilha)
{ return (Pilha.Tamanho); }

///////////////////////////////////////////////////////////
void inverteLetras(TipoPilha *Pilha, TipoItem *Item){
	
	
TipoApontador q;

	TipoPilha aux;
	 FPVazia(aux);
	 
  if (Vazia(*Pilha)) { printf("Erro: lista vazia\n"); return; }
  else{
  		
		if(strcmp(Pilha->Topo->Item.Chave, .)==1){//compara se o caracter é um ponto
	
 	 	q = Pilha->Topo;
 	 	Pilha->Topo = q->Prox;
 	 	*Item = q->Prox->Item;
 	 	Empilha(q->Item.Chave,&aux);/*  inverte a palavra(pilha) até que o caractere seja um ponto                                           */
 	 	Pilha->Tamanho--;
  		}
	}
	
}
/////////////////////////////////////////////////////////////////

int main()
{
	
	
	
	
}

