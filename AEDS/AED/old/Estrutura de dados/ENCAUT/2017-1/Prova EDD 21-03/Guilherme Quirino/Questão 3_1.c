#include<stdio.h>
#include<string.h>
#define TAM 3


typedef struct{
    char rua[100];
    int numero;
}endereco;

typedef struct{
    char nome[100], telefone[10];
    endereco end;
}pessoa;

int main()
{
    pessoa d[TAM];
    int i, j;
    for(i=0;i<TAM;i++)
    {
        printf("Nome\n");
        scanf("%s",&d[i].nome);
        printf("Rua\n");
        scanf("%s",&d[i].end.rua);
        printf("Telefone\n");
        scanf("%s",&d[i].telefone);
    }
    for(i=0;i<TAM;i++)
    {
        printf("pessoas que moram na mesma rua %s\n",d[i].nome);
        for(j=0;j<TAM;j++)
        {
                if((strcmp(d[i].end.rua,d[j].end.rua)==0)&&(!(strcmp(d[i].nome,d[j].nome))==0))// Estrutura condicional que compara se os endereços são iguais e os nomes diferentes
                {
                    printf("%s\n",d[j].nome);
                }
        }
    }
return 0;
}
