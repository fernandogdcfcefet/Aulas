#include <stdio.h>
#include <stdlib.h>
#define TAM 3
typedef struct{
    char nome[];
    int telefone;
    struct end{
    char rua[];
    }
} pessoa,end;
int main()
{
    printf("Hello world!\n");
    return 0;
}
/* o código na linha 23 tem o objetivo de imprimir na tela o nome das pessoas que moram na mesma rua.
Para isso, primeiro ele testa, usando o STRCMP (comparação de strings) para verificar se o nome da rua armazenado na estrutura de uma pessoa na posição "i" é igual ao de uma pessoa na posição "j".
Então, usando um operador booleano "AND" e o "!", que é um inversor, ele adiciona uma condição, de que os nomes destas pessoas não sejam iguais.
Sendos atendidas ambas as condições, o codigo manda imprimir na tela  o nome da pessoa na posição j. */


