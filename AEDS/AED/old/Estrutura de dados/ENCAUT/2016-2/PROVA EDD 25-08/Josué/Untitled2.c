# include <stdio.h>
# include <stdlib.h>
# define TAM 3

 struct{

    char nome[20];
    int telefone;
    char rua [10];

 } pessoa d[];



 int main(){
    pessoa d[TAM];
    int i,j;
    for ( i=0;i<TAM;i++)
    {
        printf("Nome\n");
        scanf("%s",d[i].nome);
        printf("Rua\n");
        scanf("%s",d[i].end.rua);
        printf("Telefone\n");
        scanf("%d",&d[i].telefone);

    }
    for ( i=0;i<TAM;i++)
    {
        printf(" Pessoas que moram na mesma rua de %s\n",d[i].nome);
        for(j=0;j<TAM;j++)
        {
            if ((strcmp(d[i].end.rua,d[j].end.rua)==0))&&(!(strcmp(d[i].nome,d[j].nome))==0)// Este codigo está fazendo uma comparação das informações das pessoas. No qual caso o endereço(rua) das pessoas forem iguais, irá imprimir o nome dessas pessoas.
            {
                printf("%s\n",d[j].nome);

            }

        }

    }
    return 0;

 }

