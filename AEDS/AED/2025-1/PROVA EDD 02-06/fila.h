#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#define MAXTAM  1000

typedef int TipoApontador;

typedef int TipoChave;
typedef struct
{
    TipoChave Chave;
    /* outros componentes */
} TipoItem;
typedef struct
{
    TipoItem Item[MAXTAM];
    TipoApontador Frente, Tras;
} TipoFila;


#endif // FILA_H_INCLUDED
