#include <stdio.h>
#include <string.h>
#define TAM 3

typedef struct{
    char rua[40];
}end;

typedef struct{
    char nome[40];
    end end;
    char telefone[15];
}pessoa;

int main(){
    pessoa d[TAM];
    int i,j;
    for(i=0;i<TAM;i++){
        printf("Nome\n");
        scanf("%s", d[i].nome);
        printf("Rua\n");
        scanf("%s", d[i].end.rua);
        printf("Telefone\n");
        scanf("%s", &d[i].telefone);
    }
    for(i=0;i<TAM;i++){
        printf("Pessoas que moram na mesma rua de %s\n",d[i].nome);
        for(j=0;j<TAM;j++){
            if((strcmp(d[i].end.rua,d[j].end.rua)==0) && (!strcmp(d[i].nome,d[j].nome))==0)
            /*
               Esta estrutura condicional é composta por duas expressões lógicas.
               A primeira é dedicada à comparação entre duas strings, que representam as rua das pessoas nas posições i e j. Caso sejam iguais, retornará 0, que no caso representa TRUE.
               A segunda compara os nomes das pessoas da posição i e j, para que uma pessoa não seja comparada com ela mesma. Nesse caso de negação, o valor buscado é diferente de 0.
               Para que o if seja executado, as duas condições devem ser verdadeiras.
            */
               printf("%s\n", d[j].nome);
        }
    }
    return 0;
}
