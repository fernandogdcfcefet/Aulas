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
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
}

int Vazia(TipoFila Fila)
{ return (Fila.Frente == Fila.Tras % MAXTAM); }

void Enfileira(TipoItem x, TipoFila *Fila){
	
	if (Fila->Tras % MAXTAM + 1 == Fila->Frente)
  	printf(" Erro   fila est  a  cheia\n");
  	else{
		Fila->Item[Fila->Tras - 1] = x;
  		Fila->Tras = Fila->Tras % MAXTAM + 1;	
    }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
         
       }
}

void Imprime(TipoFila *Fila){
	int i;
	
	for(i=Fila->Frente; i<Fila->Tras; i++){
		printf("%d", Fila->Item[i]);
	}
}

void Empilha(TipoItem x, TipoFila *Fila1, TipoFila *Fila2){
	Desenfileira(*Fila1, *x);
	Enfileira(x, *Fila2);
}

void Desempilha(TipoItem x, TipoFila *Fila1, TipoFila *Fila2){
	Desenfileira(*Fila2, x);
	Enfileira(x, *Fila1);
}

int main(int argc, char *argv[])
{
	TipoFila Fila1;
	TipoFila Fila2;
	
	FFVazia(Fila1);
	FFVazia(Fila2);
	
	Enfileira(1, Fila1);
	Enfileira(2, Fila1);
	Enfileira(3, Fila1);
	
	Imprime(Fila1);

}
