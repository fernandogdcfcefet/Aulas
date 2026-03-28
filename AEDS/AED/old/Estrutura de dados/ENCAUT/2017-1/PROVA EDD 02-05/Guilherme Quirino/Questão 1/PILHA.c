#include <stdio.h>
#include <stdlib.h>
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
  free(q);  Pilha->Tamanho--;
}

int Palindromo(TipoPilha Pilha){
    if(Vazia(Pilha)){
        printf("Erro: Pilha Vazia\n");
        return 1;
    }
    TipoPilha Pilha2, Pilha3;
    TipoItem Item;
    FPVazia(&Pilha2);
    FPVazia(&Pilha3);
    TipoApontador i, j;
    i = Pilha.Fundo;
    while(i != NULL){
        Empilha(i->Prox->Item, &Pilha2);
        i = i->Prox;
    }
    i = Pilha.Topo;
    while(!Vazia(Pilha2)){
        Desempilha(&Pilha2, &Item);
        Empilha(Item, &Pilha3);
    }
    i = Pilha.Fundo;
    j = Pilha3.Fundo;
    int cont=0;
    while(i != NULL){
        if(!(i->Item.Chave == j->Item.Chave))
            cont++;
    }
    return cont;
}

int Tamanho(TipoPilha Pilha)
{ return (Pilha.Tamanho); }

int main(){
	TipoPilha Pilha;
	FPVazia(&Pilha);
	int i;
	TipoItem item;
	char palavra[30];
	item.Chave = 'a';
        Empilha(item, &Pilha);
    item.Chave = 'r';
        Empilha(item, &Pilha);
    item.Chave = 'a';
        Empilha(item, &Pilha);
    item.Chave = 'r';
        Empilha(item, &Pilha);
    item.Chave = 'a';
        Empilha(item, &Pilha);
	if(Palindromo(Pilha)== 0){
        printf("E Palindromo\n");}
    else{printf("Nao e Palindromo\n");}
}

