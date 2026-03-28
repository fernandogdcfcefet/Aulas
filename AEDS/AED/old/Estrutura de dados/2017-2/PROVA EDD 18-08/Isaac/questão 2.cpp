#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define X 1 // Qtd de Alunos
#define N 1 //Qtd de notas para cada aluno

typedef struct {
	char nome[50][X];
	int matricula[X], nota[X][N];
	int soma[X], qtd[X];
} dados;

dados aluno;

void aprovados() {
	for (int a=0; a<X; a++) {
		if(aluno.soma[a]/aluno.qtd[a] >= 60) {
			printf("\n\tOs alunos aprovados foram: ");
			printf("\n\t - %s", aluno.nome[a]);
		}
	}
}

void maiormedia() {
	int maior = aluno.soma[0]/aluno.qtd[0];
	int indmaior;
	for (int b=1; b<X; b++) {
		if(aluno.soma[b]/aluno.qtd[b] > maior) {
			indmaior = b;
		}
	}
	printf("\n\tA maior média foi de: %s", aluno.nome[indmaior]);
	
}	

int main() {
	setlocale(LC_ALL, "portuguese");

	for (int i = 0; i < X; i ++)  {
		printf("\t\nIndorme o nome do aluno %d: ", i+1);
		gets(aluno.nome[i]);
		fflush(stdin);
		printf("\t\nInforme o número de matícula de %s: ", aluno.nome[i]);
		scanf("%d", &aluno.matricula[i]);
		for (int j = 0; j < N; j++) {
			printf("\t\nInforme a nota %d de %s: ", j+1, aluno.nome[i]);
			scanf("%d", &aluno.nota[i][j]);
			aluno.soma[i] = aluno.soma[i] + aluno.nota[i][j];
			aluno.qtd[i] = aluno.qtd[i] + 1;
		}
	}
	system("cls");
	aprovados();
	maiormedia();

}
