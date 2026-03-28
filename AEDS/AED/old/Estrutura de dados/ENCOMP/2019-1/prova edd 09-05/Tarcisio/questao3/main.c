#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 10

typedef int TipoChave;
typedef int TipoApontadorF;
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
typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontadorF Frente, Tras;
} TipoFila;

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
void ImprimeP(TipoPilha pilha)
{
    TipoApontador aux;
    aux=pilha.Fundo;
    while(aux!=NULL)
    {
        printf("\n%d", aux->Item.Chave);
        aux=aux->Prox;
    }
}

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
}

int VaziaFila(TipoFila Fila)
{ return (Fila.Frente == Fila.Tras); }

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->Tras % MAXTAM + 1 == Fila->Frente)
  printf(" Erro   fila est  a  cheia\n");
  else { Fila->Item[Fila->Tras - 1] = x;
         Fila->Tras = Fila->Tras % MAXTAM + 1;
       }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (VaziaFila(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
       }
}
void ImprimeF(TipoFila Fila)
{
    if (VaziaFila(Fila))
    printf("Erro fila esta vazia\n");
    else{
        int aux;
        if(Fila.Frente<Fila.Tras)
        {
            for(aux=Fila.Frente-1;aux<Fila.Tras-1;aux++)
            {
                printf("%d \n", Fila.Item[aux].Chave);
            }
        }
        else{
            if(Fila.Frente<Fila.Tras)
            {
                for(aux=Fila.Frente-1;aux<MAXTAM-1;aux++)
                {
                    printf("%d \n", Fila.Item[aux].Chave);
                }
                for(aux=0;aux<Fila.Tras-1;aux++)
                {
                    printf("%d \n", Fila.Item[aux].Chave);
                }
                printf("%d \n", Fila.Item[aux].Chave);
            }
        }

    }
}

void EmpilhaFila(TipoItem x, TipoFila *fila1, TipoFila *fila2)
{


    int i;

    for(i=0;i<3;i++)
    {
            Desenfileira(fila2, &x);

        }

        for(i=0;i<3;i++)
        {
            Desenfileira(fila1, &x);

        }

}

int main()
{
    TipoFila PF, SF;
    TipoPilha MP;
    TipoItem xx;
    FPVazia(&MP);
    FFVazia(&PF);
    FFVazia(&SF);
    int i;
    for(i=0;i<3;i++)
    {
        xx.Chave=rand()%10;
        Enfileira(xx,&PF);
        Enfileira(xx,&SF);
    }
    ImprimeF(PF);
    ImprimeF(SF);
    EmpilhaFila(xx, &PF, &SF);
    ImprimeP(MP);
    ImprimeF(SF);
    ImprimeF(PF);

    return 0;
}
