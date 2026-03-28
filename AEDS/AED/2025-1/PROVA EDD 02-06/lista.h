#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef  int  TipoChave;
typedef  struct
{
    TipoChave Chave;
    /*  outros  componentes  */
}  TipoItem;
typedef  struct  TipoCelula  *TipoApontador;
typedef  struct  TipoCelula
{
    TipoItem  Item;
    TipoApontador  Prox;
}  TipoCelula;

typedef  struct
{
    TipoApontador  Primeiro,  Ultimo;
}  TipoLista ;

#endif // LISTA_H_INCLUDED
