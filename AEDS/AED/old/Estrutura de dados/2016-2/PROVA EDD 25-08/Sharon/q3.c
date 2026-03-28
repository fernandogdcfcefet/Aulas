#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
//#include<iostream>


#define TAM 3

typedef struct
{
    char endereco;
}endereco;

typedef struct
{
    char nome;
    int telefone;
    endereco end;
    end rua;
    //end rua;
}pessoa;

int main()
{
    pessoa d[TAM];
    int i=0,j=0;

    for(i==0;i<TAM;i++)
    {
        printf("Nome:");
        scanf("%s",d[i].nome);
        printf("\nRua:");
        //scanf("%s",&d[i].end.rua);
        printf("\nTelefone:");
        scanf("%d",&d[i].telefone);
    }

    for(i==0;i<TAM;i++)
    {
        printf("\nPessoas que moram na mesma rua de %s\n",d[i].nome);

        for(j==0;j<TAM;j++)
        {
            if((strcmp(d[i].end.rua,[j].end.rua)==0)&&(!(strcmp(d[i].nome,d[j].nome)))) printf("%s\n",d[j].nome);
            /*Compara se o endereco da pesssoa especificada na LINHA 40 é igual a algum endereço da STRUCT PESSOA e se o
             nome da pessoa que tem os dois endereços que estão na comparação na LINHA 44 são iguais. Se sim, mostra qual
              o nome da pessoa, ou seja, quer saber se uma pessoa tem dois endereços iguais.*/
        }






    getch();
    return 0;

}

