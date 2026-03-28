#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAXTAM  1000

/*
*Nesse programa foi usado um auxilio de uma pilha para inverter a ordem
*da fila pedida. A pilha é uma pilha por apontadores, dai teve-se que
*fazer alguns ajustes, com, por exemplo, criar um tipo apontador para a
*pilha (TipoApontadorP), pois ele aponta para uma celula.
*/

typedef int TipoApontador;

typedef int TipoChave;
typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;

typedef struct TipoCelula *TipoApontadorP;
typedef struct TipoCelula {
  TipoItem Item;
  TipoApontadorP Prox;
} TipoCelula;

typedef struct {
  TipoApontadorP Fundo, Topo;
  int Tamanho;
} TipoPilha;

typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Frente, Tras;
  int Tamanho; // Criar tamanho para fila, para facilitar
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
  Fila->Tamanho = 0; // Inicializa tamanho
}

void FPVazia(TipoPilha *Pilha)
{ Pilha->Topo = (TipoApontadorP) malloc(sizeof(TipoCelula));
  Pilha->Fundo = Pilha->Topo;
  Pilha->Topo->Prox = NULL;
  Pilha->Tamanho = 0;
}

int Vazia(TipoFila Fila)
{ return (Fila.Tamanho==0); }

int VaziaPilha(TipoPilha Pilha)
{ return (Pilha.Topo == Pilha.Fundo); }

void Empilha(TipoItem x, TipoPilha *Pilha)
{ TipoApontadorP Aux;
  Aux = (TipoApontadorP) malloc(sizeof(TipoCelula));
  Pilha->Topo->Item = x;
  Aux->Prox = Pilha->Topo;
  Pilha->Topo = Aux;
  Pilha->Tamanho++;
}

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->Tras % MAXTAM + 1 == Fila->Frente)
  printf(" Erro   fila est  a  cheia\n");
  else { Fila->Item[Fila->Tras - 1] = x;
         Fila->Tras = Fila->Tras % MAXTAM + 1;
         Fila->Tamanho++;  // Soma mais 1 no tamanho criado
       }
}

void Desempilha(TipoPilha *Pilha, TipoItem *Item)
{ TipoApontadorP q;
  if (VaziaPilha(*Pilha)) { printf("Erro: lista vazia\n"); return; }
  q = Pilha->Topo;
  Pilha->Topo = q->Prox;
  *Item = q->Prox->Item;
  free(q);  Pilha->Tamanho--;
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
         Fila->Tamanho--; // Subtrai menos 1 no tamanho criado
       }
}

void Imprime(TipoFila Fila){
    int i;
    if(Fila.Frente > Fila.Tras){
        for(i=Fila.Frente-1; i<Fila.Tamanho; i++)
            printf("%d \t", Fila.Item[i].Chave);
        for(i=0; i<=Fila.Tras-1; i++)
            printf("%d \t", Fila.Item[i].Chave);
    }else if(Fila.Frente == Fila.Tras){
        for(i=Fila.Frente-1; i<Fila.Tamanho; i++)
            printf("%d \t", Fila.Item[i].Chave);
    }else /*if(Fila.Frente < Fila.Tras)*/{
        for(i=Fila.Frente-1; i<Fila.Tras-1; i++)
            printf("%d \t", Fila.Item[i].Chave);
    }
    printf("\n\n");
}/*Procedimento de imprime, que nao existia antes*/

void InverteOrdemFila(TipoFila *Fila){ /*Procedimento de inverter a fila usando pilhas como auxilio*/
    int i;
    TipoItem ItemAux; //Item Auxiliar
    TipoPilha PilhaAux; //Pilha Auxiliar
    TipoApontadorP Aux; //Auxiliar de apontador
    FPVazia(&PilhaAux); //Faz pilha vazia

    /*Desse ponto em diante verifica-se como está a fila com base na ideia de fila circular*/
    if(Fila->Frente > Fila->Tras){
        for(i=Fila->Frente-1; i<Fila->Tamanho; i++){
            Desenfileira(Fila, &ItemAux);
            Empilha(ItemAux, &PilhaAux);
        }
        for(i=0; i<=Fila->Tras-1; i++){
            Desenfileira(Fila, &ItemAux);
            Empilha(ItemAux, &PilhaAux);
        }
    }else if(Fila->Frente == Fila->Tras){
        for(i=Fila->Frente-1; i<Fila->Tamanho; i++){
            Desenfileira(Fila, &ItemAux);
            Empilha(ItemAux, &PilhaAux);
        }
    }else /*if(Fila.Frente < Fila.Tras)*/{
        for(i=Fila->Frente-1; i<Fila->Tras-1; i++){
            Desenfileira(Fila, &ItemAux);
            Empilha(ItemAux, &PilhaAux);
        }
    }

    //Auxiliar recebe o topo da pilha inserida
    Aux = PilhaAux.Topo->Prox;
    while(Aux != NULL){ //Enquanto ele nao for vazio
        Desempilha(&PilhaAux, &ItemAux); // Desempilha
        Enfileira(ItemAux, Fila); // Enfileira
        Aux = Aux->Prox;
    }

    /*Como a pilha e um FILO e a fila um FIFO, quando eu tiro da fila e insiro na pilha ele inverde, dai se eu voltar com os elementos eles voltaram invertidos*/

}

int main()
{
    TipoFila MF; // Cria fila
    FFVazia(&MF); // Faz fila vazia
    TipoItem Item;

    //Insere itens na pilha
    Item.Chave = 1;
    Enfileira(Item, &MF);
    Item.Chave = 2;
    Enfileira(Item, &MF);
    Item.Chave = 3;
    Enfileira(Item, &MF);
    Item.Chave = 4;
    Enfileira(Item, &MF);
    Item.Chave = 5;
    Enfileira(Item, &MF);
    //Imprime antes
    Imprime(MF);

    //Inverte
    InverteOrdemFila(&MF);
    //Imprime invertido
    Imprime(MF);
}
