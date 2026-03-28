#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 5
typedef int TipoApontador;

typedef int TipoChave;

typedef struct {
    TipoChave Chave;
    int a;
    char b;
/* outros componentes */
} TipoItem;

typedef struct {
    TipoItem Item[MAXTAM] ;
    TipoApontador Frente , Tras;
} TipoFila ;

void FFVazia(TipoFila *Fila )
{
    Fila->Frente = 1;
    Fila->Tras = Fila->Frente;
}

int Vazia(TipoFila Fila )
{
    return ( Fila .Frente == Fila .Tras ) ;
}

void Enfileira (TipoItem x , TipoFila *Fila )
{
    if ( Fila->Tras % MAXTAM + 1 == Fila->Frente)
        printf ( " Erro f i la est a cheia\n" ) ;
    else {
        Fila->Item[ Fila->Tras - 1] = x;
        Fila->Tras = Fila->Tras % MAXTAM + 1;
    }
}

void Desenfileira(TipoFila *Fila , TipoItem *Item)
{
    if (Vazia(*Fila ) )
        printf ( "Erro f i la esta vazia\n" ) ;
    else {
        *Item = Fila->Item[ Fila->Frente - 1];
        Fila->Frente = Fila->Frente % MAXTAM + 1;
    }
} //Questão 2, Letra b \/
void Imprime(TipoFila *Fila){
    TipoApontador ap1;
    if(Vazia(*Fila)){
        printf("Erro, fila vazia\n");
    }
    else{
    ap1=Fila->Frente % MAXTAM;
    for(ap1;ap1!=Fila->Tras;ap1 = Fila->Frente % MAXTAM + 1){
        printf("%d \n",Fila->Item[Fila->Frente].a);
        printf("%c \n",Fila->Item[Fila->Frente].b);
    }
    }
}
int main()
{
    return 0;
}
