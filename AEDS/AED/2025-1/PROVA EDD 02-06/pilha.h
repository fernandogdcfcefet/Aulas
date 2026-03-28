#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#define MAXTAM 1000
typedef int TipoApontador;
typedef int TipoChave;
typedef struct
{
    TipoChave Chave;
    /* --- outros componentes--- */
} TipoItem;
typedef struct
{
    TipoItem Item[MAXTAM ] ;
    TipoApontador Topo;
} TipoPilha;

#endif // PILHA_H_INCLUDED
