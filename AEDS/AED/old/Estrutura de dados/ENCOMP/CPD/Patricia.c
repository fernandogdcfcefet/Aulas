#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define TAM 26

typedef struct NO{
	struct NO* filhos[TAM];
	int indice;
	char pref[20];
}NO;

typedef NO* Ramo;

void setFilhos(Ramo p)
{
	int i;

	for(i=0;i<TAM;i++){

		p->filhos[i] = NULL;
	}
}

Ramo criaNo(){
	Ramo p = (Ramo)malloc(sizeof(NO));

	if(p){
		setFilhos(p);
	}
	return p;
}

int isEmpty(Ramo raiz){
	if( raiz == NULL)
		return 1;
	return 0;
}

int mapearIndice(char c){
	return c - 'a';
}

int verAlfabeto(char palavra[], NO raiz, int *indice){ // verifica qual palavra vem antes pela ordem alfabética
	int i, j=0;

	for(i=0;i<strlen(palavra) && i<strlen(raiz.pref);i++){ // percorrer as palavras até o fim de pelo menos uma
		if(palavra[i] != raiz.pref[i]){ //verifica em qual caracter uma palavra é diferente da outra
			j = 1;
			break;
		}
	}
	*indice = i;
	if(j){
		if(palavra[i] > raiz.pref[i])
			return 1;
		else
			return -1;
	}else{
		if(strlen(palavra)>strlen(raiz.pref)) // se a palavra tiver mais letras do que a que já tem inserida na arvore
			return 1;
		else if(strlen(palavra)<strlen(raiz.pref)) // se a palavra que já tem inserida na arvore  tiver mais letras do que a comparada
			return -1;
	}

	return 0;
}

void separaString(char *chave, int indice){
	char aux[20];
	int i, j;

	for(j=0, i=indice;i<strlen(chave);i++, j++)
		aux[j] = chave[i];
    aux[j]='\0';

    strcpy(chave,aux);
}
void insere(Ramo raiz, char chave[]){

	int i, v, tam_chave = strlen(chave);
	Ramo r = raiz;

	if(isEmpty(r->filhos[mapearIndice(chave[0])])){//se não tiver nenhuma palavra com a primeira letra igual a da chave a posição referente a letra do vetor de filhos tem como prefixo a propria palavra
		r = r->filhos[mapearIndice(chave[0])] = (NO*) malloc(sizeof(NO));
		setFilhos(r);
		strcpy(r->pref, chave);
		puts(r->pref);
		r->indice = tam_chave;
	}else{
		v = verAlfabeto(chave, *r->filhos[mapearIndice(chave[0])], &i);

		if(v==0){ // se a palavra que quer inserir já tem na arvore encerra o metodo
			return;
		}else if(v==1){ // se a palavra que já está na arvore for um prefixo da chave (que será inserida) eu insiro o restante da chave em um filho da que já está na árvore
			r->indice = i;
			r=r->filhos[mapearIndice(chave[0])];
			separaString(chave, i);
			insere(r, chave);
		}else{
			printf("\n\nInserir anteriormente não foi implementado!\n\n");
		}
	}
}

void imprime(NO raiz, char aux[], int nivel){
	int i;

	for(i=0;i<TAM;i++){
		if(!isEmpty(raiz.filhos[i])){
			strcat(aux, raiz.filhos[i]->pref);
			puts(aux);
			imprime(*(raiz.filhos[i]), aux, nivel+1);

			if(nivel==0)
				aux[0]='\0';
		}
	}
}

int main()
{
    Ramo raiz = criaNo();

	char chave[20];

	strcpy(chave, "aola");
    insere(raiz, chave);

	strcpy(chave, "bola");
    insere(raiz, chave);

	strcpy(chave, "bolacha");
    insere(raiz, chave);

    strcpy(chave, "bolada");
    insere(raiz, chave);



	printf("-------------------- IMPRIME --------------------\n");
	chave[0] = '\0';
    imprime(*raiz, chave, 0);


	return 0;
}
