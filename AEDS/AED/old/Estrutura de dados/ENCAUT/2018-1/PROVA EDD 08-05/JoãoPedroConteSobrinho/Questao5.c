#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAX 10

/*
*Nesse programa preferi retornar uma pilha invertida para a original
*/

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

void Imprime(TipoPilha Pilha){
    TipoApontador Aux;
    Aux = Pilha.Topo->Prox;

    while(Aux != NULL){
        printf("%d\t", Aux->Item.Chave);
        Aux = Aux->Prox;
    }
    printf("\n\n");
}

TipoPilha Inverte(TipoPilha *Pilha){ //Funcao que inverte pilha
    TipoItem Item; //Item Auxiliar
    TipoPilha PilhaAux; // Pilha Auxiliar (que sera retornada)
    FPVazia(&PilhaAux); //Faz ela vazia
    int i, tam = Pilha->Tamanho; //Variavel i do for e tam do tamanho original da pilha a ser invertida

    for(i=0; i<tam; i++){ //Percorre todo tamaanho
        Desempilha(Pilha, &Item); //Desempilhando da pilha original
        Empilha(Item, &PilhaAux); //Empilhando na pilha auxiliar (invertido)
    }

    return PilhaAux; //Retorna a pilha auxiliar
}

int main()
{
    TipoPilha MP; // Cria a pilha
    FPVazia(&MP); // Faz ela vazia
    TipoItem Item; // Cria o item

    //Insere itens
    Item.Chave = 1;
    Empilha(Item, &MP);
    Item.Chave = 2;
    Empilha(Item, &MP);
    Item.Chave = 3;
    Empilha(Item, &MP);
    Item.Chave = 4;
    Empilha(Item, &MP);
    Item.Chave = 5;
    Empilha(Item, &MP);
    //Imprime a pilha
    Imprime(MP);

    //Inverte a pilha
    MP = Inverte(&MP);
    //Imprime invertida
    Imprime(MP);
}

