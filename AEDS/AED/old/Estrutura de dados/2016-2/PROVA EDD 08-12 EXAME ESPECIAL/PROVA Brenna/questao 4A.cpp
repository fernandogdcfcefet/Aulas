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





void ImprimeDecrescente(Tree *t){
	if(!treeIsEmpty(t))
  {
    ImprimeDecrescente(t->sad);
    printf("%d ", t->num);
    ImprimeDecrescente(t->sae);
  }


}


int main()
{
  Tree *t;
  createTree;

  insertTree(&t,7);
  insertTree(&t,4);
  insertTree(&t,5);
  insertTree(&t,8);
  insertTree(&t,6);

  caminhamentoCentral(t);
  printf("\n");
  ImprimeDecrescente(t);

  return 0;

}
