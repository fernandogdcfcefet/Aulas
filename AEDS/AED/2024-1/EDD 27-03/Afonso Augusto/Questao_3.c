#include <stdio.h>
#include <stdlib.h>
#include "Questao_3.h"
#define TAM 3

int main(){

    pessoa d[TAM];
    int i,j;
    for(i=0;i<TAM;i++)
    {
        printf("Nome\n");
        getchar();
        scanf("%s", &d[i].nome);
        printf("Rua\n");
        scanf("%s", &d[i].rua);
        printf("Telefone \n");
        scanf("%d", &d[i].telefone);
    }
    for(i=0;i<TAM;i++)
    {
        
        printf("Pessoas que moram na mesma rua de %s\n", d[i].nome);
        for(j=0;j<TAM;j++)
        {
            if((strcmp(d[i].rua,d[j].rua)==0)&&(!(strcmp(d[i].nome,d[j].nome))==0))
            {
                printf("%s\n", d[j].nome);
            }
        }
    }


    return 0;
}