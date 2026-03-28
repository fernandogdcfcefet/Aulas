#include <stdio.h>
#include<stdlib.h>
#include "ex3.h"
#include <string.h>
#define TAM 3

int main(){
    pessoa d[TAM];
    int i,j;
    for(i =0; i<TAM; i++){
        printf("Nome\n");
        scanf("%s",d[i].nome);
        printf("Rua\n");
        scanf("%s",d[i].end.rua);
        printf("Telefone\n");
        scanf("%d",&d[i].telefone);
    }
    for(i =0; i<TAM; i++){
        printf("pessoas que moram na mesma rua de %s\n",d[i].nome);
        for(j = 0; j<TAM; j++){
            if((strcmp(d[i].end.rua,d[j].end.rua)==0)&&(!(strcmp(d[i].nome,d[j].nome))==0))
                printf("%s \n",d[j].nome);
        }
    }
    return 0;
}