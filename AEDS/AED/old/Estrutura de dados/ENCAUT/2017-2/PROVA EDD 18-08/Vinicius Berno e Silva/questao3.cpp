#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define a 5
#

typedef struct pessoa
{
	char nome;
	int idade;
	int cpf;
}pessoa;

typedef struct livro
{
	int cod;
	char titulo;
	pessoa autor;
	int ano;
}livro;


int busca ()
{
	
int z;
char titulo;
livro cad;

	printf("Digite o titulo do livro a ser buscado ");
		scanf("%s",titulo);

	for (z=0 ; z<5 ;z++)
	{
		if(cad->titulo == titulo)
		{
			Printf("titulo %s",cad.titulo);
			printf("Autor %s", cad.autor);
			printf("Ano %d", cad.ano);
			printf("Codigo %d", cad.cod);
		}
	}
}
int main ()
{
 livro cad;
int  x ;

	for (x=0;x<5;x++)
	{
		cad.cod = x;
		Printf("Digite o titulo do livro ");
		gets(cad.titulo);
		Printf("Digite o autor do livro ");
		gets(cad.autor);
			Printf("Digite o ano do livro ");
		scanf("%d", &cad.ano);
	}	 
busca(cad);
}
