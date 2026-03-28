#include <stdio.h>
#include <stdlib.h>
#define TAM 3

typedef struct{
    char rua[50];
} endereco;

typedef struct{
    char nome[50];
    endereco end;
    int telefone;
}pessoas;

int main()
{
    pessoas d[TAM];
    int i, j;
    for(i = 0; i < TAM; i++){
        printf("Nome\n");
        scanf("%s", d[i].nome);
        printf("Rua\n");
        scanf("%s", d[i].end.rua);
        printf("Telefone\n");
        scanf("%d", &d[i].telefone);
    }
    for(i = 0; i < TAM; i++){
        printf("Pessoas que moram na mesma rua %s\n", d[i].nome);
        for(j = 0; j<TAM; j++){
            if((strcmp(d[i].end.rua, d[j].end.rua)==0)&&(!(strcmp(d[i].nome, d[j].nome))==0)){
                printf("%s\n", d[j].nome);
            }
        }
    }
    return 0;
}
