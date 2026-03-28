#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

//#define MAXTAM  1000

# define N 4

typedef int TipoApontador;

typedef int TipoChave;
typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;
typedef struct {
  //TipoItem Item[MAXTAM];
  int n;
  TipoItem vet[N];
  TipoApontador Frente, Tras;
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->n = 0;
  Fila->Tras = Fila->Frente;
}

int Vazia(TipoFila Fila)
{ 
return Fila->n==0; }

void Enfileira(TipoItem x, TipoFila *Fila)
{ 
           int fim;

     if (Fila->n==N)
  printf(" Erro   fila est  a  cheia\n");
  else { 
          fim=(Fila->Frente + Fila->n)%N;
            Fila->vet[fim]=x;
              Fila->n++;
       }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = (Fila->Frente % N) + 1;
       }
}
         
         void imprime(TipoFila Fila){
         	int i;
         	for(i=0;i<Fila.n;i++){
         		printf("%d",Fila.vet[(Fila.Frente+i)%N]);
			 }
		 }



int main(int argc, char *argv[])
{
}
