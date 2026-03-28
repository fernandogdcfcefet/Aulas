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
	if(t==NULL){
		return 1;
	}
	if((t->sae!=NULL && t->sad==NULL || t->sae==NULL && t->sad!=NULL)){
		return 0;
	}

	else{
		if((Binaria(t->sae)==0 || Binaria(t->sad)==0)){
			return 0;
		}
		else{
			return 1;
		}
	}
}






int main()
{
    Tree* t = createTree();
    insertTree(&t, 12);
    insertTree(&t,15);
    insertTree(&t,10);
    Binaria(t);
   // Espelhar(&t);
    //Busca(t,12);
    return 0;
}
