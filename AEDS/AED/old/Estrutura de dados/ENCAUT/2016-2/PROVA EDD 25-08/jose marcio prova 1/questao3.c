#include<stdio.h>
#include<stdlib.h>
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

        printf("Nome\n");
        fflush(stdin);
        scanf("%s" , &d[i].nome);

        printf("Rua\n");
        fflush(stdin);
        scanf("%s" , &d[i].end.rua);

        printf("Telefone\n");
        fflush(stdin);
        scanf("%d" , &d[i].telefone);

    }
    for(i=0;i<TAM;i++){

        printf("Pessoas que moram na mesma rua de %s \n" ,d[i].nome);
        for(j=0;j<TAM;j++){

            if((strcmp(d[i].end.rua , d[j].end.rua) == 0) && (!(strcmp(d[i].nome , d[j].nome)) == 0 )) //strcmp e um comando pra string usado para fazer comparacoes entre dois elementos separados por virgula no codigo estabelecido//
                                                                                                    //a linha acima mostra a comparacao entre duas ruas(ver se sao iguais) e dois nomes (ver se sao diferentes) para entrarem na condicao do 'if'//
            {

                printf("%s\n" , d[j].nome);

            }
        }


    }

return 0;
}
