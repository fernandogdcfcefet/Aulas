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

void FFVazia(TipoFila *Fila){

int tam1, tam2;

tam1 = Fila->Frente;
tam2 = Fila->Tras;
 
 if(tam1 == tam2){
 	printf("A fila esta vazia");
 } 
 else{ 
 Fila->Frente = 1;
 Fila->Tras = Fila->Frente;
	}
}

int Vazia(TipoFila Fila){
 return (Fila.Frente == Fila.Tras);
}

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->Tras % MAXTAM + 1 == Fila->Frente)
  printf(" Erro   fila esta  cheia\n");
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


 void imprime(TipoFila *Fila)
 {
 	int i ,tam;
 	tam = Fila->Tras;
  for(i=0;i<tam;i++){
  			printf("%d\n",*Fila);
       }
}

int main(int argc, char *argv[])
{
	
	
}
