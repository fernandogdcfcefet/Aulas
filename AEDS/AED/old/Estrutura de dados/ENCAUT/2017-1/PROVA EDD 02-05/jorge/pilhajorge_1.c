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


int pilhaigual(TipoPilha Pilha, TipoPilha Pilha1){
	TipoApontador aux,aux2;
	
	for(aux=Pilha.Topo->Prox,aux2=Pilha1.Topo->Prox;aux!=NULL || aux2!=NULL;aux=aux->Prox,aux2=aux2->Prox){
		if(aux->Item.Chave!=aux2->Item.Chave){
			return 0;
		}
	}
	return (aux==aux2);
}

int palindromo(TipoPilha *Pilha){
	TipoPilha Pilha1,Pilha2;
	TipoItem Item;
	
	FPVazia(&Pilha1);
	FPVazia(&Pilha2);
	
	while(!Vazia(*Pilha)){
		Desempilha(&Item,Pilha);
		Empilha(Item,&Pilha1);
		Empilha(Item,&Pilha2);
	}
	
	while(!Vazia(Pilha2)){
		Desempilha(&Item,&Pilha2);
		Empilha(Item,Pilha);
	}
	
	if(pilhaigual(*Pilha,Pilha1)){
		return 1;
	}
	else{
		return 0;
	}
}



int main(int argc, char *argv[])
{
	
	TipoPilha Pilha1,Pilha2,Pilha3;
	
	
	
	   
	TipoItem Item1,Item2,Item3;
	
	FPVazia(&Pilha1);
	FPVazia(&Pilha2);
	FPVazia(&Pilha3);
	
	Empilha(Item1,&Pilha1);
	Empilha(Item2,&Pilha1); // 1 passo da torre de hanoi
	Empilha(Item3,&Pilha1);
	
	Desempilha(&Pilha1,&Item3); // 2 passo
	Empilha(Item3,&Pilha3);
	
	
	Desempilha(&Pilha3,&Item2); // 3 passo
	Empilha(Item2,&Pilha2);
	
	Desempilha(&Pilha3, &Item3);  // 4 passo
	Empilha(Item3, &Pilha2);
	
	
	Desempilha(&Pilha3, &Item1); // 5 passo
	Empilha( Item1, &Pilha3);
	
	
	Desempilha(&Pilha2,&Item3);
	Empilha(Item3,&Pilha1);
	
	Desempilha(&Pilha2, &Item2);
	Empilha(Item2, &Pilha3);
	
	Desempilha(&Pilha1, &Item3);
	Empilha(Item3, &Pilha3);
	
	
	
	
	
	
	
	
	
}

