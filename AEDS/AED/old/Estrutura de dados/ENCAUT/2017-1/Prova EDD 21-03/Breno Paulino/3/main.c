#include <stdio.h>
#include <stdlib.h>
typedef struct
{
  char bairro[50], rua[50];
  int numero;
} endereco;
typedef struct
{
  char nome[50];
  int telefone;
  endereco end;
} pessoa;
int main()
{
    return 0;
}
