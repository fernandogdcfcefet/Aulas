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
  TipoApontador tam;
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
  Fila->tam=0;
}

int Vazia(TipoFila Fila)
{ 
	Fila.tam=0;
	return (Fila.Frente == Fila.Tras); 
}

/*void Enfileira(TipoItem x, TipoFila *Fila)
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
}*/

void ImprimeFila(TipoFila Fila){
	int i;

	for(i=Fila.Frente-1;i!=Fila.Tras-1;i = (i+1) % MAXTAM){
	    printf("%d ", Fila.Item[i].Chave);
	}
     
}

void Enfileira(TipoFila *Fila,TipoItem x)
{
	
	if(Fila->tam==MAXTAM)
	printf("fila cheia");
	else
	{
	Fila->Item[Fila->Tras]=x;
	Fila->Tras=(Fila->Tras+1)%MAXTAM;
	Fila->tam++;
	}
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{
	if (Vazia(*Fila))
  	printf("Erro fila esta vazia\n");
	else
	{
		*Item=Fila->Item[Fila->Frente];
		(Fila->Frente=Fila->Frente+1)%MAXTAM;
		Fila->tam--;
	}
		
}



int main(int argc, char *argv[])
{
	TipoFila MF;
    TipoItem x, y, z, w, guarda;
    
    FFVazia(&MF);
        
    x.Chave = 1;
    y.Chave = 2;
    z.Chave = 3;
    w.Chave = 4;
    
    Enfileira(&MF, x);
    Enfileira(&MF, y);
    Enfileira(&MF, z);
   	Enfileira(&MF, w);
    ImprimeFila(MF);
    
    
    Desenfileira(&MF,&guarda);
    printf("\n\n");
    
    ImprimeFila(MF);
    
    Desenfileira(&MF,&guarda);
        
    printf("\n\n");
    ImprimeFila(MF);
    
   
}
