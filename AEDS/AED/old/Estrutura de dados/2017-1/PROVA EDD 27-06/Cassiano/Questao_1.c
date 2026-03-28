#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
  int num;
  struct tree* sad;
  struct tree* sae;
} Tree;

Tree* createTree()
{
    return NULL;
}

int treeIsEmpty(Tree* t)
{
    return t == NULL;
}

void insertTree(Tree** t, int num)
{
  if(*t == NULL)
  {
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->sae = NULL;
    (*t)->sad = NULL;
    (*t)->num = num;
  } else {
    if(num < (*t)->num)
    {
      insertTree(&(*t)->sae, num);
    }
    if(num > (*t)->num)
    {
      insertTree(&(*t)->sad, num);/////////////////////////////////
    }
  }
}

int verificaArvore(Tree *t){      //////QUESTÃO 1(A)
	
	if((treeIsEmpty(t))){
		printf("\nARVORE DE BUSCA VAZIA\n");
		return 0;
	}
	
	else if((t->sad)>(t->sae)){
		printf("\nEH ARVORE DE BUSCA\n");
		return 1;
	}
	
}

void espelhar(Tree* t){//////////// Questão 1(B)
	int aux;
	aux=t->sad->num;
	t->sad->num=t->sae->num;
	t->sae->num=aux;
	
}

int estritamenteBinaria(Tree* t){/////////////////////// Questao 1(C)
	if(!(t)){
		return 0; //Retorna zero para FALSO
	}
	
	else if((!(treeIsEmpty(t->sae))) && (!(treeIsEmpty(t->sad)))){
		return 1; //Retorna 1 para VERDADEIRO
		
	}
}

void caminhamentoCentral(Tree *t){
	if(t->sae!=NULL){
		caminhamentoCentral(t->sae);
	}
	
	if(t->num!=' '){
		printf("%d\n", t->num);
	}
	if(t->sad!=NULL){
		caminhamentoCentral(t->sad);
	}
	
}

int main()
{
	Tree *t;
	treeIsEmpty(t);
	int num=5;
	insertTree(&t, 5);
	insertTree(&t, 2);
	insertTree(&t, 7);
	
	caminhamentoCentral(t);
	printf("\n\n");
	
	espelhar(t);
	caminhamentoCentral(t);
	
	estritamenteBinaria(t);
	
	system("pause");
    return 0;
}
