#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3

/*  A linha 23 do código da questão 3 compara o valor da variável "rua" na posição "i" do vetor de struct com o
valor da variável "rua" na posição "j" do mesmo vetor.
    Essa comparação é feita também o valor da variável "nome", contidos no vetor struct.

    Se o valor da "rua" da pessoa na posição "j" do vetor for IGUAL ao valor da "rua" na posição "i" e o valor
do "nome" na posição "i" for DIFERENTE do "nome" na posição "j", então o código da linha 25 é executado.

*/

typedef struct {
    char rua[50];
}endereco;

typedef struct {
    char nome[50];
    int telefone;
    endereco end;
}pessoa;

int main(){
    pessoa d[TAM];
    int i, j;
    for (i=0; i<TAM; i++){
        printf("Nome\n");
        scanf("%s", &d[i].nome);
        printf("Rua\n");
        scanf("%s", &d[i].end.rua);
        printf("Telefone\n");
        scanf("%d", &d[i].telefone);
    }
    for (i=0; i<TAM; i++){
        printf("Pessoas que moram na mesma rua de %s\n", d[i].nome);
        for (j=0; j<TAM; j++){
            if ((strcmp(d[i].end.rua, d[j].end.rua)==0) && (!(strcmp(d[i].nome, d[j].nome))==0)){
                printf("%s\n", d[j].nome);
            }
        }
    }
    return 0;
}
