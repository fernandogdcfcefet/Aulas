
#include<stdlib.h>

#define max 30
#define strcmp
typedef struct{
	char nome[max];
	int idade, cpf;
	
}Autor;


typedef struct{
	char titulo [max];
	Autor dados;
	int ano;
	
}Livro;

void ler(){
	Livro l;
	printf("Nome livro:\n");
	gets(l.titulo);
	printf("Nome autor:\n");
	gets(l.dados.nome);
	printf("Idade autor:\n");
	scanf("%d", &l.dados.idade);
	printf("CPF autor:\n");
	scanf("%d", &l.dados.cpf);
	printf("Ano do livro:\n");
	scanf("%d", &l.ano);
	
}
int DadosLivro(){
	char nome[max];
	printf("Nome livro:\n");
	gets(nome);
	int r;
	r=strcmp(Livro.titulo,nome);
	if(r==0){
		printf("Nome autor:\n");
		puts(Livro.dados.nome);
		printf("Idade autor: %d\nCPF: %d\nAno do Livro:%d\n", Livro.dados.idade, Livro.dados.cpf, Livro.ano);
	 	return (0);
	}
	else printf ("Nao encontrado\n") return (1);
}



int main(int argc, char** argv) {
	Livro l;
	int ValorRetorno=0;
	ler();
	ValorRetorno=DadosLivro();
	
	
	
	return 0;
}
