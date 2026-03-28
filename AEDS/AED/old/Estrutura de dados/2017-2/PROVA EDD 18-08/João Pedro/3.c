#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define TAM 5

typedef struct{
    char nome[30];
    int idade;
    char cpf[14];
}Autor;

typedef struct{
    char titulo[30];
    Autor autor;
}Livro;

void CadastroLivro(Livro livro[]){
    int i;
    printf("\n\n\tCADASTRO DE LIVRO\n");
    for(i=0; i<TAM; i++){
        fflush(stdin);
        printf("Livro %d nome: ", i+1);
        gets(livro[i].titulo);
        printf("Livro %d autor nome: ", i+1);
        gets(livro[i].autor.nome);
        printf("Livro %d autor CPF: ", i+1);
        gets(livro[i].autor.cpf);
        printf("Livro %d autor idade: ", i+1);
        scanf("%d", &livro[i].autor.idade);
        printf("\n\n");
    }
}

int buscaLivro(char titulo[30], Livro livro[]){
    int i, j;
    for(i=0; i<TAM; i++){
        j=strcmp(livro[i].titulo, titulo);
        if(j == 0){
            return i;
            break;
        }else{
            return 50;
            break;
        }
    }
}

int main()
{
    Livro livro[TAM];
    int posicao;
    char titulo[30];
    CadastroLivro(livro);
    fflush(stdin);
    printf("\n\nDigite o titulo do livro: ");
    gets(titulo);
    posicao = buscaLivro(titulo, livro);
    if(posicao == 50){
        printf("\n\n\tLIVRO NAO ENCONTRADO\n");
    }else{
        printf("\n\n\tLIVRO ENCONTRADO\n");
        printf("Nome: %s\n", livro[posicao].titulo);
        printf("Nome autor: %s\n", livro[posicao].autor.nome);
        printf("CPF autor: %s\n", livro[posicao].autor.cpf);
        printf("Idade autor: %d\n", livro[posicao].autor.idade);
    }
    return 0;
}
