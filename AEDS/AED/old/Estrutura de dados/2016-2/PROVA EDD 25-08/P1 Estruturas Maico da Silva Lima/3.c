#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 3

typedef struct{
    char rua[50];
}endereco;

typedef struct{
    char nome[50];
    int telefone;
    endereco end;

}pessoa;


int main(){

    int i,j;
    pessoa d [TAM];

    for(i=0;i<TAM;i++){
        puts("Nome: ");
        scanf("%s",&d[i].nome);
        fflush(stdin);
        puts("Rua: ");
        scanf("%s",&d[i].end.rua);
        fflush(stdin);
        puts("Telefone: ");
        scanf("%d",&d[i].telefone);
        fflush(stdin);
    }
    for(i=0;i<TAM;i++){
        printf("\npessoas que moram na mesma rua de %s: \n", d[i].nome);
        for(j=0;j<TAM;j++){
            if((strcmp(d[i].end.rua,d[j].end.rua)==0)&&(!strcmp(d[i].nome,d[j].nome)==0))   ///Essa linha de código compara nome e rua de uma pessoa com a outra a fim de saber se existem pessoas
            {                                                                               /// morando na mesma rua de uma certa pessoa. fixa i em um certo valor e percorre j procurando pessoas que
                                                                                            ///moram na mesma rua.
                printf("%s\n ",d[j].nome);
            }

        }
    }
return 0;
}
