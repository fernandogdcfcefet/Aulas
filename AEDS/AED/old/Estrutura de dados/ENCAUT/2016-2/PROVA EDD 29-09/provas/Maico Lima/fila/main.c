#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 3
typedef int TipoApontador;

typedef int TipoChave;

typedef struct {
    TipoChave Chave;
/* outros componentes */
} TipoItem;

typedef struct {
    TipoItem Item[MAXTAM] ;
    TipoApontador Frente , Tras;
    int cont;
} TipoFila ;

void FFVazia(TipoFila *Fila )
{
    Fila->Frente = 1;
    Fila->Tras = Fila->Frente;
    Fila->cont=0;
}

int Vazia(TipoFila Fila )
{
    return ( Fila.cont==0 ) ;
}

void Enfileira (TipoItem x , TipoFila *Fila )
{
    if ( Fila->cont== MAXTAM)
        printf ( " Erro f i la est a cheia\n" ) ;
    else {
        Fila->Item[ Fila->Tras - 1] = x;
        Fila->Tras = Fila->Tras % MAXTAM + 1;
        Fila->cont++;
    }
}

void Desenfileira(TipoFila *Fila , TipoItem *Item)
{
    if (Vazia(*Fila ) )
        printf ( "Erro fila esta vazia\n" ) ;
    else {
        *Item = Fila->Item[ Fila->Frente - 1];
        Fila->Frente = Fila->Frente % MAXTAM + 1;
        Fila->cont--;
    }
}
void Imprime(TipoFila FilaX){
    TipoApontador Aux,c;
    Aux=FilaX.Frente;
    c=FilaX.cont;
    printf("\n______________\n");
    while(c!=0){
        printf("%d \n",FilaX.Item[Aux-1].Chave);
        Aux=Aux%MAXTAM+1;
        c--;
    }
    printf("\n______________\n");

}

int main()
{
    TipoFila F1;
    TipoItem Armazena;
    TipoItem i1={1};
    TipoItem i2={2};
    TipoItem i3={3};
    FFVazia(&F1);
    printf("Vazia: %d\n",Vazia(F1));

    Enfileira(i1,&F1);
    Enfileira(i2,&F1);
    Enfileira(i3,&F1);
    Imprime(F1);
    Desenfileira(&F1,&Armazena);
    Desenfileira(&F1,&Armazena);
    Imprime(F1);



    return 0;
}
