#include <stdio.h>
#include <stdlib.h>
#define qnt 5

typedef struct{
    char[50] nome;
    unsigned int idade;
    char[11] cpf;
}Pessoa;

typedef struct{
    char[30] titulo;
    Pessoa autor;
    int ano;
}livro;

void procura_livro(char[] tit, livro l){
    int i;
    for(i = 0; i < qnt; i++){
        if(strcmp(tit,l[i].titulo)==0){
            puts(l[i].titulo);
            printf("\n");
            puts(l[i].autor.nome);
            printf("\n");
            printf("%d \n%s \n%d",l[i].autor.idade, l[i].autor.cpf, l[i].ano)
        }
    }
}

int main()
{
    livro book[qnt];
    char[50] a;
    procura_livro(a,book);


    return 0;
}
