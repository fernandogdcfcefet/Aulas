#include <stdio.h>
#include <stdlib.h>
#define tam 50;

void maiorMedia() {

}

void aprovado(int total) {

}

void inserir() {
    int n,matricula,x,i,total[tam];
    char nome[tam][50], rua[tam][50], cidade[tam][50];

    total = 0;

    for (i=0;i<n;i++) {
        printf("NOME: ");
        scanf("%c",&nome);
        printf("RUA: ");
        scanf("%c",&rua);
        printf("CIDADE: ");
        scanf("%c",&cidade);
        printf("MATRICULA: ");
        scanf("%d",&matricula);
        printf("NOTAS: ");
        scanf("%d",&x);
        total = total + x;
    }
}
