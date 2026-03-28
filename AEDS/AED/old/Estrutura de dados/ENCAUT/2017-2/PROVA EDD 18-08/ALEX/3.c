#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

typedef struct{
    char nome[200];
    int idade;
    char CPF[11];
}Autor;

typedef struct{
    char titulo[30];
    Autor autor;
    int ano;
}livros;

void lerDados(livros L[]){
    int i;
    for(i=0;i<TAM;i++){
        printf("Livro %d\n",i+1);
        printf("Titulo: ");
        fflush(stdin);
        gets(L[i].titulo);
        printf("Ano do livro: ");
        scanf("%d", &L[i].ano);
        fflush(stdin);
        printf("\nDados do autor: \n");
        printf("Nome: ");
        gets(L[i].autor.nome);
        printf("Idade: ");
        scanf("%d", &L[i].autor.idade);
        fflush(stdin);
        printf("CPF do autor: ");
        gets(L[i].autor.CPF);
        fflush(stdin);
    }
}

void mostraDados(livros L){
    printf("\nDados do Livro: \n");
    printf("Titulo: ");
    puts(L.titulo);
    printf("\nAno: %d",L.ano);
    printf("\n\nDados do autor do livro procurado: \n");
    printf("Nome: ");puts(L.autor.nome);
    printf("Idade: %d\n\n",L.autor.idade);
}

livros procura(livros L[], char t[]){
    int i;
    for(i=0;i<TAM;i++){
        if(strcmp(t,L[i].titulo)==0){
            printf("\nLivro encontrado!!\n");
            mostraDados(L[i]);
        }
        else if(i==TAM-1){
            printf("\nLivro nao encontrado!\n");
        }
    }
}

int main()
{
    livros L[TAM];
    lerDados(L);
    printf("Digite o titulo do livro a ser procurado: ");
    char titulo[30];
    gets(titulo);
    procura(L,titulo);

    return 0;
}
