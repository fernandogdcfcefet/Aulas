#include <stdio.h>
#include <stdlib.h>

//#include "Fila_Arranjo.h"
#include "Fila_Ponteiro.h"

int main()
{
    Cliente clientes[] { {"Joao", 35}, {"Maria", 66}, {"Antonio", 45}, {"Joana", 70}, {"Felix", 75} };

    TipoFila *f = (TipoFila*)malloc(sizeof(TipoFila));
    FFVazia(f);

    for(int i=0;i<5;i++)
        EnfileiraComPrioridade(f, clientes[i]);

    Imprimi(f);

    return 0;
}
