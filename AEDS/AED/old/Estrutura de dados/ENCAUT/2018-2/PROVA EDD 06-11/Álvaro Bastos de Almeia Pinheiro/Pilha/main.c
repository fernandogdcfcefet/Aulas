#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAXTAM  1000

typedef int TipoApontador;

typedef int TipoChave;
typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;
typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Frente, Tras;
  int tamanho;
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
  Fila->tamanho=0;
}

int Vazia(TipoFila Fila)
{ return (Fila.Frente == Fila.Tras); }

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->Tras % MAXTAM + 1 == Fila->Frente)
  printf(" Erro   fila est  a  cheia\n");
  else { Fila->Item[Fila->Tras - 1] = x;
         Fila->Tras = Fila->Tras % MAXTAM + 1;
         Fila->tamanho++;
       }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
         Fila->tamanho--;
       }
}

void imprime(TipoFila ML){
    for(int i=0;i<ML.tamanho;i++){
        printf("%d",ML.Item[i].Chave);
    }
}

void Empilha(TipoItem x, TipoFila *Fila1, TipoFila *Fila2){//fila ja uma fila preenchida e vc que adcionar o x.chave e que fazer virar uma pilha que e fila
    int t = Fila1->tamanho+1;
    TipoItem b, a[t];
    for(int i=0;i<t-1;i++){
        Desenfileira(Fila1,&a[i]);
    }
    a[t-1]=x;
    for(int i = 0;i<t;i++){
        for(int j = i ; j<t;j++){
            if(a[i].Chave<a[j].Chave){
                b=a[i];
                a[i]=a[j];
                a[j]=b;
            }
        }
    }
    FFVazia(Fila2);
    for(int m=0;m<t;m++){
        Enfileira(a[m],Fila2);
    }

}

void desempilha(TipoItem x, TipoFila *Fila1, TipoFila *Fila2){
    TipoItem a;
    Desenfileira(Fila2,&a);
}

int main(int argc, char *argv[])
{
    TipoFila f,F;
    TipoItem a;
    FFVazia(&f);
    FFVazia(&F);
    a.Chave=1;
    Enfileira(a,&f);
    a.Chave=2;
    Enfileira(a,&f);
    a.Chave=9;
    Enfileira(a,&f);
    a.Chave=4;
    Enfileira(a,&f);
    Empilha(a,&f,&F);
    desempilha(a,&f,&F);
    imprime(F);
}
