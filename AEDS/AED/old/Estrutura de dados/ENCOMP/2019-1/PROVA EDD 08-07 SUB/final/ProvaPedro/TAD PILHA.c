#include <stdio.h>
#include <stdlib.h>

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

int palindromo(TipoPilha Pilha){

    TipoPilha P1,P2;
    TipoApontador aux,aux2;
    TipoItem x;

    FPVazia(&P1);
    FPVazia(&P2);

    aux = Pilha.Topo->Prox;

    while(aux != NULL){
        Empilha(aux->Item,&P1);
        aux = aux->Prox;
    }
    imprime(P1);

    aux = Pilha.Topo->Prox;
    aux2 = P1.Topo->Prox;



    while(aux != NULL){
    printf("Aux 1: %c\n",aux->Item.Chave);
    printf("Aux 2: %c\n",aux2->Item.Chave);
        if(aux->Item.Chave != aux2->Item.Chave){
            return 0;
        }
        aux = aux->Prox;
        aux2 = aux2->Prox;

    printf("\n\n");
     }
     return 1;
}

void imprime(TipoPilha MP){

    TipoApontador aux;
    aux = MP.Topo->Prox;
    while(aux != NULL){
        printf("%c \n",aux->Item.Chave);
        aux = aux->Prox;
    }
}

int main()
{
    TipoPilha MP;

    FPVazia(&MP);

    TipoItem coisa;

    coisa.Chave = 'A';
    Empilha(coisa,&MP);
    coisa.Chave = 'B';
    Empilha(coisa,&MP);
    coisa.Chave = 'Z';
    Empilha(coisa,&MP);
    coisa.Chave = 'A';
    Empilha(coisa,&MP);

    imprime(MP);

    printf("\n\n");

    if(palindromo(MP)){
        printf("E palindromo\n");
    }else{
        printf("Nao e palindromo\n");
    }





}

