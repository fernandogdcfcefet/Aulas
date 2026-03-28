#include <stdio.h>
#include <stdlib.h>
typedef  int  TipoChave;
typedef  struct  {
    TipoChave Chave;
    /*  outros  componentes  */
}  TipoItem;
typedef  struct  TipoCelula  *TipoApontador;
typedef  struct  TipoCelula  {
    TipoItem  Item;
    TipoApontador  Prox;
}  TipoCelula;

typedef  struct  {
    TipoApontador  Primeiro ,  Ultimo;
}  TipoLista ;

void igual(TipoLista A, TipoLista B){
    TipoApontador aux=A.Primeiro->Prox
    TipoApontador aux2=B.Primeiro->Prox
    while(aux!=NULL){
        aux == aux2;
        aux=aux->Prox;
        aux2=aux2->Prox;
    }
}

int main()
{
    return 0;
}
