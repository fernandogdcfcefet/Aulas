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


int Binaria(Tree *t){
	if(treeIsEmpty(t)){
		return 0;
	}
	if(t->sad!=NULL){
		return Binaria(t->sad);
	}
	if(t->sae!=NULL){
		return Binaria(t->sae);
	}
}
int main()
{
    Tree* t = createTree();
    insertTree(&t, 12);
    return 0;
}
