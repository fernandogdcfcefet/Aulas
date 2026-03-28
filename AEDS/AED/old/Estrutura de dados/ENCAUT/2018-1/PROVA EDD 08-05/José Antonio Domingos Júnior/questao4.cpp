#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAXTAM  5

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
{ return (Fila.Frente == Fila.Tras); }

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->Tras % MAXTAM + 1 == Fila->Frente)
  printf(" Erro   fila est  a  cheia\n");
  else { Fila->Item[Fila->Tras - 1] = x;
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

void imprime(TipoFila mf){
	
	int i;
	if(mf.Frente<mf.Tras){
		for(i=mf.Frente-1; i<mf.Tras-1;i++){
			printf("%d",mf.Item[i]);
		}
	}
	else{
		for(i=mf.Frente-1; i<MAXTAM;i++){
			printf("%d",mf.Item[i]);
		}
		for(i=0; i<mf.Tras-1;i++){
			printf("%d",mf.Item[i]);
		}
	}
	
}

int main()
{
	
	TipoFila mf;
	FFVazia(&mf);
	Vazia(mf);
	TipoItem coisa;
	coisa.Chave=3;
	Enfileira(coisa,&mf);
	coisa.Chave=8;
	Enfileira(coisa,&mf);
	coisa.Chave=9;
	Enfileira(coisa,&mf);
	coisa.Chave=2;
	Enfileira(coisa,&mf);
	imprime(mf);
	
	
	
}
