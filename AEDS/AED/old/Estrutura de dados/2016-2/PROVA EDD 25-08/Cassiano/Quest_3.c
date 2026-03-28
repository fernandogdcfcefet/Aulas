#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define TAM 3
typedef struct{
    char rua;
}endereco;

typedef struct{
    char nome;
    endereco end;
    int telefone;

}pessoa;


int main(){
    pessoa d[TAM];
    int i, j;
    for(i=0; i<TAM; i++){
        //fflush(stdin);
        printf("Nome\n");
        scanf("%s", &d[i].nome);
        //fflush(stdin);
        printf("Rua\n");
        scanf("%s", &d[i].end.rua);
        //fflush(stdin);
        printf("Telefone\n");
        scanf("%d", &d[i].telefone);
    }
    for(i=0; i<TAM; i++){
        printf("Pessoas que moram na mesma rua de %s\n", d[i].nome);
        for(j=0; j<TAM; j++){
            if((strcmp(d[i].end.rua,d[j].end.rua)==0)&&(!(strcmp(d[i].nome,d[j].nome))==0)){
        /*Na linha de código acima é feita COMPARAÇÂO de se existem pessoas que moram na mesma rua, na primeira parte é verivicado se
        se o nome da rua da pessoa na possição i é igual ap nome da rua da pessoa na posição j; ja na segunda parte é verificado se o nome da pessoa na posição i é
        igual ao da pessoa na posição j; caso for não passara a execução para a próxima linha, pois nesta estrutura condicional têm que ser atendidas a primeira e segunda parte.*/
                printf("%s\n", d[j].nome);

            }


        }


    }

system("pause");
return 0;
}
