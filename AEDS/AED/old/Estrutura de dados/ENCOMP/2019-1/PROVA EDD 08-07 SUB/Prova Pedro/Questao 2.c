#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int Tamanho(TipoPilha Pilha)
{ return (Pilha.Tamanho); }

bool verificaPalindromo(TipoPilha MP){
    bool palindromo = true;
    TipoPilha aux;
    TipoApontador aux2 = MP.Fundo;
    FPVazia(&aux);
    TipoItem item;
    while(aux2 != MP.Topo){
        Desempilha(&MP,&item);
        Empilha(item,&aux);
        aux2 = aux2->Prox;
    }
    aux2 = MP.Fundo;
    TipoApontador aux3 = aux.Fundo;

     while(aux2 != MP.Topo && aux3 != aux.Topo){
        if(aux2->Item.Chave != aux3->Item.Chave){
            palindromo = false;
        }
     }
     return palindromo;
}

int main()
{
    TipoPilha MP;
    FPVazia(&MP);


    TipoItem coisa1,coisa2,coisa3;

    coisa1.Chave = 'A';
    coisa2.Chave = 'B';
    coisa3.Chave = 'A';

    Empilha(coisa1,&MP);
    Empilha(coisa2,&MP);
    Empilha(coisa3,&MP);



    if(verificaPalindromo(MP)){
        printf("E palindromo\n");
    }else{
        printf("Nao e palindromo\n");
    }
}

