#include<stdio.h>
#include<string.h>
#define TAM 3

typedef struct{

    char rua[10];
}Endereco;


typedef struct{

    char nome[50];
    char telefone[8];
    Endereco end;

}pessoa;

/*Na linha 23 é comparado se  as ruas(endereços) da pessoa i e pessoa j são iguais e se seus nomes são diferentes, uma vez que não podem ser iguais. Se ambas
as condições forem satisfeitas o código da linha abaixo, dentro do if, será executado.

     */
