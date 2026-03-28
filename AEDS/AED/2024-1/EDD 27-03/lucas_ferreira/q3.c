#include "stdlib.h"
#include "stdio.h"

typedef struct endereco_da_pessoa
{
    char rua[50];
}endereco;

typedef struct dados_da_pessoa{
    int telefone;
    char nome[50];
    endereco end;
}pessoa;
