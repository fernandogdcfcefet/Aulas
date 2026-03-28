#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#define MAX 10

typedef char TipoChave;
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

int VerificaPalindromo(TipoPilha *Pilha){
    int tam = Pilha->Tamanho, i=0, j=tam-1;
    char vet[tam], vetInvertido[tam];
    TipoApontador aux = Pilha->Topo->Prox;
    while(aux != NULL){
        vet[i] = aux->Item.Chave;
        aux = aux->Prox;
        i++;
    }
    i=0;
    while(vet[i]!='\0'){
        //printf("%c", vet[i]);
        vetInvertido[j] = vet[i];
        i++;
        j--;
    }

    /*printf("\n");
    i=0;
    while(vetInvertido[i]!='\0'){
        printf("%c", vetInvertido[i]);
        i++;
    }*/

    if(strcmp(vet, vetInvertido)==0) return 1;
    else return 0;

}

int main(int argc, char *argv[])
{
    TipoItem a,b,c,d,e;
    a.Chave = 'A';
    b.Chave = 'R';
    c.Chave = 'A';
    d.Chave = 'R';
    e.Chave = 'A';

    TipoPilha p;
    FPVazia(&p);
    Empilha(a, &p);
    Empilha(b, &p);
    Empilha(c, &p);
    Empilha(d, &p);
    Empilha(e, &p);

    printf("%d", VerificaPalindromo(&p));
}

