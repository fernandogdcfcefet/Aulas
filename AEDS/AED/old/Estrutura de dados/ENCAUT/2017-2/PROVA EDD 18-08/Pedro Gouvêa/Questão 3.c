#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define n 1

typedef struct {
  char nome[50];
  int idade, cpf;
}Autor;

typedef struct {
  char titulo[30];
  int ano;
  Autor autor;
}Livro;

void ler_livros(Livro l[]) {
  int i;
  for(i = 0; i < n; i++) {
    printf("Informe o titulo do livro: ");
    fflush(stdin);
    gets(l[i].titulo);
    fflush(stdin);

    printf("Informe o ano do livro: ");
    fflush(stdin);
    scanf("%d", &l[i].ano);
    fflush(stdin);

    printf("Informe o nome do autor do livro: ");
    fflush(stdin);
    gets(l[i].autor.nome);
    fflush(stdin);

    printf("Informe o cpf do autor do livro: ");
    fflush(stdin);
    scanf("%d", &l[i].autor.cpf);
    fflush(stdin);

    printf("Informe a idade do autor do livro: ");
    fflush(stdin);
    scanf("%d", &l[i].autor.idade);
    fflush(stdin);
  }
}

Livro retorna_livro(Livro l[], char titulo[30]) {
  int i;
  for(i = 0; i < n; i ++)
    if(strcmp(l[i].titulo, titulo))
      return l[i];
}

int main() {
  Livro l[n], livro;
  char titulo[30];
  gets(titulo);

  ler_livros(l);
  gets(titulo);
  livro = retorna_livro(l, titulo);

  printf("\n\nLivro encontrado: %s", livro.titulo);

  return 0;
}
