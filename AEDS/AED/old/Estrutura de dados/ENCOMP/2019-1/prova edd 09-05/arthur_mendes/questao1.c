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

typedef  struct{
    TipoApontador Primeiro,Ultimo;
}TipoLista ;

int  Vazia( TipoLista  Lista ){
    return(Lista.Primeiro == Lista.Ultimo);
}

void RetiraTodos(TipoLista *Lista, TipoItem Item){
    TipoApontador aux = Lista->Primeiro->Prox;
    TipoApontador q;
    if (Vazia(*Lista) || ){
        printf ("Erro:Lista vazia ou ocorrencia nao existe\n");
    return;
}
    while(aux!=NULL){
        if(aux == Item.Chave){
            q = aux;
            aux =
            if(->Prox == NULL)
                Lista->Ultimo == ;
        }
        aux=aux->Prox;
        free(q);
    }
}

int main(){
    TipoLista ML
    return 0;
}
