# include <stdio.h>

# define MAXTAM 1000

typedef int TipoApontador;
typedef int TipoChave;
typedef struct {

}TipoItem;

typedef struct {

TipoItem Item [MAXTAM];
TipoApontador Frente, Tras;
} TipoFila;

void FFvazia(TipoFila *Fila)
{
    Fila -> Frente = 1; Fila ->Tras = Fila ->Frente;
}

int Vazia( TipoFila Fila)
{
     return (Fila. Frente ==Fila .Tras);
}

void Enfileira (TipoItem x, TipoFila * Fila)
{
    if ( Fila ->Tras %MAXTAM + 1 ==Fila->Frente )
        printf ("Erro fila está cheia\n");

    else {

        Fila->Item[Fila->Tras-1]=x;
        Fila->Tras = Fila->Tras%MAXTAM +1;
    }
}
 void Desenfileira (TipoFila *Fila , TipoItem *Item)
 {
     if (vazia(*Fila))
        printf("Erro fila esta vazia\n" );

     else {*Item =Fila->Item[Fila->Frente-1];
            Fila-> Frente = Fila->Frente %MAXTAM + 1;
        }

  void imprime (TipoFila *Fila){  /* letra b) 8*/

          while ( Fila!=0)
            printf ( "%i Item Fila" ,&Fila);
        }
 }








