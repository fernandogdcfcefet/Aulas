#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> /** Inclui a biblioteca bool.h*/

typedef char TipoChave; /** Troca chave por char*/
typedef struct {
  TipoChave Chave;           /** Troca chave por char*/
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

/**=====================================================================================================================================================================================*/

bool eh_palindromo(TipoPilha *Pilha_original){

    TipoApontador pont_aux = Pilha_original->Topo->Prox;  /** Guarda o ponteiro da Pilha original*/
    TipoApontador pont_aux1, pont_aux2;
    TipoItem item_aux;
    TipoPilha pilha_aux1, pilha_aux2, pilha_aux3;   /** Declaração e inicialização das pilhas auxiliares*/
    FPVazia(&pilha_aux1); FPVazia(&pilha_aux2); FPVazia(&pilha_aux3);

    while(pont_aux->Prox != NULL) { /** Percorre a pilha original guardando os elementos nas auxiliares*/
        Desempilha(&Pilha_original, &item_aux);
        Empilha(item_aux, &pilha_aux1);
        Empilha(item_aux, &pilha_aux2);
        pont_aux = pont_aux->Prox;
        printf("Flag 1\n");
    }

    pont_aux1 = pilha_aux1.Topo->Prox;

    while(pont_aux1 != NULL) { /**Retorna a pilha original ao estado inicial*/
        Desempilha(&pilha_aux1, &item_aux);
        Empilha(item_aux, &Pilha_original);
        Empilha(item_aux, &pilha_aux3);
        printf("Flag 2\n");
    }

    pont_aux2 = pilha_aux2.Topo->Prox;

    while(pont_aux2 != NULL) { /** Compara a pilha 2 (que é a inversa da original), com a pilha 3 (que é idêntica à original)*/
            Desempilha(&pilha_aux2, &item_aux);
            Desempilha(&pilha_aux3, &item_aux);
            if(pilha_aux2.Topo->Item.Chave != pilha_aux3.Topo->Item.Chave)
                return false;
            pont_aux2 = pont_aux2->Prox;
            printf("Flag 3\n");
    }

    return true;
}

/**=====================================================================================================================================================================================*/

int main()
{
    TipoPilha palavra;
    TipoItem primletra, segunletra, tercletra;
    primletra.Chave = "a";
    segunletra.Chave = "n";
    tercletra.Chave = "a";
    FPVazia(&palavra);
    Empilha(primletra, &palavra);
    Empilha(segunletra, &palavra);
    Empilha(tercletra, &palavra);

    if(eh_palindromo(&palavra))
        printf("É palíndromo.\n");
    else
        printf("Não é palíndromo.\n");

    return 0;
}

