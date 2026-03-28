#include<stdio.h>
#include<string.h>
#define TAM 3


typedef struct{

    char rua[100];

}endereco;

typedef struct{

    char nome[100];
    int telefone[10];
    endereco end;

}pessoa;

int main(){

    pessoa d[TAM];
    int i,j;
    for(i=0;i<TAM;i++){

        printf("Nome \n");
        scanf("%s", d[i].nome);
        fflush(stdin);

        printf("Rua \n");
        scanf("%s", d[i].end.rua);
        fflush(stdin);

        printf("Telefone \n");
        scanf("%d", &d[i].telefone);
        fflush(stdin);

    }

    for(i=0;i<TAM;i++){

        printf("Pessoas que moram na mesma rua de %s \n", d[i].nome);
        for(j=0;j<TAM;j++){

            if((strcmp(d[i].end.rua , d[j].end.rua) == 0 ) && (!(strcmp(d[i].nome , d[j].nome)) == 0 ))
            {
                printf("%s \n", d[j].nome);
            }
        }

    }
    return 0;


}
