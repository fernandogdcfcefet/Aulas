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
  int Tamanho;
} TipoFila;

void FFVazia(TipoFila *Fila)
{
	Fila->Frente = 1;
	Fila->Tras = Fila->Frente;
	Fila->Tamanho = 0;
}

int Vazia(TipoFila Fila)
{ return (Fila.Tamanho==0); }

void Enfileira(TipoItem x, TipoFila *Fila)
{
	if (Fila->Tamanho==MAXTAM)
  		printf(" Erro   fila esta  cheia\n");
  	else{
		Fila->Item[Fila->Tras - 1] = x;
    	Fila->Tras = Fila->Tras % MAXTAM + 1;
    	Fila->Tamanho++;
    }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{	if (Vazia(*Fila))
  		printf("Erro fila esta vazia\n");
  	else {
		*Item = Fila->Item[Fila->Tamanho-1];
        Fila->Frente = Fila->Frente % MAXTAM + 1;
        Fila->Tamanho--;
    }
}

void Imprime(TipoFila *Fila){
	if(Vazia(*Fila)!=0)
		printf("Fila esta vazia\n");
	else{
		if(Fila->Frente<Fila->Tras)
			for(int i=Fila->Frente; i<Fila->Tras; i++)
				printf("%d\n", Fila->Item[i-1]);
		if(Fila->Frente>Fila->Tras){
			for(int i=Fila->Frente-1; i<MAXTAM; i++)
				printf("%d\n", Fila->Item[i]);
			for(int i=0; i<Fila->Tras-1; i++)
				printf("%d\n", Fila->Item[i]);
		}
	}
}


int main(){
	TipoFila MF;
	TipoItem coisa, coisa1;

	FFVazia(&MF);
	coisa.Chave = 2;
	Enfileira(coisa, &MF);
	coisa.Chave = 4;
	Enfileira(coisa, &MF);
	coisa.Chave = 6;
	Enfileira(coisa, &MF);
	coisa.Chave = 8;
	Enfileira(coisa, &MF);
//	Imprime(&MF);

	coisa.Chave = 10;
	Enfileira(coisa, &MF);
	//Imprime(&MF);

//	coisa.Chave = 12;
//	Enfileira(coisa, &MF);
	//Imprime(&MF);

	Desenfileira(&MF, &coisa1);
	//printf("O item removido foi %d\n", coisa1.Chave);
	//Imprime(&MF);

//	coisa.Chave = 9;
	//Enfileira(coisa, &MF);
//	coisa.Chave = 10;
	//Enfileira(coisa, &MF);
	//Imprime(&MF);

	Desenfileira(&MF, &coisa1);
	//printf("O item removido foi %d\n", coisa1.Chave);
	//Imprime(&MF);

	coisa.Chave = 12;
	Enfileira(coisa, &MF);
	Imprime(&MF);

	return 0;
}
