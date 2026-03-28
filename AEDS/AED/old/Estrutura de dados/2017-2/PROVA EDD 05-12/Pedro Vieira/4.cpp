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
      insertTree(&(*t)->sad, num);
    }
  }
}

void verifica(Tree** t)
{
	if((*t)->sad == NULL && (*t)->sae == NULL)
		printf("Arvore estritamente binaria");
	else
		printf("Arvore nao estritamente binaria");
}

int main()
{
    Tree* t = createTree();
    insertTree(&t, 12);
    verifica(&t);
    return 0;
}
