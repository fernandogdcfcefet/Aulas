#include "pilha.h"

void FPVazia(TipoPilha *Pilha)
{
    Pilha->Topo = 0;
}
int Vazia(TipoPilha Pilha)
{
    return ( Pilha .Topo == 0);
}
void Empilha(TipoItem x, TipoPilha *Pilha)
{
    if ( Pilha->Topo == MAXTAM) printf ( "Erro : pilha esta cheia\n" );
    else
    {
        Pilha->Topo++;
        Pilha->Item[Pilha->Topo- 1] = x ;
    }
}
void Desempilha(TipoPilha *Pilha, TipoItem *Item)
{
    if (Vazia( *Pilha )) printf ( "Erro : pilha esta vazia\n" );
    else
    {
        *Item = Pilha->Item[Pilha->Topo- 1];
        Pilha->Topo --;
    }
}
int Tamanho(TipoPilha Pilha)
{
    return ( Pilha .Topo) ;
}
