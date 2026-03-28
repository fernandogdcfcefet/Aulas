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
void imprime_decresente(Tree* t){
	if(!treeIsEmpty(t))
  {
    imprime_decresente(t->sad);
    printf("%d ", t->num);
    imprime_decresente(t->sae);
  }
}
void espelho(Tree* t,Tree** t2){
  createTree();
  if(*t2 == NULL)
  {
  	(*t2)->num = t->num;
  } else {
    if(t->num < (*t2)->num)
    {
      insertTree(&(*t2)->sad, t->num);
    }
    if(t->num > (*t2)->num)
    {
      insertTree(&(*t2)->sae, t->num);
    }
  }
	
	
}
int main()
{
  system("pause");
  return 0;

}
