#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#define TAM 3
typedef struct{
	char rua[100];
}endereco;

typedef struct{
	char nome[30];
	endereco end;
	int telefone;	
}pessoa;

int main(){
	pessoa d[TAM];
	int i, j;
	for(i=0; i<TAM; i++){
		printf("Nome\n");
		scanf("%s", &d[i].nome);
		printf("Rua\n");
		scanf("%s", &d[i].end.rua);
		printf("Telefone\n");
		scanf("%d", &d[i].telefone);
	}
	for(i=0; i<TAM; i++){
		printf("Pessoas que moram na mesma rua de %s\n", d[i].nome);
		for(j=0; j<TAM; j++){
			if((strcmp(d[i].end.rua,d[j].end.rua)==0)&&(!(strcmp(d[i].nome,d[j].nome))==0)){
				/*Na estrutura condicional acima é verificado quais pessoas moram na mesma rua.
				Fazendo pelo "for" percorrer vetor de pessoa 2 vezes e comparando rua da posição i com a posição j.
				E como é rodado o memso vetor duas vezes, dentro da condição "if" também tem a condição que restringe nomes iguais, para evitar de dizer, por exemplo,
				que Fulano mara na mesma rua de Fulano*/
				printf("%s\n", d[j].nome);
			}
		}		
	}
	
	system("pause");
	return 0;
}
