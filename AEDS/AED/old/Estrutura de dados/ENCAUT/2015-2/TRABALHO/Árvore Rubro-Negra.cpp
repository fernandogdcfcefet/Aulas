#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define RED 1 //define as cores
#define BLACK 0


typedef struct Noh {
	int info;
	struct Noh *esq;
	struct Noh *dir;
	int cor;	
}Noh;

typedef struct Noh* ArvRB;

Noh* insereNoh(Noh*, int, int*);
Noh* Buscar(Noh*, int);
int removeArvRB(Noh*, int);
Noh* removeNoh(struct Noh* N, int valor);


int cor (Noh* N){
	if(N==NULL)
		return BLACK;
	else
	return N->cor;
	
}

//inverte a cor do pai e de seus filhos
//nao altera a estrutura ou o conteúdo da arvore
void trocaCor(Noh* N){
	N->cor = !N->cor;
	if (N->esq != NULL)
		N->esq->cor = !N->esq->cor;
	if (N->dir != NULL)
		N->dir->cor = !N->dir->cor;
}

struct Noh* rotacionaEsq(struct Noh* A){
	struct Noh* C = A->dir->dir;
	struct Noh* B = A->dir;
	A->dir = C->esq;
	B->esq = A;
	B->cor = A->cor;
	A->cor = RED;
	return B;
}

struct Noh* rotacionaDir(struct Noh* A){
	struct Noh* C= A->esq->esq;
	struct Noh* B = A->esq;
	A->esq = C->esq;
	B->dir = A;
	B->cor = A->cor;
	A->cor = RED;
	return B;
}
struct Noh* rotacionaDuplaEsq(struct Noh* A){
	struct Noh* B = A->dir;
	struct Noh* C = A->dir->esq;
	A->dir = C;
	B->esq = C->esq;
	C->dir = B;
	A->dir = B->dir;
	C->esq = A;
	C->cor = A->cor;
	A->cor = RED;
	return C;
}
struct Noh* rotacionaDuplaDir(struct Noh* A){
	struct Noh* B = A->esq;
	struct Noh* C = A->esq->dir;
	A->esq = C;
	B->dir = C->dir;
	C->esq = B;
	A->esq = B->esq;
	C->dir = A;
	C->cor = A->cor;
	A->cor = RED;
	return C;
}

//Inserção
//Para inerir um valor "V" na árvore:
//"raiz" é NULL: insira o nó.
//"V" é maior do que a raiz: vá para a sub-árvore "direita"
//aplique o método "recursivamente"
//Ao voltar na recursão, verificar as propriedades de cada sub-árvore.
//Aplique a rotação ou mudança de cor ncessária.
//Também existe o caso que a inserção é eita em uma arvore que está vazia


//PROGRAMA INICIAL
//int x = insere_ArvRB(raiz, valor);


//arquivo ArvoreLLRB.c
int insere_ArvRB(ArvRB* raiz, int valor){
	
	int resp;
	//FUNÇÃO RESPONSAVEL PELA BUSC DO LOCAL DE INSERÇÃO DO NOH
	*raiz = insereNoh(*raiz, valor, &resp);
	if((raiz) !=NULL)
		(*raiz)->cor = BLACK;
	
	return resp;
}

struct Noh* insereNoh(Noh* N, int valor, int *resp){
	if (N == NULL){
		struct Noh *novo;
		novo = (struct Noh*)malloc (sizeof(struct Noh));
		if (novo == NULL){
			*resp = 0;
			return NULL;
		}
		novo->info = valor;
		novo->cor = RED;
		novo->dir = NULL;
		novo->esq = NULL;
		*resp = 1;
		return novo;
	}
	
	if(valor == N->info)
		*resp = 0;//valor duplicado
	else{
		if(valor < N->info)
			N->esq = insereNoh(N->esq,valor,resp);
		else
			N->dir = insereNoh(N->dir,valor,resp);
	}
		
	if (N->esq==NULL && cor(N->dir) == RED && cor(N->dir->dir) == RED)
		N = rotacionaEsq(N);
	else {
		if(N->esq!=NULL && cor(N->esq) == RED && cor(N->dir) == RED && cor(N->dir->dir) == RED)
			trocaCor(N);
		}
		
	if (N->esq==NULL && cor(N->dir) == RED && cor(N->dir->esq) == RED){
		N = rotacionaDuplaEsq(N);
	}
	else{
		if(N->esq!=NULL && cor(N->dir) == RED && cor(N->dir->esq) == RED)
		trocaCor(N);
	}
				
	if(N->dir==NULL && cor(N->esq) == RED && cor(N->esq->esq) == RED)
		N = rotacionaDir(N);
		else{
			if(N->dir!=NULL && cor(N->esq) == RED && cor(N->esq->esq) == RED)
				trocaCor(N);
			}
		
	if(N->dir==NULL && cor(N->esq) == RED && cor(N->esq->dir) == RED){
		N = rotacionaDuplaDir(N);
	}
	else{
			if(N->dir!=NULL && cor(N->esq) == RED && cor(N->esq->dir) == RED)
			trocaCor(N);
	}
		
	return N;
}

//programa principal
//int x = removeArvRB(raiz, valor);

//arquivo ArvRB.h
//int removeArvRB(ArvRB *raiz, int valor);

//arquivo removeArvRB.c
int removeArvRB(ArvRB *raiz, int valor){
	if(Buscar(*raiz,valor)){
		Noh* N = *raiz;
		//função responsavel pela busca do nó a ser removido
		*raiz = removeNoh(N, valor);
		return 1;
	}else
		return 0;
}

struct Noh* removeNoh(struct Noh* N, int valor)
{
	if (valor == (N)->info && cor(N) == RED){
	
		free(N);
	}
	if(valor > (N)->info && cor(N) == BLACK){
		if(cor((N)->dir) == BLACK && cor((N)->dir->dir) == RED){
			free(N);
			//(N)->esq = removeNoh((N)->esq, valor);
			(N)->dir->dir->cor = !cor((N)->dir->dir);
			(N) = rotacionaDir((N));
		}
		else{
			if(cor((N)->dir) == BLACK && cor((N)->dir->dir) == BLACK){
				//(N)->esq = removeNoh((N)->esq, valor);
				free(N);
				(N)->cor = !(N)->cor;
				(N)->dir->cor = !cor((N)->dir);
			}
		}
	}
	if (valor < (N)->info && cor((N)) == BLACK){
		if(cor((N)->esq) == BLACK && cor((N)->esq->esq) == RED){
			//(N)->dir = removeNoh((N)->dir, valor);
			free(N);
			(N)->esq->esq->cor = !cor((N)->esq->esq);
			(N) = rotacionaEsq((N));
		}
		else
		{
			
			if(cor((N)->esq) == BLACK && cor((N)->esq->esq) == BLACK){
				//(N)->dir = removeNoh((N)->dir, valor);
				free(N);
				(N)->cor = !(N)->cor;
				(N)->esq->cor = !cor((N)->esq);
			}
		}
	}
}



Noh* Buscar(Noh* N, int info)
{
	if (N==NULL){
		printf(" elemento nao encontrado\n");
		return NULL;
	}
		
	if (info==N->info){
		printf("O elemento procurado encontra-se na arvore");
		return N;
	}
	if (info < N->info)
		return Buscar(N->esq, info);
	else
		return Buscar( N->dir, info);
}


 void escreve(Noh* x)
{
 	if(x!=NULL){
		escreve(x->esq);
		printf("valor: %d cor:%d\n",x->info,x->cor);
		escreve(x->dir);
	}
}


void MENU(){
		printf("  MENU  ");
		printf("\nEscolha a opcao desejada");
		printf("\n1- inserir elemento manualmente");
		printf("\n2- remover elemento");
		printf("\n3- buscar elemento");
		printf("\n4- mostrar exemplo de uma arvore rubro-negra");
		printf("\n5- sair\n\n");
}

int main (){
	
	int opc = 0, num, i;
	Noh* arvore=NULL;
	
	while(opc!=5){
		
		MENU();
		scanf("%d", &opc);
		system("cls");	
				
		if(opc==1){
				for(i=0; i<7; i++){
				
			printf("informe o %do elemento a ser inserido\n", i+1);
			scanf("%d", &num);
			insere_ArvRB(&arvore, num);
			escreve (arvore);
			getch();
			system("cls");
			}
		}
		if(opc==2){
			printf("informe o elemento a ser removido\n");
			scanf("%d", &num);
			removeArvRB(&arvore, num);
			escreve (arvore);
			getch();
			system("cls");
		}
		
		if(opc==3){
			
			printf("informe o elemento a ser encontrado\n");
			scanf("%d", &num);
			Buscar(arvore, num);
			getch();
			system("cls");
		}
		if(opc==4){
			//Noh* arvore=NULL;
			insere_ArvRB(&arvore, 40);
			insere_ArvRB(&arvore, 8);
			insere_ArvRB(&arvore, 45);
			//system("pause");
			//escreve (arvore);
			insere_ArvRB(&arvore, 7);
			insere_ArvRB(&arvore, 9);
			insere_ArvRB(&arvore, 44);
			insere_ArvRB(&arvore, 46);
			system("pause");
			escreve (arvore);	
			getch();
			system("cls");
			
		}
			
	}	
}

