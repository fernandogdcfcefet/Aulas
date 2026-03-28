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

//------------------------------------------------------------------------------//

void  estritamenteBinaria(Tree** t){
	if((*t->sad == NULL && *t->sae == NULL))
		return;
	else if(*t->sad!=NULL && *t->sae!= NULL){
		estritamenteBinaria(&(*t)->sad);
		estritamenteBinaria(&(*t)->sae);
	}
	else{
		printf("Arvore apresenta elemento com 1 filho");
	}
}

int arvoreBusca(Tree** t, int *valor){
	if((*t->sad == NULL && *t->sae == NULL))
		return 0;
	else{
		if(*t->sad!=NULL){
			valor--;
			arvoreBusca(&(*t)->sad);
		}
		if(*t->sae!=NULL){
			valor++;
			arvoreBusca(&(*t)->sae);	
		}
	}
}


int main()
{
    Tree* t = createTree();
    insertTree(&t, 12);
    return 0;
}
