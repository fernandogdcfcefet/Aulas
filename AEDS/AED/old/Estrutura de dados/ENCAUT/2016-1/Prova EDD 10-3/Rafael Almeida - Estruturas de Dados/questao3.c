#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 3

typedef struct
{
    int telefone;
    char nome[30], rua[50];

}pessoa;

int main()
{
    pessoa d[TAM];
    int i, j;
    for(i=0;i<TAM;i++)
    {
        printf("Nome:\n");
        scanf("%s",d[i].nome);
        printf("Rua:\n");
        scanf("%s",d[i].rua);
        printf("Telefone:\n");
        scanf("%d",&d[i].telefone);
        system("cls");
    }
    for(i=0;i<TAM;i++)
    {
        printf("Pessoas que moram na mesma rua de %s:\n", d[i].nome);
            for(j=0;j<TAM;j++)
            {
                if((strcmp(d[i].rua,d[j].rua)==0)&&(!(strcmp(d[i].nome,d[j].nome))==0))
                {
                    printf("%s\n\n", d[j].nome);
                }
                
            }
         system("\n\npause");
            
    }
    return 0;
}


