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

void caminhamentoCentral(Tree* t)
{
  if(!treeIsEmpty(t))
  {
    caminhamentoCentral(t->sae);
    printf("%d ", t->num);
    caminhamentoCentral(t->sad);
  }
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
      insertTree(&(*t)->sad, num);
    }
  }
}

int isInTree(Tree* t, int num) {

  if(treeIsEmpty(t)) {
    return 0;
  }

  return t->num==num || isInTree(t->sae, num) || isInTree(t->sad, num);
}


void Espelhar( Tree* t){
	Tree* aux;
	
	if(!treeIsEmpty(t)){
		aux=t->sad;
		t->sad=t->sae;
		t->sae=aux;
		Espelhar(t->sad);
		Espelhar(t->sae);
	}
}


void Imprime(Tree *t){
	if(!treeIsEmpty(t)){
		Imprime(t->sad);
		printf("%d",t->num);
		Imprime(t->sae);
	}
}

Tree* freeTree(Tree** t)
{

  if(!treeIsEmpty(*t))
  {
    freeTree(&(*t)->sae);

    freeTree(&(*t)->sad);

    free(*t);

  }

  return NULL;
}

int main()
{
  system("pause");
  return 0;

}
